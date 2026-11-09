#include "Order.h"
Order::Order(const int id, const int cid, vector<OrderItem> orderItems, const Date date, const double total) :
	orderID(id), clientID(cid), items(orderItems), orderDate(date), finalTotal(total) { };

int Order::getOrderID() const
{
	return orderID;
}

int Order::getClientID() const
{
	return clientID;
}

const vector<OrderItem>& Order::getItems() const
{
	return items;
}

Date Order::getOrderDate() const
{
	return orderDate;
}

double Order::getFinalTotal() const
{
	return finalTotal;
}

string Order::ToString()
{
	return " * Order #" + to_string(getOrderID())
		+ " | Client ID: " + to_string(getClientID())
		+ " | Date: " + (getOrderDate().ToString())
		+ " | Total: " + to_string(getFinalTotal()) + " rub.";
}

bool Order::operator==(const Order& other) const
{
	if (orderID != other.orderID || clientID != other.clientID || orderDate != other.orderDate || finalTotal != other.finalTotal || items.size() == other.items.size()) {
		return false;
	}
	for (size_t i(0); i < items.size(); i++) {
		if (items[i] != other.items[i]) {
			return false;
		}
	}
	return true;
}

bool Order::operator!=(const Order& other) const
{
	return false;
}

bool OrderItem::operator==(const OrderItem& other) const
{
	return (product == other.product && quantity == other.quantity);
}

bool OrderItem::operator!=(const OrderItem& other) const
{
	return !(*this == other);
}
