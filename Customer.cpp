#include "Customer.h"

Customer::Customer(string n, int a, string c, int i, int table) : Person(n, a, c, i){
    tableNumber = table;
    loyaltyPoints = 0;
}

void Customer::placeOrder(int order, int ite_num){
    orderHistory.push_back(order);
    quantities.push_back(ite_num);
    loyaltyPoints += 10;
    cout << "Order placed : " << order << endl;
}

void Customer::viewHistory(){
    cout << "Order History" << endl;
    for(int i = 0; i < orderHistory.size(); i++){
        cout << "--" << quantities[i] << "x item ID: " << orderHistory[i] << endl;
    }
}

void Customer::redeemPoints(){
    if(loyaltyPoints >= 50){
        cout << "Points redeemed!" << endl;
        loyaltyPoints -= 50;
    } else {
        cout << "Not enough points!" << endl;
    }
}

int Customer::getTable(){
    return tableNumber;
}

void Customer::setTable(int t){
    tableNumber = t;
}

int Customer::getLoyaltyPoints(){
    return loyaltyPoints;
}