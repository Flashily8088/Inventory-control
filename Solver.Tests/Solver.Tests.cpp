#include "CppUnitTest.h"
#include <iostream>
#include <string>
#include<vector>
#include<memory>
#include<iomanip>
#include "../Solver/Warehouse.h"
#include "../Solver/Date.h"

#include "../Solver/Product.h"
#include "../Solver/Client.h"
#include "../Solver/Order.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolverTests
{
	TEST_CLASS(SolverTests)
	{
	public:
		TEST_METHOD(Client_constructor) {
			//Act
			Client client;
			//Assert
			Assert::AreEqual(0, client.getID());
			Assert::AreEqual(static_cast<string>(""), client.getName());
			Assert::AreEqual(0.0, client.getTotalSpent());
			Assert::AreEqual(0.0, client.getDiscountRate());
			Assert::AreEqual(static_cast<string>("Regular"), client.getClientType());
			Assert::AreEqual(static_cast<string>(""), client.getAddress());
		}
		TEST_METHOD(Client_Constructor) {
			//Arrange
			int id = 1;
			string name = "AAA";
			string clientType = "Retail";
			string address = "Apple st.";
			//Act
			Client client(id, name, clientType, address);
			//Assert
			Assert::AreEqual(id, client.getID());
			Assert::AreEqual(name, client.getName());
			Assert::AreEqual(0.0, client.getTotalSpent());
			Assert::AreEqual(0.0, client.getDiscountRate());
			Assert::AreEqual(clientType, client.getClientType());
			Assert::AreEqual(address, client.getAddress());
		}
		TEST_METHOD(Client_getClientType) {
			//Arrange
			int id = 1;
			string name = "AAA";
			string clientType = "Retail";
			string address = "Apple st.";
			Client client(id, name, clientType, address);
			//Act
			string result =  client.getClientType();
			//Assert
			Assert::AreEqual(clientType, result);
		}
		TEST_METHOD(Client_getName) {
			//Arrange
			int id = 1;
			string name = "AAA";
			string clientType = "Retail";
			string address = "Apple st.";
			Client client(id, name, clientType, address);
			//Act
			string result = client.getName();
			//Assert
			Assert::AreEqual(name, result);
		}
		TEST_METHOD(Client_getAddress) {
			//Arrange
			int id = 1;
			string name = "AAA";
			string clientType = "Retail";
			string address = "Apple st.";
			Client client(id, name, clientType, address);
			//Act
			string result = client.getAddress();
			//Assert
			Assert::AreEqual(address, result);
		}
		TEST_METHOD(Client_addSpentMoney) {
			//Arrange
			int id = 1;
			string name = "AAA";
			string clientType = "Retail";
			string address = "Apple st.";
			Client client(id, name, clientType, address);
			double SpentMoney = 100.0;
			//Act
			client.addSpentMoney(SpentMoney);
			//Assert
			Assert::AreEqual(SpentMoney, client.getTotalSpent());
		}
		TEST_METHOD(Client_getTotalSpent) {
			//Arrange
			int id = 1;
			string name = "AAA";
			string clientType = "Retail";
			string address = "Apple st.";
			Client client(id, name, clientType, address);
			//Act
			double result = client.getTotalSpent();
			//Assert
			Assert::AreEqual(0.0, result);
		}
		TEST_METHOD(Client_linkOrder) {
			//Arrange
			int id = 1;
			string name = "AAA";
			string clientType = "Retail";
			string address = "Apple st.";
			Client client(id, name, clientType, address);
			int orderID = 1;
			//Act
			client.linkOrder(orderID);
			//Assert
			Assert::AreEqual(client.getOrderIDs()[0], orderID);
		}
		TEST_METHOD(Client_toString) {
			//Arrange
			int id = 1;
			string name = "AAA";
			string clientType = "Retail";
			string address = "Apple st.";
			Client client(id, name, clientType, address);
			string test = "Retail (Address: Apple st.)";
			//Act
			string result = client.toString();
			//Assert
			Assert::AreEqual(test, result);
		}
		TEST_METHOD(Client_getDiscountRate) {
			//Arrange
			int id = 1;
			string name = "AAA";
			string clientType = "Retail";
			string address = "Apple st.";
			Client client(id, name, clientType, address);
			//Act
			double result = client.getDiscountRate();
			//Assert
			Assert::AreEqual(0.0, result);
		}
		TEST_METHOD(Client_updateDiscountRate) {
			//Arrange
			int id = 1;
			string name = "AAA";
			string clientType = "Retail";
			string address = "Apple st.";
			Client client(id, name, clientType, address);
			client.addSpentMoney(100000.1);
			//Act
			client.updateDiscountStatus();
			//Assert
			Assert::AreEqual(0.05, client.getDiscountRate());
		}
		TEST_METHOD(Date_constructor)
		{
			//Arrange
			int day = 1;
			int month = 1;
			int year = 2026;
			//Act
			Date date(day, month, year);
			//Assert
			Assert::AreEqual(date.getDay(), day);
			Assert::AreEqual(date.getMonth(), month);
			Assert::AreEqual(date.getYear(), year);
		}
		TEST_METHOD(Date_ToString)
		{
			//Arrange
			int day = 1;
			int month = 1;
			int year = 2026;
			Date date(day, month, year);
			string test = "1. 1. 2026";
			//Act
			string result = date.ToString();
			//Assert
			Assert::AreEqual(result, test);
		}
		TEST_METHOD(Date_opertor_less_than_or_equal)
		{
			//Arrange
			int day1 = 1;
			int month1 = 1;
			int year1 = 2026;
			int day2 = 2;
			int month2 = 1;
			int year2 = 2026;
			Date date1(day1, month1, year1);
			Date date2(day2, month2, year2);
			//Act
			bool result = date1 <= date2;
			//Assert
			Assert::IsTrue(result);
		}
		TEST_METHOD(Date_opertor_more_than_or_equal)
		{
			//Arrange
			int day2 = 1;
			int month2 = 1;
			int year2 = 2026;
			int day1 = 2;
			int month1 = 1;
			int year1 = 2026;
			Date date1(day1, month1, year1);
			Date date2(day2, month2, year2);
			//Act
			bool result = date1 >= date2;
			//Assert
			Assert::IsTrue(result);
		}
		Date testableInputDate(istream& input) {
			int d, m, y;
			input >> d;
			input >> m;
			input >> y;
			return Date(d, m, y);
		}
		TEST_METHOD(Date_input)
		{
			//Arrange
			stringstream Input("1 1 2026");
			//Act
			Date result = testableInputDate(Input);
			//Assert
			Assert::AreEqual(string("1. 1. 2026"), result.ToString());
		}
		TEST_METHOD(Date_getDay)
		{
			//Arrange
			int day = 1;
			int month = 1;
			int year = 2026;
			Date date(day, month, year);
			//Act
			int result = date.getDay();
			//Assert
			Assert::AreEqual(result, day);
		}
		TEST_METHOD(Date_getMonth)
		{
			//Arrange
			int day = 1;
			int month = 1;
			int year = 2026;
			Date date(day, month, year);
			//Act
			int result = date.getMonth();
			//Assert
			Assert::AreEqual(result, month);
		}
		TEST_METHOD(Date_getYear)
		{
			//Arrange
			int day = 1;
			int month = 1;
			int year = 2026;
			Date date(day, month, year);
			//Act
			int result = date.getYear();
			//Assert
			Assert::AreEqual(result, year);
		}
		TEST_METHOD(Dates_Are_Equal)
		{
			//Arrange
			int day1 = 1;
			int month1 = 1;
			int year1 = 2026;
			Date date1(day1, month1, year1);
			int day2 = 1;
			int month2 = 1;
			int year2 = 2026;
			Date date2(day2, month2, year2);
			//Act
			bool result = (date1 == date2);
			//Assert
			Assert::IsTrue(result);
		}
		TEST_METHOD(Order_constructor) {
			//Arange
			int orderID = 1;
			int clientID = 1;
			Product product("SKU-04", "Apple juice", 120.0, "l");
			OrderItem orderItem(product, 1);
			vector<OrderItem> items(1, orderItem);
			Date orderDate(1, 1, 2026);
			double finalTotal = 120.0;
			//Act
			Order order(orderID, clientID, items, orderDate, finalTotal);
			//Assert
			Assert::AreEqual(1, order.getOrderID());
			Assert::AreEqual(1, order.getClientID());
			Assert::AreEqual(items.size(), order.getItems().size());
			bool result2 = items[0] == order.getItems()[0];
			Assert::IsTrue(result2);
			bool result1 = orderDate == order.getOrderDate();
			Assert::IsTrue(result1);
			Assert::AreEqual(finalTotal, order.getFinalTotal());
		}
		TEST_METHOD(Order_getOrderID) {
			//Arange
			int orderID = 1;
			int clientID = 1;
			Product product("SKU-04", "Apple juice", 120.0, "l");
			OrderItem orderItem(product, 1);
			vector<OrderItem> items(1, orderItem);
			Date orderDate(1, 1, 2026);
			double finalTotal = 120.0;
			Order order(orderID, clientID, items, orderDate, finalTotal);
			//Act
			int result = order.getOrderID();
			//Assert
			Assert::AreEqual(orderID, result);
		}
		TEST_METHOD(Order_getClientID) {
			//Arange
			int orderID = 1;
			int clientID = 1;
			Product product("SKU-04", "Apple juice", 120.0, "l");
			OrderItem orderItem(product, 1);
			vector<OrderItem> items(1, orderItem);
			Date orderDate(1, 1, 2026);
			double finalTotal = 120.0;
			Order order(orderID, clientID, items, orderDate, finalTotal);
			//Act
			int result = order.getClientID();
			//Assert
			Assert::AreEqual(clientID, result);
		}
		TEST_METHOD(Order_getOrderItems) {
			//Arange
			int orderID = 1;
			int clientID = 1;
			Product product("SKU-04", "Apple juice", 120.0, "l");
			OrderItem orderItem(product, 1);
			vector<OrderItem> items(1, orderItem);
			Date orderDate(1, 1, 2026);
			double finalTotal = 120.0;
			Order order(orderID, clientID, items, orderDate, finalTotal);
			//Act
			vector<OrderItem> result = order.getItems();
			//Assert
			Assert::AreEqual(items.size(), result.size());
			bool res = items[0] == result[0];
			Assert::IsTrue(res);
		}
		TEST_METHOD(Order_getOrderDate) {
			//Arange
			int orderID = 1;
			int clientID = 1;
			Product product("SKU-04", "Apple juice", 120.0, "l");
			OrderItem orderItem(product, 1);
			vector<OrderItem> items(1, orderItem);
			Date orderDate(1, 1, 2026);
			double finalTotal = 120.0;
			Order order(orderID, clientID, items, orderDate, finalTotal);
			//Act
			Date result = order.getOrderDate();
			//Assert
			bool res = orderDate == result;
			Assert::IsTrue(res);
		}
		TEST_METHOD(Order_getFinalTotal) {
			//Arange
			int orderID = 1;
			int clientID = 1;
			Product product("SKU-04", "Apple juice", 120.0, "l");
			OrderItem orderItem(product, 1);
			vector<OrderItem> items(1, orderItem);
			Date orderDate(1, 1, 2026);
			double finalTotal = 120.0;
			Order order(orderID, clientID, items, orderDate, finalTotal);
			//Act
			double result = order.getFinalTotal();
			//Assert
			Assert::AreEqual(finalTotal, result);
		}
		TEST_METHOD(Order_ToString) {
			//Arange
			int orderID = 1;
			int clientID = 1;
			Product product("SKU-04", "Apple juice", 120.0, "l");
			OrderItem orderItem(product, 1);
			vector<OrderItem> items(1, orderItem);
			Date orderDate(1, 1, 2026);
			double finalTotal = 120.0;
			Order order(orderID, clientID, items, orderDate, finalTotal);
			string test = " * Order #1 | Client ID: 1 | Date: 1. 1. 2026 | Total: 120.000000 rub.";
			//Act
			string result = order.ToString();
			//Assert
			Assert::AreEqual(test, result);
		}
		TEST_METHOD(Orders_Are_Equal) {
			//Arange
			int orderID1 = 1;
			int clientID1 = 1;
			Product product("SKU-04", "Apple juice", 120.0, "l");
			OrderItem orderItem(product, 1);
			vector<OrderItem> items1(1, orderItem);
			Date orderDate1(1, 1, 2026);
			double finalTotal1 = 120.0;
			Order order1(orderID1, clientID1, items1, orderDate1, finalTotal1);
			int orderID2 = 1;
			int clientID2 = 1;
			vector<OrderItem> items2(1, orderItem);
			Date orderDate2(1, 1, 2026);
			double finalTotal2 = 120.0;
			Order order2(orderID2, clientID2, items2, orderDate2, finalTotal2);
			//Act
			bool result = order1 == order2;
			//Assert
			Assert::IsTrue(result);
		}
		TEST_METHOD(Product_Constructor) {
			//Arange//Act
			Product product;
			string empty = "";
			//Assert
			Assert::AreEqual(product.getSKU(), empty);
			Assert::AreEqual(product.getName(), empty);
			Assert::AreEqual(product.getBasePrice(), 0.0);
		}
		TEST_METHOD(Product_Constructor_with_params) {
			//Arange
			string SKU = "SKU-04";
			string name = "Apple juice";
			double basePrice = 120.0;
			string unit = "l";
			//Act
			Product product(SKU ,name, basePrice, unit);
			//Assert
			Assert::AreEqual(product.getSKU(), SKU);
			Assert::AreEqual(product.getName(), name);
			Assert::AreEqual(product.getBasePrice(), basePrice);
			Assert::AreEqual(product.getUnit(), unit);
		}
		TEST_METHOD(Product_getSKU) {
			//Arange
			string SKU = "SKU-04";
			string name = "Apple juice";
			double basePrice = 120.0;
			string unit = "l";
			Product product(SKU, name, basePrice, unit);
			//Act
			string result = product.getSKU();
			//Assert
			Assert::AreEqual(result, SKU);
		}
		TEST_METHOD(Product_getName) {
			//Arange
			string SKU = "SKU-04";
			string name = "Apple juice";
			double basePrice = 120.0;
			string unit = "l";
			Product product(SKU, name, basePrice, unit);
			//Act
			string result = product.getName();
			//Assert
			Assert::AreEqual(result, name);
		}
		TEST_METHOD(Product_getBasePrice) {
			//Arange
			string SKU = "SKU-04";
			string name = "Apple juice";
			double basePrice = 120.0;
			string unit = "l";
			Product product(SKU, name, basePrice, unit);
			//Act
			double result = product.getBasePrice();
			//Assert
			Assert::AreEqual(result, basePrice);
		}
		TEST_METHOD(Product_getUnit) {
			//Arange
			string SKU = "SKU-04";
			string name = "Apple juice";
			double basePrice = 120.0;
			string unit = "l";
			Product product(SKU, name, basePrice, unit);
			//Act
			string result = product.getUnit();
			//Assert
			Assert::AreEqual(result, unit);
		}
		TEST_METHOD(Product_getInfoString) {
			//Arange
			string SKU = "SKU-04";
			string name = "Apple juice";
			double basePrice = 120.0;
			string unit = "l";
			Product product(SKU, name, basePrice, unit);
			string test = "[Item] Apple juice (SKU: SKU-04 - 120.000000 rub/l";
			//Act
			string result = product.getInfoString();
			//Assert
			Assert::AreEqual(result, test);
		}
		TEST_METHOD(Products_Are_Equal) {
			//Arange
			string SKU1 = "SKU-04";
			string name1 = "Apple juice";
			double basePrice1 = 120.0;
			string unit1 = "l";
			Product product1(SKU1, name1, basePrice1, unit1);
			string SKU2 = "SKU-04";
			string name2 = "Apple juice";
			double basePrice2 = 120.0;
			string unit2 = "l";
			Product product2(SKU2, name2, basePrice2, unit2);
			//Act
			bool result = product1 == product2;
			//Assert
			Assert::IsTrue(result);
		}
		TEST_METHOD(Products_Are_Not_Equal) {
			//Arange
			string SKU1 = "SKU-04";
			string name1 = "Apple juice";
			double basePrice1 = 120.0;
			string unit1 = "l";
			Product product1(SKU1, name1, basePrice1, unit1);
			string SKU2 = "SKU-04";
			string name2 = "Apple juice";
			double basePrice2 = 120.0;
			string unit2 = "l";
			Product product2(SKU2, name2, basePrice2, unit2);
			//Act
			bool result = product1 != product2;
			//Assert
			Assert::IsFalse(result);
		}
		TEST_METHOD(Warehouse_constructor) {
			//Arange//Act
			Warehouse warehouse;
			int test = 1;
			//Assert
			Assert::AreEqual(warehouse.getNextOrderID(), test);
		}
		TEST_METHOD(Warehouse_addProductStock) {
			//Arange
			Warehouse warehouse;
			string SKU = "SKU-04";
			string name = "Apple juice";
			double basePrice = 120.0;
			string unit = "l";
			Product product(SKU, name, basePrice, unit);
			double quantity = 1.0;
			WarehouseItem wi(product, quantity);
			vector<WarehouseItem> test(1, wi);
			//Act
			warehouse.addProductStock(product, quantity);
			//Assert
			Assert::AreEqual(warehouse.getCurrentInventory().size(), test.size());
			bool result = warehouse.getCurrentInventory()[0] == test[0];
			Assert::IsTrue(result);
		}
		TEST_METHOD(Warehouse_registerClient) {
			//Arange
			Warehouse warehouse;
			int id = 1;
			string name = "AAA";
			string clientType = "Retail";
			string address = "Apple st.";
			Client client(id, name, clientType, address);
			vector<Client> test(1, client);
			//Act
			warehouse.registerClient(client);
			//Assert
			Assert::AreEqual(warehouse.getClients().size(), test.size());
			bool result = warehouse.getClients()[0] == test[0];
			Assert::IsTrue(result);
		}
		TEST_METHOD(Warehouse_registerClient_sameIDs) {
			//Arange
			Warehouse warehouse;
			Client client1(1, "Ivan", "Regular", "Moscow");
			Client client2(1, "Petr", "Retail", "Tomsk");
			//Act
			warehouse.registerClient(client1);
			warehouse.registerClient(client2);
			//Assert
			Assert::AreEqual(static_cast<size_t>(1), warehouse.getClients().size());
			Assert::AreEqual(string("Ivan"), warehouse.getClients()[0].getName());
		}
		TEST_METHOD(Empty_Warehouse_processOrder) {
			//Arrange
			Warehouse warehouse;
			int clientID = 1;
			vector<pair<string, double>> cart;
			string product_SKU = "SKU-04";
			string product_name = "Apple juice";
			double product_base_price = 120.0;
			string product_unit = "l";
			double product_quantity = 400.0;
			cart.push_back(pair<string, double>(product_SKU, 50.0));
			Date order_date(1, 1, 2026);
			//Act
			bool result = warehouse.processOrder(clientID, cart, order_date);
			//Assert
			Assert::IsFalse(result);
		}
		TEST_METHOD(Warehouse_processOrder) {
			//Arrange
			Warehouse warehouse;
			vector<pair<string, double>> cart;
			string product_SKU = "SKU-04";
			string product_name = "Apple juice";
			double product_base_price = 120.0;
			string product_unit = "l";
			double product_quantity = 400.0;
			Date order_date(1, 1, 2026);
			cart.push_back(pair<string, double>(product_SKU, 50.0));
			Product product(product_SKU, product_name, product_base_price, product_unit);
			warehouse.addProductStock(product, product_quantity);
			int client_ID = 1;
			string client_name = "AAA";
			string client_type = "Retail";
			string client_address = "Apple st.";
			Client client(client_ID, client_name, client_type, client_address);
			warehouse.registerClient(client);
			//Act
			bool result = warehouse.processOrder(client_ID, cart, order_date);
			//Assert
			Assert::IsTrue(result);
		}
		TEST_METHOD(Warehouse_getCurentInventory) {
			//Arrange
			Warehouse warehouse;
			vector<pair<string, double>> cart;
			string product_SKU = "SKU-04";
			string product_name = "Apple juice";
			double product_base_price = 120.0;
			string product_unit = "l";
			double product_quantity = 400.0;
			Product product(product_SKU, product_name, product_base_price, product_unit);
			warehouse.addProductStock(product, product_quantity);
			WarehouseItem item(product, product_quantity);
			vector<WarehouseItem> test;
			test.push_back(item);
			//Act
			vector<WarehouseItem> result = warehouse.getCurrentInventory();
			//Assert
			Assert::AreEqual(result.size(), test.size());
			bool res = result[0] == test[0];
			Assert::IsTrue(res);
		}
		TEST_METHOD(Warehouse_getSalesHistory) {
			Warehouse warehouse;
			int clientID = 1;
			vector<pair<string, double>> cart;
			string product_SKU = "SKU-04";
			string product_name = "Apple juice";
			double product_base_price = 120.0;
			string product_unit = "l";
			double product_quantity = 400.0;
			Date order_date(1, 1, 2026);
			cart.push_back(pair<string, double>(product_SKU, 50.0));
			Product product(product_SKU, product_name, product_base_price, product_unit);
			warehouse.addProductStock(product, product_quantity);
			int client_ID = 1;
			string client_name = "AAA";
			string client_type = "Retail";
			string client_address = "Apple st.";
			Client client(client_ID, client_name, client_type, client_address);
			warehouse.registerClient(client);
			warehouse.processOrder(clientID, cart, order_date);
			OrderItem item(product, 50.0);
			Order order(1, 1, vector<OrderItem>(1, item), order_date, 6000.0);
			vector<Order>  test;
			test.push_back(order);
			//Act
			vector<Order> result = warehouse.getSalesHistory();
			//Assert
			Assert::AreEqual(result.size(), test.size());
			bool res = result[0] == test[0];
			Assert::IsTrue(res);
		}
		TEST_METHOD(Warehouse_getClients) {
			//Arrange
			Warehouse warehouse;
			int client_ID = 1;
			string client_name = "AAA";
			string client_type = "Retail";
			string client_address = "Apple st.";
			Client client(client_ID, client_name, client_type, client_address);
			warehouse.registerClient(client);
			vector<Client> test;
			test.push_back(client);
			//Act
			vector<Client> result = warehouse.getClients();
			//Assert
			Assert::AreEqual(result.size(), test.size());
			bool res = result[0] == test[0];
			Assert::IsTrue(res);
		}
		TEST_METHOD(Warehouse_getNextOrderID) {
			//Arange
			Warehouse warehouse;
			int test = 1;
			//Act
			int result = warehouse.getNextOrderID();
			//Assert
			Assert::AreEqual(result, test);
		}
		TEST_METHOD(WarehouseItems_are_Equal) {
			//Arange
			string product_SKU = "SKU-04";
			string product_name = "Apple juice";
			double product_base_price = 120.0;
			string product_unit = "l";
			double product_quantity = 400.0;
			Product product(product_SKU, product_name, product_base_price, product_unit);
			WarehouseItem item1(product, product_quantity);
			WarehouseItem item2(product, product_quantity);
			//Act
			bool result = item1 == item2;
			//Assert
			Assert::IsTrue(result);
		}
		TEST_METHOD(WarehouseItems_are_not_Equal) {
			//Arange
			string product_SKU1 = "SKU-04";
			string product_name1 = "Apple juice";
			double product_base_price1 = 120.0;
			string product_unit1 = "l";
			double product_quantity1 = 400.0;
			Product product1(product_SKU1, product_name1, product_base_price1, product_unit1);
			WarehouseItem item1(product1, product_quantity1);
			string product_SKU2 = "SKU-03";
			string product_name2 = "Flour";
			double product_base_price2 = 50.0;
			string product_unit2 = "kg";
			double product_quantity2 = 100.0;
			Product product2(product_SKU2, product_name2, product_base_price2, product_unit2);
			WarehouseItem item2(product2, product_quantity2);
			//Act
			bool result = item1 != item2;
			//Assert
			Assert::IsTrue(result);
		}
	};
}
