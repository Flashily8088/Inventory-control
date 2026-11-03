#include "Order.h"
Order::Order(int id, int cid, vector<OrderItem> orderItems, Date date, double total) : 
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
