#include "Warehouse.h"

Warehouse::Warehouse(): nextOrderID(1){}

void Warehouse::addProductStock(shared_ptr<Product> product, const double quantity)
{
	if (!product || quantity <= 0) return;
	
	for (size_t i(0); i < inventory.size(); i++) {
		if (inventory[i].product->getSKU() == product->getSKU()) {
			inventory[i].quantity += quantity;
			return;
		}
	}
	WarehouseItem newItem;
	newItem.product = product;
	newItem.quantity = quantity;
	inventory.push_back(newItem);
}

void Warehouse::registerClient(shared_ptr<Client> client)
{
	if (client) {
		clients.push_back(client);
	}
}

bool Warehouse::processOrder(const int clientID, vector<pair<string, double>>& cart, const Date date)
{
	shared_ptr<Client> currentClient = nullptr;
	for (size_t i(0); i < clients.size(); i++) {
		if (clients[i]->getID() == clientID) {
			currentClient = clients[i];
			break;
		}
	}
	if (!currentClient) return false;
	vector<OrderItem> orderItems;
	double totalCost = 0.0;

	for (size_t i(0); i < cart.size(); i++) {
		string requestedSKU = cart[i].first;
		double requestedQty = cart[i].second;
		for (size_t j(0); j < inventory.size(); j++) {
			if (inventory[j].product->getSKU() == requestedSKU) {
				if (inventory[j].quantity >= requestedQty) {
					inventory[j].quantity -= requestedQty;
					OrderItem item;
					item.product = inventory[j].product;
					item.quantity = requestedQty;
					orderItems.push_back(item);
					totalCost += inventory[j].product->getBasePrice() * requestedQty;
				}
				break;
			}
		}
	}
	if (orderItems.empty()) return false;
	currentClient->updateDiscountStatus();
	totalCost -= totalCost * currentClient->getDiscountRate();
	currentClient->addSpentMoney(totalCost);
	currentClient->linkOrder(nextOrderID);
	Order newOrder(nextOrderID, clientID, orderItems, date, totalCost);
	salesHistory.push_back(newOrder);
	nextOrderID++;
	return true;
}

const vector<WarehouseItem>& Warehouse::getCurrentInventory() const
{
	return inventory;
}

vector<Order> Warehouse::getSalesHistory() const
{
	return salesHistory;
}

vector<shared_ptr<Client>> Warehouse::getClients() const
{
	return clients;
}
