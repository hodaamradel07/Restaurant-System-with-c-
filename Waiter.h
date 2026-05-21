#ifndef WAITER_H
#define WAITER_H

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

class Waiter : public Person {
    private:
    string shift;
    vector<int> assignedTables;

    public:
    Waiter(string n, int a, string c, int i, string s);
    void takeOrder();
    void updateStatus();
    void assignTable(int table);
    void getInfo();
};

#endif