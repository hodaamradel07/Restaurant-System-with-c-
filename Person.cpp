#include "Person.h"

Person::Person(string n, int a, string c, int i){
    name = n;
    contactInfo = c;
    age = a;
    id = i;
}

Person::~Person(){}

void Person::getInfo(){
    cout << "Name : " << name << endl;
    cout << "Contact Info : " << contactInfo << endl;
    cout << "Age : " << age << endl;
    cout << "Id : " << id << endl;
}

string Person::getName(){
    return name;
}

int Person::getAge(){
    return age;
}

int Person::getId(){
    return id;
}