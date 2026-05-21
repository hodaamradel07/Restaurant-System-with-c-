#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include <vector>
#include "Category.h"
#include "Person.h"
#include "Customer.h"
#include "Chef.h"
#include "Waiter.h"
#include "Order.h"
using namespace std;

class Restaurant {
private:
    vector<Category> menu;
    vector<Person*> staff;
    vector<Customer*> customers;
    vector<Order> orders;
    vector<int> tableNumbers;
    vector<bool> tableAvailable;
    vector<int> tableCustomerIds;
    int nextOrderId;

public:
    Restaurant();
    ~Restaurant();

    void addCategory(string name);
    bool exists(int id);
    bool customerExists(int id);
    void addMenuItem(int categoryIndex, int itemId, string itemName, double price);
    void addStaff(Person* p);
    void removeStaff(int id);
    void viewStaff();
    void viewChefs();
    void viewWaiters();
    void searchStaff(int id);
    void viewMenu();
    void searchMenuItem(int id);
    bool menuItemExists(int id);
    double getMenuItemPrice(int id);
    void searchMenuItemByName(string name);
    void searchMenuItemByCategory(string categoryName);
    void updateMenuItem(int id, string newName, double newPrice, bool newAvailability);
    void removeItemFromMenu(int id);
    void addCustomer(Customer* c);
    void searchCustomer(int id);
    void viewCustomerHistory(int id);
    void viewCustomers();
    int createOrder(int customerId, int tableNumber);
    void addItemToOrder(int orderId, int itemId, int qty);
    void removeItemFromOrder(int orderId, int itemId);
    void advanceOrderStatus(int orderId);
    void viewOrder(int orderId);
    void searchOrdersByTable(int tableNumber);
    void viewAllOrders();
    void generateOrderBill(int orderId);
    int getMenuSize();
    void viewTables();
    void setTableAvailability(int tableNumber, bool available);
    void occupyTable(int tableNumber, int customerId);
    void clearTable(int tableNumber);
    void updateCustomerTable(int customerId, int newTable);
    void checkoutTable(int tableNumber);
};

#endif