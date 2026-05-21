#include "Item.h"

Item::Item(){
    id = 0;
    name = "";
    price = 0;
    available = true;
}

void Item::setItem(int i, string n, double p){
    id = i;
    name = n;
    price = p;
}

void Item::setAvailability(bool a){
    available = a;
}

bool Item::isAvailable(){
    return available;
}

void Item::displayItem(){
    cout << "Item ID: " << id << endl;
    cout << "Item Name: " << name << endl;
    cout << "Price: " << price << "$" << endl;
    cout << "Available: " << (available ? "Yes" : "No") << endl;
}

int Item::getId(){
    return id;
}

string Item::getName(){
    return name;
}

double Item::getPrice(){
    return price;
}