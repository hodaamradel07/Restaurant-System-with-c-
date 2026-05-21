#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

class Customer : public Person {
    private:
    vector<int> orderHistory;
    vector<int> quantities;
    protected:
    int tableNumber;
    int loyaltyPoints;
    public:
    Customer(string n, int a, string c, int i, int table);
    void placeOrder(int order, int ite_num);
    void viewHistory();
    void redeemPoints();
    int getTable();
    void setTable(int t);
    int getLoyaltyPoints();
};

#endif