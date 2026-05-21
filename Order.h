#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Order {
private:
    int orderId;
    int customerId;
    int tableNumber;
    string status;
    double tax;
    double discount;

    vector<int> itemIds;
    vector<int> quantities;
    vector<double> prices;

public:
    Order();
    Order(int oid, int cid, int table);
    void addItem(int itemId, int qty, double price);
    void removeItem(int itemId);
    void updateStatus(string newStatus);
    void setDiscount(double d);
    void viewOrder();
    void generateBill();
    int getOrderId();  //getters
    int getCustomerId();//getters
    int getTableNumber();//getters
    string getStatus();//getters
    bool isEmpty();//to check if item is empty or not
};

#endif