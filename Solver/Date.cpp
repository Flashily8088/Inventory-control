#include "Date.h"

Date::Date(const int d, const int m, const int y) : day(d), month(m), year(y) {};

string Date::ToString() const
{
	return to_string(day) + ". " + to_string(month) + ". " + to_string(year);
}

bool Date::operator<=(const Date& other) const
{
	if (year != other.year) return year < other.year;
	if (month != other.month) return month < other.month;
	return day <= other.day;
}

bool Date::operator>=(const Date& other) const
{
	if (year != other.year) return year > other.year;
	if (month != other.month) return month > other.month;
	return day >= other.day;
}

void Date::input()
{
	int d, m, y;
	cout << "Day: ";
	cin >> d;
	cout << "Month: ";
	cin >> m;
	cout << "Year: ";
	cin >> y;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}


