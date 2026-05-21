#include "Waiter.h"

Waiter::Waiter(string n, int a, string c, int i, string s) : Person(n, a, c, i){
    shift = s;
}

void Waiter::takeOrder(){
    cout << "Waiter is taking order." << endl;
}

void Waiter::updateStatus(){
    cout << "Order status updated." << endl;
}

void Waiter::assignTable(int table){
    assignedTables.push_back(table);
    cout << "Table " << table << " is assigned to waiter " << name << endl;
}

void Waiter::getInfo(){
    Person::getInfo();
    cout << "Shift : " << shift << endl;
}