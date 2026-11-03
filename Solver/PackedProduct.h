#pragma once
#include"Product.h"
/**
* @brief класс "Расфасованный товар"
*/
class PackedProduct : public Product
{
private:
	/**
	* @brief тип упаковки
	*/
	string packagingType;
	/**
	* @brief объём на единицу
	*/
	int volumePerUnit;
public:
	/**
	* @brief конструктор по умолчанию
	*/
	PackedProduct();
	/**
	* @brief конструктор
	* @param SKU - индивидуальный номер товара
	* @param name - наименование товара
	* @param price - цена товара
	* @param type - вид упаковки
	* @param box - объём на единицу
	*/
	PackedProduct(const string SKU, const string name, const double price, const string type, const int box);
	/**
	* @brief функция преобразования информации о фасованном продукте в тип string
	* @return информация о фасованном товаре
	*/
	string getInfoString() const override;
	/**
	* @brief функция получения типа упаковки
	* @return тип упаковки
	*/
	string getPackagingType() const;
	/**
	* @brief функция получения объёма на единицу
	* @return объём на единицу
	*/
	int getVolumePerUnit() const;
};

