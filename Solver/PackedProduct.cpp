#include "PackedProduct.h"

PackedProduct::PackedProduct() : Product(), packagingType(""), volumePerUnit(0){};

PackedProduct::PackedProduct(const string SKU, const string name, const double price, const string type, const int box) : Product(SKU, name, price), packagingType(type), volumePerUnit(box) {};

string PackedProduct::getInfoString() const
{
	return "[Item] " + getName() + " (SKU: " + getSKU() + ") - Type of packaging: " + packagingType
		+ " (" + std::to_string(volumePerUnit) + " kg/l), Price: " + std::to_string(getBasePrice()) + " rub/item.";
}

string PackedProduct::getPackagingType() const
{
	return packagingType;
}

int PackedProduct::getVolumePerUnit() const
{
	return volumePerUnit;
}
