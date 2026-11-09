#include "Warehouse.h"

Warehouse::Warehouse(): nextOrderID(1){}

void Warehouse::addProductStock(Product product, const double quantity)
{
	if (quantity <= 0) return;
	
	for (size_t i(0); i < inventory.size(); i++) {
		if (inventory[i].product.getSKU() == product.getSKU()) {
			inventory[i].quantity += quantity;
			return;
		}
	}
	WarehouseItem newItem;
	newItem.product = product;
	newItem.quantity = quantity;
	inventory.push_back(newItem);
}

void Warehouse::registerClient(Client client)
{
	for (size_t i(0); i < clients.size(); i++) {
		if (client == clients[i]) {
			cout << "The client already exists." << endl;
			return;
		}
	}
	clients.push_back(client);
}
bool Warehouse::processOrder(const int clientID, vector<pair<string, double>>& cart, const Date date)
{
	int clientIndex = -1;
	for (size_t i(0); i < clients.size(); i++) {
		if (clientID == clients[0].getID()) {
			clientIndex = static_cast<int>(i);
			break;
		}
	}
	if (clientIndex == -1) {
		cout << "Client's index doesn't exist" << endl;
		return false;
	}
	for (size_t i(0); i < cart.size(); i++) {
		string requestedSKU = cart[i].first;
		double requestedQty = cart[i].second;
		bool foundAndEnough = false;
		for (size_t j(0); j < inventory.size(); j++) {
			if (requestedSKU == inventory[j].product.getSKU()) {
				if (inventory[j].quantity >= requestedQty) {
					foundAndEnough = true;
				}
				break;
			}
		}
		if (!foundAndEnough) {
			cout << "Product isn't found or isn't enough" << endl;
			return false;
		}
	}
	vector <OrderItem> orderItem;
	double totalCost = 0.0;
	for (size_t i(0); i < cart.size(); i++) {
		string reqeustedSKU = cart[i].first;
		double requestedQty = cart[i].second;
		for (size_t j(0); j < inventory.size(); j++) {
			if (reqeustedSKU == inventory[j].product.getSKU()) {
				inventory[j].quantity -= requestedQty;
				OrderItem item;
				item.product = inventory[j].product;
				item.quantity = requestedQty;
				orderItem.push_back(item);
				totalCost = inventory[j].product.getBasePrice() * requestedQty;
				break;
			}
		}
	}
	double discount = clients[clientIndex].getDiscountRate();
	totalCost -= totalCost * discount;
	clients[clientIndex].addSpentMoney(totalCost);
	clients[clientIndex].updateDiscountStatus();
	clients[clientIndex].linkOrder(nextOrderID);
	Order newOrder(nextOrderID, clientID, orderItem, date, totalCost);
	salesHistory.push_back(newOrder);
	nextOrderID++;
	return true;
}

const vector<WarehouseItem> Warehouse::getCurrentInventory() const
{
	return inventory;
}

vector<Order> Warehouse::getSalesHistory() const
{
	return salesHistory;
}

vector<Client> Warehouse::getClients() const
{
	return clients;
}

int Warehouse::getNextOrderID() const
{
	return nextOrderID;
}

bool WarehouseItem::operator==(const WarehouseItem& other) const
{
	return (product == other.product && quantity == other.quantity);
}

bool WarehouseItem::operator!=(const WarehouseItem& other) const
{
	return !(*this == other);
}
