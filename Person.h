#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
    protected:
    string name;
    string contactInfo;
    int age;
    int id;
    public:
    Person(string n, int a, string c, int i);
    virtual ~Person();
    virtual void getInfo();
    string getName();
    int getAge();
    int getId();
};

#endif