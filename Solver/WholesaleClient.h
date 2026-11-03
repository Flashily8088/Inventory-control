#pragma once
#include"Client.h"
#include <string>
#include <ostream>
using namespace std;

/**
* @brief класс "Оптовый покупатель"
*/
class WholesaleClient : public Client
{
private:
	/**
	* @brief скидка
	*/
	double discountRate;
public:
	/**
	* @brief конструктор по умолчанию и с параметрами
	* @param id - индивидуальный номер клиента
	* @param n - имя покупателя
	* @param initialDiscount - изначальная скидка
	*/
	WholesaleClient(const int id, const string n, const double initialDiscount = 0);
	/**
	* @brief функция получения скидки
	* @return скиндка
	*/
	double getDiscountRate() const override;
	/**
	* @brief функция обновлнения информации о скидке
	*/
	void updateDiscountStatus() override;
	/**
	* @brief функция преобразования информации о магазине в тип string
	* @return информаци о магазине
	*/
	string getClientTypeString() const override;
};

