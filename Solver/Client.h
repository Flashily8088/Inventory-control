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
private:
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
	/**
	* @brief скидка
	*/
	double discountRate;
	/**
	* @brief тип клиента
	*/
	string clientType;
	/**
	* @brief адресс
	*/
	string address;
public:
	/**
	* @brief конструктор по умолчанию
	*/
	Client();
	/**
	* @brief конструктор
	* @param ID - индивидуальный номер клиента
	* @param n - название корпоративного аккаунта
	* @param type - тип клиента
	* @param addr - адресс
	*/
	Client(const int ID, const string n, const string type, const string addr);
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
	* @brief функция получения типа клиента
	* @return тип клиента
	*/
	string getClientType() const;
	/**
	* @brief функция получения адресса
	* @return адресс
	*/
	string getAddress() const;
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
	* @brief функция преобразования информации о клиенте в string
	* @return информация о клиенте
	*/
	string toString() const;
	/**
	* @brief функция получения размера скидки
	* @return размер скидки
	*/
	double getDiscountRate() const;
	/**
	* @brief функция обновления статуса скидки клиента
	*/
	void updateDiscountStatus();
	/**
	* @brief функция получения индивидуального номера заказа
	* @return индивидуальный номер заказа
	*/
	vector<int> getOrderIDs() const;
	/**
	* @brief оператор ==
	* @return true,  если клиенты равны
	*/
	bool operator ==(const Client& other) const;
	/**
	* @brief оператор ==
	* @return true,  если клиенты неравны
	*/
	bool operator !=(const Client& other) const;
};

