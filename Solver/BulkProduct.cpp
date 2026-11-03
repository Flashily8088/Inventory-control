#include "BulkProduct.h"

BulkProduct::BulkProduct() : Product(), unitOfMeasure("") {}
BulkProduct::BulkProduct(const string sku, const string name, const double price, const string unit) : Product(sku, name, price), unitOfMeasure(unit){}
string BulkProduct::getInfoString() const
{
	return "[Item] " + getName() + " (SKU: " + getSKU() + ") - " + std::to_string(getBasePrice()) + " rub/" + unitOfMeasure;
}
string BulkProduct::getUnit() const
{
	return unitOfMeasure;
}
;
