#include "Client.h"
Client::Client() : id(0), name(""), totalSpent(0.0) {};
Client::Client(const int ID, const string n) : id(ID), name(n), totalSpent(0.0){};

int Client::getID() const {
	return id;
}

string Client::getName() const {
	return name;
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
