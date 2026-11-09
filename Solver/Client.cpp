#include "Client.h"
Client::Client() : id(0), name(""), totalSpent(0.0), discountRate(0.0), clientType("Regular"), address("") {}
Client::Client(const int ID, const string n, const string type, const string addr)
	: id(ID), name(n), totalSpent(0.0), discountRate(0.0), clientType(type), address(addr) {
}int Client::getID() const {
	return id;
}

string Client::getName() const {
	return name;
}

string Client::getClientType() const
{
	return clientType;
}

string Client::getAddress() const
{
	return address;
}

void Client::addSpentMoney(double amount) {
	totalSpent += amount;
}

double Client::getTotalSpent() const {
	return totalSpent;
}

void Client::linkOrder(int orderID) {
	orderIDs.push_back(orderID);
}
string Client ::toString() const {
	if (address.empty()) {
		return clientType + " (Discount: " + to_string(discountRate * 100) + "%)";
	}
	return clientType + " (Address: " + address + ")";
}
double Client::getDiscountRate() const {
	return discountRate;
}
void Client::updateDiscountStatus() {
	if (totalSpent > 500000.0) {
		discountRate = 0.15;
	}
	else if (totalSpent > 100000.0) {
		discountRate = 0.05;
	}
}

vector<int> Client::getOrderIDs() const
{
	return orderIDs;
}

bool Client::operator==(const Client& other) const
{
	return (id == other.id && name == other.name && clientType == other.clientType && address == other.address);
}

bool Client::operator!=(const Client& other) const
{
	return !(*this == other);
}
