#pragma once
#include "Product.h"
using namespace std;
/**
* @brief класс "Оптовый товар"
*/
class BulkProduct : public Product
{
private:
	/**
	* @brief единица измерения товара
	*/
	string unitOfMeasure;
public:
	/**
	* @brief конструктор по умолчанию
	*/
	BulkProduct();
	/**
	* @brief конструктор
	* @param sku - уникальный код товара
	* @param name - название товара
	* @param price - цена товара
	* @param unit - единица измерения
	*/
	BulkProduct(const string sku, const string name, const double price,  const string unit);
	/**
	* @brief функция для преобразовании информации о товаре в тип string
	* @return информация о товаре string
	*/
	string getInfoString() const override;
	/**
	* @brief функция получения единицы измерения товара
	* @return единица измерения товара
	*/
	string getUnit() const;
};

