#pragma once
#include "Client.h"
#include <string>
using namespace std;
/**
* @brief класс "Роздничный магазин"
*/
class RetailStore : public Client
{
private:
	/**
	* @brief адрес доставки
	*/
	string deliveryAddress;
public:
	/**
	* @brief конструктор
	* @param id - индивидуальный номер клиента
	* @param name - наименование магазина
	* @param address - адрес доставки
	*/
	RetailStore(const int id, const string name, const string address);
	/**
	* @brief функция преведения информации о магазине к типу string
	* @return информация о магазине
	*/
	string getClientTypeString() const override;
	/**
	* @brief функция  получения адреса магазина
	* @return адрес магазина
	*/
	string getAddress() const;
};

