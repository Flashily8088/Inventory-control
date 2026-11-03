#include "CppUnitTest.h"
#include <iostream>
#include <string>
#include<vector>
#include<memory>
#include<iomanip>
#include "../Solver/Warehouse.h"
#include "../Solver/BulkProduct.h"
#include "../Solver/PackedProduct.h"
#include "../Solver/RetailStore.h"
#include "../Solver/WholesaleClient.h"
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

		TEST_METHOD(BulkProduct_constructor)
		{
			//Arrange
			string SKU = "SKU-01";
			string name = "Apple";
			double price = 1000.0;
			string unit = "kg";
			//Act
			BulkProduct product(SKU, name, price, unit);
			//Assert
			Assert::AreEqual(product.getSKU(), SKU);
			Assert::AreEqual(product.getName(), name);
			Assert::AreEqual(product.getBasePrice(), price);
			Assert::AreEqual(product.getUnit(), unit);
		}
		TEST_METHOD(BulkProduct_getInfoString) {
			//Arrange
			string SKU = "SKU-01";
			string name = "Apple";
			double price = 1000.0;
			string unit = "kg";
			BulkProduct product(SKU, name, price, unit);
			string test = "[Item] Apple (SKU: SKU-01) - 1000.000000 rub/kg";
			//Act
			string result = product.getInfoString();
			//Assert
			Assert::AreEqual(result, test);
		}
		TEST_METHOD(BulkProduct_getSKU) {
			//Arrange
			string SKU = "SKU-01";
			string name = "Apple";
			double price = 1000.0;
			string unit = "kg";
			BulkProduct product(SKU, name, price, unit);
			//Act
			string result = product.getSKU();
			//Assert
			Assert::AreEqual(result, SKU);
		}
		TEST_METHOD(BulkProduct_getName) {
			//Arrange
			string SKU = "SKU-01";
			string name = "Apple";
			double price = 1000.0;
			string unit = "kg";
			BulkProduct product(SKU, name, price, unit);
			//Act
			string result = product.getName();
			//Assert
			Assert::AreEqual(result, name);
		}
		TEST_METHOD(BulkProduct_getPrice) {
			//Arrange
			string SKU = "SKU-01";
			string name = "Apple";
			double price = 1000.0;
			string unit = "kg";
			BulkProduct product(SKU, name, price, unit);
			//Act
			double result = product.getBasePrice();
			//Assert
			Assert::AreEqual(result, price);
		}
		TEST_METHOD(BulkProduct_getUnit) {
			//Arrange
			string SKU = "SKU-01";
			string name = "Apple";
			double price = 1000.0;
			string unit = "kg";
			BulkProduct product(SKU, name, price, unit);
			//Act
			string result = product.getUnit();
			//Assert
			Assert::AreEqual(result, unit);
		}
		TEST_METHOD(PackedProduct_constructor)
		{
			//Arrange
			string SKU = "SKU-01";
			string name = "Apple";
			double price = 1000.0;
			string packigingType = "box";
			int volumePerUnit = 10;
			//Act
			PackedProduct product(SKU, name, price, packigingType, volumePerUnit);
			//Assert
			Assert::AreEqual(product.getSKU(), SKU);
			Assert::AreEqual(product.getName(), name);
			Assert::AreEqual(product.getBasePrice(), price);
			Assert::AreEqual(product.getPackagingType(), packigingType);
			Assert::AreEqual(product.getVolumePerUnit(), volumePerUnit);
		}
		TEST_METHOD(PackedProduct_getInfoString) {
			//Arrange
			string SKU = "SKU-01";
			string name = "Apple";
			double price = 1000.0;
			string packigingType = "box";
			int volumePerUnit = 10;
			PackedProduct product(SKU, name, price, packigingType, volumePerUnit);
			string test = "[Item] Apple (SKU: SKU-01) - Type of packaging: box (10 kg/l), Price: 1000.000000 rub/item.";
			//Act
			string result = product.getInfoString();
			//Assert
			Assert::AreEqual(result, test);
		}
		TEST_METHOD(PackedProduct_getPackigingType)
		{
			//Arrange
			string SKU = "SKU-01";
			string name = "Apple";
			double price = 1000.0;
			string packigingType = "box";
			int volumePerUnit = 10;
			PackedProduct product(SKU, name, price, packigingType, volumePerUnit);
			//Act
			string result = product.getPackagingType();
			//Assert
			Assert::AreEqual(result, packigingType);
		}
		TEST_METHOD(PackedProduct_getVolumePerUnit)
		{
			//Arrange
			string SKU = "SKU-01";
			string name = "Apple";
			double price = 1000.0;
			string packigingType = "box";
			int volumePerUnit = 10;
			PackedProduct product(SKU, name, price, packigingType, volumePerUnit);
			//Act
			int result = product.getVolumePerUnit();
			//Assert
			Assert::AreEqual(result, volumePerUnit);
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
		TEST_METHOD(Order_constructor) {
			//Arrange
			int orderID = 1;
			int clientID = 1;
			Date date(1, 1, 2026);
			double finalTotal = 400.0;
			shared_ptr<Product> flour = make_shared<BulkProduct>("SKU-01", "Flour", 40.0, "kg");
			OrderItem orderItem;
			orderItem.product = flour;
			orderItem.quantity = 10.0;
			vector<OrderItem> orderItems;
			orderItems.push_back(orderItem);
			//Act
			Order order(orderID, clientID, orderItems, date, finalTotal);
			//Assert
			Assert::AreEqual(order.getOrderID(), orderID);
			Assert::AreEqual(order.getClientID(), clientID);
			Assert::AreEqual(orderItems.size(), order.getItems().size());
			Assert::AreEqual(orderItems[0].product->getSKU(), order.getItems()[0].product->getSKU());
			Assert::AreEqual(orderItems[0].quantity, order.getItems()[0].quantity);
			Assert::AreEqual(date.ToString(), order.getOrderDate().ToString());
			Assert::AreEqual(order.getFinalTotal(), finalTotal);
		}
		TEST_METHOD(Order_getOrderID) {
			//Arrange
			int orderID = 1;
			int clientID = 1;
			Date date(1, 1, 2026);
			double finalTotal = 400.0;
			shared_ptr<Product> flour = make_shared<BulkProduct>("SKU-01", "Flour", 40.0, "kg");
			OrderItem orderItem;
			orderItem.product = flour;
			orderItem.quantity = 10.0;
			vector<OrderItem> orderItems;
			orderItems.push_back(orderItem);
			Order order(orderID, clientID, orderItems, date, finalTotal);
			//Act
			int result = order.getOrderID();
			//Assert
			Assert::AreEqual(result, orderID);
		}
		TEST_METHOD(Order_getClientID) {
			//Arrange
			int orderID = 1;
			int clientID = 1;
			Date date(1, 1, 2026);
			double finalTotal = 400.0;
			shared_ptr<Product> flour = make_shared<BulkProduct>("SKU-01", "Flour", 40.0, "kg");
			OrderItem orderItem;
			orderItem.product = flour;
			orderItem.quantity = 10.0;
			vector<OrderItem> orderItems;
			orderItems.push_back(orderItem);
			Order order(orderID, clientID, orderItems, date, finalTotal);
			//Act
			int result = order.getClientID();
			//Assert
			Assert::AreEqual(result, clientID);
		}
		TEST_METHOD(Order_getItems) {
			//Arrange
			int orderID = 1;
			int clientID = 1;
			Date date(1, 1, 2026);
			double finalTotal = 400.0;
			shared_ptr<Product> flour = make_shared<BulkProduct>("SKU-01", "Flour", 40.0, "kg");
			OrderItem orderItem;
			orderItem.product = flour;
			orderItem.quantity = 10.0;
			vector<OrderItem> orderItems;
			orderItems.push_back(orderItem);
			Order order(orderID, clientID, orderItems, date, finalTotal);
			//Act
			vector <OrderItem> result = order.getItems();
			//Assert
			Assert::AreEqual(orderItems.size(), result.size());
			Assert::AreEqual(orderItems[0].product->getSKU(), result[0].product->getSKU());
			Assert::AreEqual(orderItems[0].quantity, result[0].quantity);
		}
		TEST_METHOD(Order_getOrderDate) {
			//Arrange
			int orderID = 1;
			int clientID = 1;
			Date date(1, 1, 2026);
			double finalTotal = 400.0;
			shared_ptr<Product> flour = make_shared<BulkProduct>("SKU-01", "Flour", 40.0, "kg");
			OrderItem orderItem;
			orderItem.product = flour;
			orderItem.quantity = 10.0;
			vector<OrderItem> orderItems;
			orderItems.push_back(orderItem);
			Order order(orderID, clientID, orderItems, date, finalTotal);
			//Act
			Date result = order.getOrderDate();
			//Assert
			Assert::AreEqual(date.ToString(), result.ToString());
		}
		TEST_METHOD(Order_getFinalTotal) {
			//Arrange
			int orderID = 1;
			int clientID = 1;
			Date date(1, 1, 2026);
			double finalTotal = 400.0;
			shared_ptr<Product> flour = make_shared<BulkProduct>("SKU-01", "Flour", 40.0, "kg");
			OrderItem orderItem;
			orderItem.product = flour;
			orderItem.quantity = 10.0;
			vector<OrderItem> orderItems;
			orderItems.push_back(orderItem);
			Order order(orderID, clientID, orderItems, date, finalTotal);
			//Act
			double result = order.getFinalTotal();
			//Assert
			Assert::AreEqual(result, finalTotal);
		}
		TEST_METHOD(Order_ToString) {
			//Arrange
			int orderID = 1;
			int clientID = 1;
			Date date(1, 1, 2026);
			double finalTotal = 400.0;
			shared_ptr<Product> flour = make_shared<BulkProduct>("SKU-01", "Flour", 40.0, "kg");
			OrderItem orderItem;
			orderItem.product = flour;
			orderItem.quantity = 10.0;
			vector<OrderItem> orderItems;
			orderItems.push_back(orderItem);
			Order order(orderID, clientID, orderItems, date, finalTotal);
			string test = " * Order #1 | Client ID: 1 | Date: 1. 1. 2026 | Total: 400.000000 rub.";
			//Act
			string result = order.ToString();
			//Assert
			Assert::AreEqual(result, test);
		}
		TEST_METHOD(Retail_constructor)
		{
			//Arrange
			int ID = 1;
			string name = "AAA";
			string address = "St. Apple, 15";
			//Act
			RetailStore store(ID, name, address);
			//Assert
			Assert::AreEqual(store.getID(), ID);
			Assert::AreEqual(store.getName(), name);
			Assert::AreEqual(store.getAddress(), address);
		}
		TEST_METHOD(Retail_getClientTypeString)
		{
			//Arrange
			int ID = 1;
			string name = "AAA";
			string address = "St. Apple, 15";
			RetailStore store(ID, name, address);
			string test = "Retail store (Address: St. Apple, 15";
			//Act
			string result = store.getClientTypeString();
			//Assert
			Assert::AreEqual(result, test);
		}
		TEST_METHOD(Retail_getAddress)
		{
			//Arrange
			int ID = 1;
			string name = "AAA";
			string address = "St. Apple, 15";
			RetailStore store(ID, name, address);
			//Act
			string result = store.getAddress();
			//Assert
			Assert::AreEqual(result, address);
		}
		TEST_METHOD(Wholesale_constructor)
		{
			//Arrange
			int ID = 1;
			string name = "AAA";
			double discount = 5.0;
			//Act
			WholesaleClient store(ID, name, discount);
			//Assert
			Assert::AreEqual(store.getID(), ID);
			Assert::AreEqual(store.getName(), name);
			Assert::AreEqual(store.getDiscountRate(), discount);
		}
		TEST_METHOD(Wholesale_getDiscountRate)
		{
			//Arrange
			int ID = 1;
			string name = "AAA";
			double discount = 5.0;
			WholesaleClient store(ID, name, discount);
			//Act
			double result = store.getDiscountRate();
			//Assert
			Assert::AreEqual(result, discount);
		}
		TEST_METHOD(Wholesale_updateDiscount)
		{
			//Arrange
			int ID = 1;
			string name = "AAA";
			double discount = 5.0;
			WholesaleClient store(ID, name, discount);
			store.addSpentMoney(500010.0);
			//Act
			store.updateDiscountStatus();
			//Assert
			Assert::AreEqual(store.getDiscountRate(), 0.15);
		}
		TEST_METHOD(Wholesale_getClientTypeString)
		{
			//Arrange
			int ID = 1;
			string name = "AAA";
			double discount = 5.0;
			WholesaleClient store(ID, name, discount);
			string test = "Wholesale client (Discount: 5.000000";
			//Act
			string result = store.getClientTypeString();
			//Assert
			Assert::AreEqual(result, test);
		}
		TEST_METHOD(Warehose_constructor) {
			//Arregne
			//Act
			Warehouse wh;
			const vector<WarehouseItem>& initialInventory = wh.getCurrentInventory();
			const vector<shared_ptr<Client>>& initialClients = wh.getClients();
			const vector<Order>& initialHistory = wh.getSalesHistory();
			//Assert
			Assert::AreEqual(static_cast<size_t>(0), initialInventory.size());
			Assert::AreEqual(static_cast<size_t>(0), initialClients.size());
			Assert::AreEqual(static_cast<size_t>(0), initialHistory.size());
		}
		TEST_METHOD(Warehouse_AddProductStock_And_Summation)
		{
			//Arrenge
			Warehouse wh;
			shared_ptr<Product> flour = make_shared<BulkProduct>("SKU-01", "Flour", 40.0, "kg");
			//Act
			wh.addProductStock(flour, 50.0);
			const vector<WarehouseItem>& initialInventory = wh.getCurrentInventory();
			//Assert
			Assert::AreEqual(static_cast<size_t>(1), initialInventory.size());
			Assert::AreEqual(50.0, initialInventory[0].quantity);
			//Act
			wh.addProductStock(flour, 50.0);
			//Assert
			Assert::AreEqual(static_cast<size_t>(1), initialInventory.size());
			Assert::AreEqual(100.0, initialInventory[0].quantity);
		}
		TEST_METHOD(Warehouse_RegisterClient)
		{
			// Arrange
			Warehouse wh;
			shared_ptr<Client> store = make_shared<RetailStore>(101, "Paterochka", "Lenina St.");

			// Act
			wh.registerClient(store);

			// Assert
			const vector<shared_ptr<Client>>& clients = wh.getClients();
			Assert::AreEqual(static_cast<size_t>(1), clients.size());
			Assert::AreEqual(101, clients[0]->getID());
			Assert::AreEqual(string("Paterochka"), clients[0]->getName());
		}
		TEST_METHOD(Warehouse_ProcessOrder_Success)
		{
			// Arrange
			Warehouse wh;
			shared_ptr<Product> flour = make_shared<BulkProduct>("SKU-01", "Flour", 40.0, "kg");
			wh.addProductStock(flour, 150.0); // Кладем 150 кг на склад
			shared_ptr<Client> store = make_shared<RetailStore>(101, "Paterochka", "Lenina St.");
			wh.registerClient(store);
			vector<pair<string, double>> cart;
			cart.push_back(pair<string, double>("SKU-01", 50.0));
			// Act
			bool result = wh.processOrder(101, cart, Date(2, 11, 2026));
			// Assert
			Assert::IsTrue(result);
			Assert::AreEqual(100.0, wh.getCurrentInventory()[0].quantity);
			Assert::AreEqual(static_cast<size_t>(1), wh.getSalesHistory().size());
			Assert::AreEqual(2000.0, wh.getSalesHistory()[0].getFinalTotal());
			Assert::AreEqual(2000.0, store->getTotalSpent());
		}
	};
}
