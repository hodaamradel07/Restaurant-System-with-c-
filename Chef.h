#ifndef CHEF_H
#define CHEF_H

#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Chef : public Person {
    private:
    string specialization;
    string kitchenStation;

    public:
    Chef(string n, int a, string c, int i, string spec, string stat);
    void prepareOrder();
    void markReady();
    void getInfo();
};

#endif