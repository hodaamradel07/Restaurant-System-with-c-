#include "Category.h"

void Category::setCategory(string n){
    categoryName = n;
}

string Category::getCategoryName(){
    return categoryName;
}

void Category::addItem(int itemId, string itemName, double price){
    Item newItem;
    newItem.setItem(itemId, itemName, price);
    items.push_back(newItem);
}

void Category::showCategory(){
    cout << "\nCategory: " << categoryName << endl;
    for(int i = 0; i < items.size(); i++){
        items[i].displayItem();
        cout << "--------------" << endl;
    }
}

void Category::findItem(int searchId){
    for(int i = 0; i < items.size(); i++){
        if(items[i].getId() == searchId){
            cout << "---- Item found ----" << endl;
            items[i].displayItem();
            return;
        }
    }
}

bool Category::itemExists(int searchId){
    for(int i = 0; i < items.size(); i++){
        if(items[i].getId() == searchId){
            return true;
        }
    }
    return false;
}

void Category::findItemByName(string searchName){
    for(int i = 0; i < items.size(); i++){
        if(items[i].getName() == searchName){
            cout << "---- Item found ----" << endl;
            items[i].displayItem();
            return;
        }
    }
}

bool Category::itemExistsByName(string searchName){
    for(int i = 0; i < items.size(); i++){
        if(items[i].getName() == searchName){
            return true;
        }
    }
    return false;
}

double Category::getItemPrice(int searchId){
    for(int i = 0; i < items.size(); i++){
        if(items[i].getId() == searchId){
            return items[i].getPrice();
        }
    }
    return -1;
}

bool Category::updateItem(int id, string newName, double newPrice, bool newAvailability){
    for(int i = 0; i < items.size(); i++){
        if(items[i].getId() == id){
            items[i].setItem(id, newName, newPrice);
            items[i].setAvailability(newAvailability);
            return true;
        }
    }
    return false;
}

bool Category::removeItem(int id){
    int index = -1;
    for(int i = 0; i < items.size(); i++){
        if(items[i].getId() == id){
            index = i;
            break;
        }
    }
    if(index != -1){
        items.erase(items.begin() + index);
        return true;
    }
    return false;
}