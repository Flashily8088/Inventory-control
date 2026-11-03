#include "Product.h"
#include "Client.h"

Product::Product() : SKU(""), name(""), basePrice(0.0) {}
Product::Product(const string sku, const string n, const double price) : SKU(sku), name(n), basePrice(price){}
string Product::getSKU() const
{
	return SKU;
}

string Product::getName() const
{
	return name;
}

double Product::getBasePrice()  const
{
	return basePrice;
}