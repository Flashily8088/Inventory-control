#pragma once
#include <string>
#include<iostream>
using namespace std;
/**
* @brief структура "ƒата"
*/
struct Date
{
	/**
	* @brief день
	*/
	int day;
	/**
	* @brief мес¤ц
	*/
	int month;
	/**
	* @brief год
	*/
	int year;
	/**
	* @brief конструктор спараметрами и по умолчанию
	* @param d - день (по умолчанию 0)
	* @param m - мес¤ц (по умолчанию 0)
	* @param y - год (по умолчанию 0)
	*/
	Date(const int d = 0, const int m = 0, const int y = 0);
	/**
	* @brief функци¤ преобразовани¤ даты в тип string
	* @return string
	*/
	string ToString() const;
	/**
	* @brief оператор <=
	* @param other - дата с которой нужно сравнить
	* @return true если this <= other
	*/
	bool operator <=(const Date& other) const;
	/**
	* @brief оператор >=
	* @param other - дата с которой нужно сравнить
	* @return true если this >= other
	*/
	bool operator >=(const Date& other) const;
	/**
	* @brief функци¤ ввода даты
	*/
	void input();
	/**
	* @brief функци¤ получени¤ дн¤
	* @return день
	*/
	int getDay() const;
	/**
	* @brief функци¤ получени¤ мес¤ц
	* @return мес¤ц
	*/
	int getMonth() const;
	/**
	* @brief функци¤ получени¤ год
	* @return год
	*/
	int getYear() const;
};


