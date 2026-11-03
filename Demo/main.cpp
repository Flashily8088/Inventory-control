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
/**
 * @brief класс "Режимы меню"
 */
enum class MenuOption {
	Exit = 0,
	ShowInventory = 1,
	ShowClientOrders = 2,
	ShowSalesInPeriod = 3,
	ShowDiscountClients = 4,
	CreateNewOrder = 5,
	RestockProduct = 6,
	RegisterClient = 7,
    Invalid
};
/**
* @brief функция вывода на экран меню
*/
void showMenu();
/**
* @brief функция вывода на экран разделителя
*/
void printDivider();
/**
* @brief функция проверки введённых int данных
* * @return введённое число
*/
int inputInt();
/**
* @brief функция преверки введённых double данных
* @return введённое число
*/
double inputDouble();

/**
* @brief функция работы со складом
* @param warehouse - склад
* @param flourBulk - нерасфасованная мука
* @param flourPacked - расфасованная мука
* @param SugarBulk - нерасфасованный сахар
* @param SugarPacked - расфасованный сахар
* @param store - розничный магазин
* @param wholesaleClientt - оптовый покупатель
* @cart1 - карта заказа 1
* @cart2 - карта заказа 2
* @cart3 - карта заказа 3
* @choice/user_mod - режим меню
* 
*/
using namespace std;
int main() {
	Warehouse warehouse;
	shared_ptr<BulkProduct> flourBulk = make_shared<BulkProduct>("SKU-01", "Premium-grade flour (raw material)", 40.0, "kg");
	shared_ptr<PackedProduct> flourPacked = make_shared<PackedProduct>("SKU-02", "Premium-grade flour (pre-packaged)", 90.0, "Bag 2 kg", 2.0);
	shared_ptr<BulkProduct> SugarBulk = make_shared<BulkProduct>("SKU-03", "Sugar (raw material)", 55.0, "kg");
	shared_ptr<PackedProduct> juicePacked = make_shared<PackedProduct>("SKU-04", "Apple juice (pre-packaged)", 120.0, "Bottle 1 l", 1.0);
	warehouse.addProductStock(flourBulk, 2000.0);
	warehouse.addProductStock(flourPacked, 150.0);
	warehouse.addProductStock(SugarBulk, 5000.0);
	warehouse.addProductStock(juicePacked, 400.0);
	shared_ptr<RetailStore> store = make_shared<RetailStore>(101, "Store 7/11", "St. Apple, 15");
	shared_ptr<WholesaleClient> wholesaleClient = make_shared<WholesaleClient>(201, "BakalCorp", 0.0);
	warehouse.registerClient(store);
	warehouse.registerClient(wholesaleClient);

	vector<pair<string, double>> cart1;
	cart1.push_back(pair<string, double>("SKU-02", 50.0));
	cart1.push_back(pair<string, double>("SKU-04", 30.0));
	warehouse.processOrder(101, cart1, Date(1, 11, 2026));

	vector<pair<string, double>> cart2;
	cart2.push_back(pair<string, double>("SKU-03", 3000.0));
	warehouse.processOrder(201, cart2, Date(5, 11, 2026));

	vector<pair<string, double>> cart3;
	cart3.push_back(pair<string, double>("SKU-02", 20.0));
	warehouse.processOrder(201, cart3, Date(12, 11, 2026));

    int chose = -1;
    MenuOption user_mod = MenuOption::Invalid;

    while (user_mod != MenuOption::Exit) {
        showMenu();
        cout << "Input option: ";
        chose = inputInt();
        user_mod = static_cast<MenuOption>(chose);

        switch (user_mod) {
        case MenuOption::ShowInventory: {
            cout << "\n[TASK 1] CURRENT WAREHOUSE STOCK AND INVENTORY:\n";
            printDivider();
            const vector<WarehouseItem>& inventory = warehouse.getCurrentInventory();

            if (inventory.empty()) {
                cout << "The warehouse is completely empty.\n";
            }
            else {
                for (size_t i = 0; i < inventory.size(); ++i) {
                    const WarehouseItem& item = inventory[i];
                    shared_ptr<Product> baseProductPtr = item.product;
                    cout << " * " << baseProductPtr->getInfoString() << " | Stock remaining: " << item.quantity << " units\n";
                }
            }
            printDivider();
            break;
        }
        case MenuOption::ShowClientOrders: {
            cout << "\nEnter Client/Store ID to look up history (e.g., 101 or 201): ";
            int searchId = inputInt();

            cout << "\n[TASK 2] ORDERED ITEM LOG FOR CLIENT ID " << searchId << ":\n";
            printDivider();

            bool hasOrders = false;
            const vector<Order>& history = warehouse.getSalesHistory();

            for (size_t i = 0; i < history.size(); ++i) {
                const Order& currentOrder = history[i];
                if (currentOrder.getClientID() == searchId) {
                    hasOrders = true;
                    const vector<OrderItem>& itemsInOrder = currentOrder.getItems();
                    cout << " Order #" << currentOrder.getOrderID() << " dated " << currentOrder.getOrderDate().ToString() << ":\n";
                    for (size_t j = 0; j < itemsInOrder.size(); ++j) {
                        cout << "    -> " << itemsInOrder[j].product->getName() << " | Quantity: " << itemsInOrder[j].quantity << " units\n";
                    }
                }
            }
            if (!hasOrders) {
                cout << "This client has not placed any orders yet, or the ID does not exist.\n";
            }
            printDivider();
            break;
        }
        case MenuOption::ShowSalesInPeriod: {
            cout << "\nEnter START date:\n";
            Date startDate;
            startDate.input();
            cout << "Enter END date:\n";
            Date endDate;
            endDate.input();

            cout << "\n[TASK 3] SALES RECORD FROM " << startDate.ToString() << " TO " << endDate.ToString() << ":\n";
            printDivider();

            double totalRevenue = 0.0;
            const vector<Order>& history = warehouse.getSalesHistory();

            for (size_t i = 0; i < history.size(); ++i) {
                const Order& currentOrder = history[i];
                if (currentOrder.getOrderDate() >= startDate && currentOrder.getOrderDate() <= endDate) {
                    cout << " * Order #" << currentOrder.getOrderID()
                        << " | Client ID: " << currentOrder.getClientID()
                        << " | Date: " << currentOrder.getOrderDate().ToString()
                        << " | Total Total: " << currentOrder.getFinalTotal() << " rub.\n";
                    totalRevenue += currentOrder.getFinalTotal();
                }
            }
            cout << " Total revenue generated during this period: " << totalRevenue << " rub.\n";
            printDivider();
            break;
        }
        case MenuOption::ShowDiscountClients: {
            cout << "\n[TASK 4] LOYAL CLIENTS WITH AN ACTIVE DISCOUNT STATUS:\n";
            printDivider();

            const vector<shared_ptr<Client>>& clientList = warehouse.getClients();
            bool foundDiscount = false;

            for (size_t i = 0; i < clientList.size(); ++i) {
                const shared_ptr<Client>& currentClient = clientList[i];
                if (currentClient->getDiscountRate() > 0.0) {
                    foundDiscount = true;
                    cout << " * " << currentClient->getName() << " | " << currentClient->getClientTypeString() << " | Total revenue: " << currentClient->getTotalSpent() << " rub.\n";
                }
            }
            if (!foundDiscount) {
                cout << "No clients have qualified for a discount program yet.\n";
            }
            printDivider();
            break;
        }
        case MenuOption::CreateNewOrder: {
            cout << "\n--- CREATE NEW ORDER SELECTION ---\n";
            cout << "Enter customer ID: ";
            int orderClientId = inputInt();

            cout << "Enter product SKU: ";
            string orderSku;
            getline(cin, orderSku);

            cout << "Enter order quantity: ";
            double orderQty = inputDouble();

            cout << "Enter transaction date:\n";
            Date orderDate;
            orderDate.input();
            vector<pair<string, double>> userCart;
            userCart.push_back(pair<string, double>(orderSku, orderQty));
            if (warehouse.processOrder(orderClientId, userCart, orderDate)) {
                cout << "\n[SUCCESS]: Order processed successfully! Client account updated, stock deducted.\n";
            }
            else {
                cout << "\n[ERROR]: Transaction failed. Verify client ID validity, SKU code or warehouse limits.\n";
            }
            break;
        }
        case MenuOption::RestockProduct: {
            cout << "\n--- STOCK RESTOCK OPERATIONS ---\n";
            cout << "Enter target product SKU code (e.g., SKU-01, SKU-02): ";
            string refillSku;
            getline(cin, refillSku);
            cout << "Enter quantity allocation amount: ";
            double refillQty = inputDouble();
            shared_ptr<Product> targetProduct = nullptr;
            const vector<WarehouseItem>& inventory = warehouse.getCurrentInventory();
            for (size_t i = 0; i < inventory.size(); ++i) {
                if (inventory[i].product->getSKU() == refillSku) {
                    targetProduct = inventory[i].product;
                    break;
                }
            }
            if (targetProduct) {
                warehouse.addProductStock(targetProduct, refillQty);
                cout << "[SUCCESS]: Stock parameters reinforced successfully.\n";
            }
            else {
                cout << "[ERROR]: SKU string does not match any items stored in inventory base.\n";
            }
            break;
        }
        case MenuOption::RegisterClient: {
            cout << "\n--- CUSTOMER REGISTRATION SYSTEM ---\n";
            cout << "Enter unique integer Client ID: ";
            int newId = inputInt();
            cout << "Enter full name / Corporate account moniker: ";
            string newName;
            getline(cin, newName);
            cout << "Select user type subclass (1 - Retail Store, 2 - Wholesale Entity): ";
            int typeChoice = inputInt();
            if (typeChoice == 1) {
                cout << "Enter specific physical delivery address configuration: ";
                string address;
                getline(cin, address);
                warehouse.registerClient(make_shared<RetailStore>(newId, newName, address));
                cout << "[SUCCESS]: Retail shop recorded in global tracking layout.\n";
            }
            else if (typeChoice == 2) {
                warehouse.registerClient(make_shared<WholesaleClient>(newId, newName, 0.0));
                cout << "[SUCCESS]: Wholesale buyer synchronized. Initial tracking status discount: 0%\n";
            }
            else {
                cout << "[ERROR]: Invalid category selection matrix setup.\n";
            }
            break;
        }
        case MenuOption::Exit:
            cout << "\nClosing administrative module setup. Goodbye!\n";
            break;
        default:
            cout << "Option lookup failed! Please repeat options choice logic sequence.\n";
            break;
        }
    }
    return 0;
}

