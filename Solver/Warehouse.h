#pragma once
#include <vector>
#include <memory>
#include "Product.h"
#include "Client.h"
#include "Order.h"
using namespace std;
/**
* @brief структура хранимого продукта на  складе
*/
struct WarehouseItem {
	/**
	* @brief умный указатель на продукт
	*/
	shared_ptr<Product> product;
	/**
	* @brief количество продукта на складе
	*/
	double quantity;
};
/**
* @brief класс "Склад"
*/
class Warehouse
{
private:
	/**
	* @brief инвентарь склада - список хранимых на нём товаров
	*/
	vector<WarehouseItem> inventory;
	/**
	* @brief список указателей на клиентов склада
	*/
	vector<shared_ptr<Client>> clients;
	/**
	* @brief история продаж
	*/
	vector<Order> salesHistory;
	/**
	* @brief индивидуальный номер следующего заказа
	*/
	int nextOrderID;
public:
	/**
	* @brief конструктор по умолчанию
	*/
	Warehouse();
	/**
	* @brief функия добавления продукта на склад
	* @param product - добавляемый продукт
	* @param quantity - количество продукта
	*/
	void addProductStock(shared_ptr<Product> product, const double quantity);
	/**
	* @brief функия регистрации нового клиента
	* @param client - клиент
	*/
	void registerClient(shared_ptr<Client> client);
	/**
	* @brief функия регистрации (проведения) заказа
	* @param clientID - индивидуальный номер клиента
	* @param cart - карта заказа в виде вектораБ в котором храняться пары, состоящие из наименования товара и количества
	* @param date - дата заказа
	*/
	bool processOrder(const int clientID, vector<pair<string, double>>& cart, const Date date);
	/**
	* @brief функия получения списка хранимых на складе товаров
	* @return список хранимых на складе вещей
	*/
	const vector<WarehouseItem>& getCurrentInventory() const;
	/**
	* @brief функия получения истории заказов
	* @return история продаж
	*/
	vector<Order> getSalesHistory() const;
	/**
	* @brief функия получения списка клиентов
	* @return список клиентов
	*/
	vector<shared_ptr<Client>> getClients() const;
};

