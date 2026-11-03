#include "WholesaleClient.h"

WholesaleClient::WholesaleClient(const int id, const string n, const double initialDiscount) : Client(id, n), discountRate(initialDiscount) {}
double WholesaleClient::getDiscountRate() const
{
	return discountRate;
}
void WholesaleClient::updateDiscountStatus()
{
	if (getTotalSpent() > 500000.0) {
		discountRate = 0.15;
	}
	else if (getTotalSpent() > 100000.0) {
		discountRate = 0.05;
	}
}
string WholesaleClient::getClientTypeString() const
{
	return "Wholesale client (Discount: " + to_string(discountRate);
}