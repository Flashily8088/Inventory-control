#include "Product.h"
#include "Client.h"

Product::Product() : SKU(""), name(""), basePrice(0.0) {}
Product::Product(const string sku, const string n, const double price, const string u) : SKU(sku), name(n), unit(u) {
	if (price <= 0.0) {
		throw invalid_argument("Invalid product price\n");
	}
	basePrice = price;
};
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

string Product::getUnit() const
{
	return unit;
}
string Product::getInfoString() const {
	return "[Item] " + name + " (SKU: " + SKU + " - " + to_string(basePrice) + " rub/" + unit;
}

bool Product::operator==(const Product& other) const
{
	return (SKU == other.SKU && name == other.name && basePrice == other.basePrice && unit == other.unit);
}

bool Product::operator!=(const Product& other) const
{
	return !(*this == other);
}
