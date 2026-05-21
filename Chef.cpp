#include "Chef.h"

Chef::Chef(string n, int a, string c, int i, string spec, string stat) : Person(n, a, c, i){
    specialization = spec;
    kitchenStation = stat;
}

void Chef::prepareOrder(){
    cout << "Preparing order..." << endl;
}

void Chef::markReady(){
    cout << "Order is ready!" << endl;
}

void Chef::getInfo(){
    Person::getInfo();
    cout << "Specialization : " << specialization << endl;
    cout << "Kitchen Station: " << kitchenStation << endl;
}