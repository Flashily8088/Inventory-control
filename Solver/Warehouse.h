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
	Product product;
	/**
	* @brief количество продукта на складе
	*/
	double quantity;
	/*
	* @brief оператор ==
	* @param other - переменная для сравнения с текущй
	* @return true, если обе переменные равны
	*/
	bool operator ==(const WarehouseItem& other) const;
	/*
	* @brief оператор !=
	* @param other - переменная для сравнения с текущй
	* @return true, если обе переменные неравны
	*/
	bool operator !=(const WarehouseItem& other) const;
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
	vector<Client> clients;
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
	void addProductStock(Product product, const double quantity);
	/**
	* @brief функия регистрации нового клиента
	* @param client - клиент
	*/
	void registerClient(Client client);
	/**
	* @brief функия регистрации (проведения) заказа
	* @param clientID - индивидуальный номер клиента
	* @param cart - карта заказа в виде вектора в котором храняться пары, состоящие из наименования товара и количества
	* @param date - дата заказа
	*/
	bool processOrder(const int clientID, vector<pair<string, double>>& cart, const Date date);
	/**
	* @brief функия получения списка хранимых на складе товаров
	* @return список хранимых на складе вещей
	*/
	const vector<WarehouseItem> getCurrentInventory() const;
	/**
	* @brief функия получения истории заказов
	* @return история продаж
	*/
	vector<Order> getSalesHistory() const;
	/**
	* @brief функия получения списка клиентов
	* @return список клиентов
	*/
	vector<Client> getClients() const;
	/**
	* @brief функия получения следующего номера заказа
	* @return номер следующего заказа
	*/
	int getNextOrderID() const;
};

