#pragma once
#include <string>
using namespace std;
/**
* @brief класс "Продукт"
*/
class Product
{
private:
	/**
	* @brief индивидуальный номер продукта
	*/	
	string SKU;
	/**
	* @brief название продукта
	*/
	string name;
	/**
	* @brief базовая цена продукта
	*/
	double basePrice;
public:
	/**
	* @brief конструктор по умолчанию
	*/
	Product();
	/**
	* @brief конструктор
	* @param sku - индивидуальный номер
	* @param n - наименование
	* @param price - цена
	*/
	Product(const string sku, const string n, const double price);
	/**
	* @brief деструктор по умолчанию
	*/
	virtual ~Product() = default;
	/**
	* @brief функция получения индивидуального номера
	* @return индивидуальный номер
	*/
	string getSKU() const;
	/**
	* @brief функция получения наименования продукта
	* @return наименование продукта
	*/
	string getName() const;
	/**
	* @brief функция получениия базовой цены продукта
	* @return базовая цена продукта
	*/
	double getBasePrice() const;
	/**
	* @brief функция преобразования информации о продукти в тип string
	* @return инормация о продукте
	*/
	virtual string getInfoString() const = 0;
};

