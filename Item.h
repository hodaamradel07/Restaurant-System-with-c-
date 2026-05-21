#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    int id;
    string name;
    double price;
    bool available;

public:
    Item();
    void setItem(int i, string n, double p);
    void setAvailability(bool a);
    bool isAvailable();
    void displayItem();
    int getId();
    string getName();
    double getPrice();
};

#endif