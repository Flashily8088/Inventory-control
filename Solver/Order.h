 #pragma once
#include <vector>
#include<memory>
#include <ostream>
#include"Product.h"
#include"Date.h"
using namespace std;
/**
* @brief структура продукта в заказе
*/
struct OrderItem {
	/**
	* @brief указатель на заказываемый продукт
	*/
	Product product;
	/**
	* @brief количество заказываемого продукта
	*/
	double quantity;
	/**
	* @brief оператор ==
	* @param other - предмет заказа, с которым нужно сравнить
	* @return true, если this == other
	*/
	bool operator==(const OrderItem& other) const;
	/**
	* @brief оператор !=
	* @param other - предмет заказа, с которым нужно сравнить
	* @return true, если this != other
	*/
	bool operator!= (const OrderItem & other) const;
};
/**
* @brief класс "Заказ"
*/
class Order
{
private:
	/**
	* @brief индивидуальный номер заказа
	*/
	int orderID;
	/**
	* @brief индивидуальный номер клиента
	*/
	int clientID;
	/**
	* @brief список продуктов в заказе
	*/
	vector<OrderItem> items;
	/**
	* @brief дата заказа
	*/
	Date orderDate;
	/**
	* @brief итоговая оплата заказа
	*/
	double finalTotal;
public:
	/**
	* @brief конструктор заказа
	* @param id - индивидуальный номер заказа
	* @param cid - индивидуальный номер клиента
	* @param orderItems - список продуктов в заказе
	* @param data - дата
	* @param total - итоговая оплата
	*/
	Order(const int id, const int cid, vector<OrderItem> orderItems, const Date date, const double total);
	/**
	* @brief функция получения номера заказа
	* @return номер заказа
	*/
	int getOrderID() const;
	/**
	* @brief функция получения номера клиента
	* @return номер клиента
	*/
	int getClientID() const;
	/**
	* @brief функция получения списка продуктов в заказе
	* @return список продуктов в заказе
	*/
	const vector<OrderItem>& getItems() const;
	/**
	* @brief функция получения даты заказа
	* @return дата заказа
	*/
	Date getOrderDate() const;
	/**
	* @brief функция получения конечной суммы заказа
	* @return кончная сумма заказа
	*/
	double getFinalTotal() const;
	/**
	* @brief функция преобразования информации о заказе в типе string
	* @return информация о заказе
	*/
	string ToString();
	/**
	* @brief оператор ==
	* @param other - заказ, с которым нужно сравнить
	* @return true, если this == other
	*/
	bool operator==(const Order& other) const;
	/**
	* @brief оператор !=
	* @param other - заказ, с которым нужно сравнить
	* @return true, если this != other
	*/
	bool operator!=(const Order& other) const;
};

