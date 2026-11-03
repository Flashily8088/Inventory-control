#pragma once
#include <string>
#include <vector>
#include <ostream>
using namespace std;
/**
* @brief класс "Клиент"
*/
class Client
{
protected:
	/**
	* @brief индивидуальный номер клиента
	*/
	int id;
	/**
	* @brief полние имя или название корпоративного аккаунта
	*/
	string name;
	/**
	* @brief потраченные деньги клиента
	*/
	double totalSpent;
	/**
	* @brief индивидуальные номера заказов клиента
	*/
	vector <int> orderIDs;
public:
	/**
	* @brief конструктор по умолчанию
	*/
	Client();
	/**
	* @brief конструктор
	* @param ID - индивидуальный номер клиента
	* @param n - название корпоративного аккаунта
	*/
	Client(const int ID, const string n);
	/**
	* @brief деструктор по умолчанию
	*/
	virtual ~Client() = default;
	/**
	* @brief функция получения ID
	* @return ID
	*/
	int getID() const;
	/**
	* @brief функция получения названия корпоративного аккаунта
	* @return название корпоративного аккаунта
	*/
	string getName() const;
	/**
	* @brief функция добавления потраченных денег
	* @param amount - количество потраченных денег
	*/
	void addSpentMoney(double amount);
	/**
	* @brief функция получения потраченных денег
	* @return количество потраченных денег
	*/
	double getTotalSpent() const;
	/**
	* @brief функция добавления номера заказа в список
	*/
	void linkOrder(int orderID);
	/**
	* @brief виртуальная функция преобразования информации о клиенте в string
	* @return информация о клиенте
	*/
	virtual string getClientTypeString() const = 0;
	/**
	* @brief виртуальная функция получения размера скидки
	* @return размер скидки
	*/
	virtual double getDiscountRate() const { return 0.0; }
	/**
	* @brief виртуальная функция обновления статуса скидки клиента
	*/
	virtual void updateDiscountStatus() {};
};