void showMenu()
{
    cout << "================ WAREHOUSE MANAGMENT SYSTEM ================" << endl;
    cout << static_cast<int>(MenuOption::ShowInventory) << ". Show current warehouse inventory\n";
    cout << static_cast<int>(MenuOption::ShowClientOrders) << ". Show products ordered by a specific store\n";
    cout << static_cast<int>(MenuOption::ShowSalesInPeriod) << ". Show sales log for a specific period\n";
    cout << static_cast<int>(MenuOption::ShowDiscountClients) << ". Show clients with an active discount\n";
    cout << static_cast<int>(MenuOption::CreateNewOrder) << ". Process a new order (Sale simulation)\n";
    cout << static_cast<int>(MenuOption::RestockProduct) << ". Restock existing product inventory\n";
    cout << static_cast<int>(MenuOption::RegisterClient) << ". Register a new customer\n";
    cout << static_cast<int>(MenuOption::Exit) << ". Exit system\n";
}

void printDivider()
{
    cout << "-----------------------------------------------------------------------" << endl;
}

int inputInt()
{
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Invalid input! Please enter an integer: ";
        }
        else {
            cin.ignore(32767, '\n');
            return value;
        }
    }
}

double inputDouble()
{
    double value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Invalid input! Please enter a number: ";
        }
        else {
            cin.ignore(32767, '\n');
            return value;
        }
    }
}
