#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Category {
private:
    string categoryName;
    vector<Item> items;//composition

public:
    void setCategory(string n);
    string getCategoryName();
    void addItem(int itemId, string itemName, double price);
    void showCategory();
    void findItem(int searchId);
    bool itemExists(int searchId);
    void findItemByName(string searchName);
    bool itemExistsByName(string searchName);
    double getItemPrice(int searchId);
    bool updateItem(int id, string newName, double newPrice, bool newAvailability);
    bool removeItem(int id);
};

#endif