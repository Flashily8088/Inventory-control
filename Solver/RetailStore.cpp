#include "RetailStore.h"

RetailStore::RetailStore(const int id, const string name, const string address) : Client(id, name), deliveryAddress(address){}
string RetailStore::getClientTypeString() const
{
	return "Retail store (Address: " + deliveryAddress;
}

string RetailStore::getAddress() const
{
	return deliveryAddress;
}

