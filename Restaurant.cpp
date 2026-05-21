#include "Restaurant.h"

Restaurant::Restaurant(){
    nextOrderId = 1;
    for(int i = 1; i <= 20; i++){
        tableNumbers.push_back(i);
        tableAvailable.push_back(true);
        tableCustomerIds.push_back(0);
    }
}

Restaurant::~Restaurant(){
    for(int i = 0; i < staff.size(); i++){
        delete staff[i];
    }
    for(int i = 0; i < customers.size(); i++){
        delete customers[i];
    }
}

void Restaurant::addCategory(string name){
    Category c;
    c.setCategory(name);
    menu.push_back(c);
}

bool Restaurant::exists(int id){
    for(int i = 0; i < staff.size(); i++){
        if(staff[i]->getId() == id){
            return true;
        }
    }
    return false;
}

bool Restaurant::customerExists(int id){
    for(int i = 0; i < customers.size(); i++){
        if(customers[i]->getId() == id){
            return true;
        }
    }
    return false;
}

void Restaurant::addMenuItem(int categoryIndex, int itemId, string itemName, double price){
    if(categoryIndex < menu.size()){
        menu[categoryIndex].addItem(itemId, itemName, price);
    }
}

void Restaurant::addStaff(Person* p){
    staff.push_back(p);
}

void Restaurant::removeStaff(int id){
    int index = -1;
    for(int i = 0; i < staff.size(); i++){
        if(staff[i]->getId() == id){
            index = i;
            break;
        }
    }
    if(index != -1){
        delete staff[index];
        staff.erase(staff.begin() + index);
        cout << "Staff member with ID " << id << " removed successfully." << endl;
    } else {
        cout << "Error, Staff ID not found!" << endl;
    }
}

void Restaurant::viewStaff(){
    if(staff.size() == 0){
        cout << "No staff found." << endl;
        return;
    }
    for(int i = 0; i < staff.size(); i++){
        cout << "=======================" << endl;
        staff[i]->getInfo();
    }
    cout << "=======================" << endl;
}

void Restaurant::viewChefs(){
    bool found = false;
    for(int i = 0; i < staff.size(); i++){
        if(dynamic_cast<Chef*>(staff[i]) != nullptr){
            cout << "=======================" << endl;
            staff[i]->getInfo();
            found = true;
        }
    }
    if(!found){
        cout << "No chefs found." << endl;
        return;
    }
    cout << "=======================" << endl;
}

void Restaurant::viewWaiters(){
    bool found = false;
    for(int i = 0; i < staff.size(); i++){
        if(dynamic_cast<Waiter*>(staff[i]) != nullptr){
            cout << "=======================" << endl;
            staff[i]->getInfo();
            found = true;
        }
    }
    if(!found){
        cout << "No waiters found." << endl;
        return;
    }
    cout << "=======================" << endl;
}

void Restaurant::searchStaff(int id){
    bool found = false;
    for(int i = 0; i < staff.size(); i++){
        if(staff[i]->getId() == id){
            cout << "---- Staff Found ----" << endl;
            staff[i]->getInfo();
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Error, Staff ID " << id << " not found!" << endl;
    }
}

void Restaurant::viewMenu(){
    for(int i = 0; i < menu.size(); i++){
        menu[i].showCategory();
    }
}

void Restaurant::searchMenuItem(int id){
    for(int i = 0; i < menu.size(); i++){
        menu[i].findItem(id);
    }
    if(!menuItemExists(id)){
        cout<<"Error, Item ID Was Not Found!"<<endl;
    }
}

bool Restaurant::menuItemExists(int id){
    for(int i = 0; i < menu.size(); i++){
        if(menu[i].itemExists(id)){
            return true;
        }
    }
    return false;
}

double Restaurant::getMenuItemPrice(int id){
    for(int i = 0; i < menu.size(); i++){
        double p = menu[i].getItemPrice(id);
        if(p != -1){
            return p;
        }
    }
    return -1;
}

void Restaurant::searchMenuItemByName(string name){
    bool found = false;
    for(int i = 0; i < menu.size(); i++){
        if(menu[i].itemExistsByName(name)){
            menu[i].findItemByName(name);
            found = true;
        }
    }
    if(!found){
        cout << "Error, Item Name Was Not Found!" << endl;
    }
}

void Restaurant::searchMenuItemByCategory(string categoryName){
    bool found = false;
    for(int i = 0; i < menu.size(); i++){
        if(menu[i].getCategoryName() == categoryName){
            menu[i].showCategory();
            found = true;
        }
    }
    if(!found){
        cout << "Error, Category Not Found!" << endl;
    }
}

void Restaurant::updateMenuItem(int id, string newName, double newPrice, bool newAvailability){
    bool found = false;
    for(int i = 0; i < menu.size(); i++){
        if(menu[i].updateItem(id, newName, newPrice, newAvailability)){
            cout << "Item ID " << id << " updated successfully!" << endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Error, Item ID " << id << " not found!" << endl;
    }
}

void Restaurant::removeItemFromMenu(int id){
    bool found = false;
    for(int i = 0; i < menu.size(); i++){
        if(menu[i].removeItem(id)){
            found = true;
            cout << "Item With ID : " << id << " Removed from category." << endl;
            break;
        }
    }
    if(!found){
        cout << "Error, No matching ID. Please check Item ID and try again!" << endl;
    }
}

void Restaurant::addCustomer(Customer* c){
    customers.push_back(c);
}

void Restaurant::searchCustomer(int id){
    bool found = false;
    for(int i = 0; i < customers.size(); i++){
        if(customers[i]->getId() == id){
            cout << "Customer Found:" << endl;
            customers[i]->getInfo();
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Error, Customer with ID " << id << " not found." << endl;
    }
}

void Restaurant::viewCustomerHistory(int id){
    bool found = false;
    for(int i = 0; i < customers.size(); i++){
        if(customers[i]->getId() == id){
            cout << "---- Order History for Customer ID " << id << " ----" << endl;
            customers[i]->viewHistory();
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Error, Customer with ID " << id << " not found." << endl;
    }
}

void Restaurant::viewCustomers(){
    if(customers.size() == 0){
        cout << "No customers found." << endl;
        return;
    }
    for(int i = 0; i < customers.size(); i++){
        cout << "=======================" << endl;
        customers[i]->getInfo();
    }
    cout << "=======================" << endl;
}

int Restaurant::createOrder(int customerId, int tableNumber){
    Order newOrder(nextOrderId, customerId, tableNumber);
    orders.push_back(newOrder);
    nextOrderId++;
    cout << "Order #" << nextOrderId - 1 << " created for Customer ID " << customerId << endl;
    return nextOrderId - 1;
}

void Restaurant::addItemToOrder(int orderId, int itemId, int qty){
    double price = getMenuItemPrice(itemId);
    if(price == -1){
        cout << "Error: Item ID " << itemId << " not found in menu!" << endl;
        return;
    }
    for(int i = 0; i < orders.size(); i++){
        if(orders[i].getOrderId() == orderId){
            orders[i].addItem(itemId, qty, price);
            return;
        }
    }
    cout << "Error: Order ID " << orderId << " not found." << endl;
}

void Restaurant::removeItemFromOrder(int orderId, int itemId){
    for(int i = 0; i < orders.size(); i++){
        if(orders[i].getOrderId() == orderId){
            orders[i].removeItem(itemId);
            return;
        }
    }
    cout << "Error: Order ID " << orderId << " not found." << endl;
}

void Restaurant::advanceOrderStatus(int orderId){
    for(int i = 0; i < orders.size(); i++){
        if(orders[i].getOrderId() == orderId){
            string current = orders[i].getStatus();
            if(current == "placed"){
                orders[i].updateStatus("preparing");
            } else if(current == "preparing"){
                orders[i].updateStatus("served");
            } else {
                cout << "Order is already served." << endl;
            }
            return;
        }
    }
    cout << "Order ID " << orderId << " not found." << endl;
}

void Restaurant::viewOrder(int orderId){
    for(int i = 0; i < orders.size(); i++){
        if(orders[i].getOrderId() == orderId){
            orders[i].viewOrder();
            return;
        }
    }
    cout << "Order ID " << orderId << " not found." << endl;
}

void Restaurant::searchOrdersByTable(int tableNumber){
    bool found = false;
    for(int i = 0; i < orders.size(); i++){
        if(orders[i].getTableNumber() == tableNumber){
            orders[i].viewOrder();
            found = true;
        }
    }
    if(!found){
        cout << "Error, No orders found for table " << tableNumber << "." << endl;
    }
}

void Restaurant::viewAllOrders(){
    if(orders.size() == 0){
        cout << "No orders found." << endl;
        return;
    }
    for(int i = 0; i < orders.size(); i++){
        orders[i].viewOrder();
    }
}

void Restaurant::generateOrderBill(int orderId){
    for(int i = 0; i < orders.size(); i++){
        if(orders[i].getOrderId() == orderId){
            if(orders[i].isEmpty()){
                cout << "Order has no items. Cannot generate bill." << endl;
                return;
            }
            int loyaltyChoice;
            cout << "Apply loyalty discount? 1-Yes | 0-No : ";
            cin >> loyaltyChoice;
            if(loyaltyChoice == 1){
                orders[i].setDiscount(0.10);
                cout << "10% loyalty discount applied!" << endl;
            }
            orders[i].generateBill();
            return;
        }
    }
    cout << "Order ID " << orderId << " not found." << endl;
}

int Restaurant::getMenuSize(){
    return menu.size();
}

void Restaurant::viewTables(){
    for(int i = 0; i < tableNumbers.size(); i++){
        cout << "Table " << tableNumbers[i]
             << " | Available: " << (tableAvailable[i] ? "Yes" : "No");
        if(!tableAvailable[i]){
            cout << " | Customer ID: " << tableCustomerIds[i];
        }
        cout << endl;
    }
}

void Restaurant::setTableAvailability(int tableNumber, bool available){
    for(int i = 0; i < tableNumbers.size(); i++){
        if(tableNumbers[i] == tableNumber){
            tableAvailable[i] = available;
            cout << "Table " << tableNumber << " availability set to: " << (available ? "Available" : "Unavailable") << endl;
            return;
        }
    }
    cout << "Error, Table " << tableNumber << " not found!" << endl;
}

void Restaurant::occupyTable(int tableNumber, int customerId){
    for(int i = 0; i < tableNumbers.size(); i++){
        if(tableNumbers[i] == tableNumber){
            if(!tableAvailable[i]){
                cout << "Error, Table " << tableNumber << " is already occupied!" << endl;
                return;
            }
            tableAvailable[i] = false;
            tableCustomerIds[i] = customerId;
            cout << "Table " << tableNumber << " assigned to Customer ID " << customerId << endl;
            return;
        }
    }
    cout << "Error, Table " << tableNumber << " not found!" << endl;
}

void Restaurant::clearTable(int tableNumber){
    for(int i = 0; i < tableNumbers.size(); i++){
        if(tableNumbers[i] == tableNumber){
            tableAvailable[i] = true;
            tableCustomerIds[i] = 0;
            cout << "Table " << tableNumber << " cleared and is now available." << endl;
            return;
        }
    }
    cout << "Error, Table " << tableNumber << " not found!" << endl;
}

void Restaurant::updateCustomerTable(int customerId, int newTable){
    for(int i = 0; i < customers.size(); i++){
        if(customers[i]->getId() == customerId){
            int oldTable = customers[i]->getTable();
            clearTable(oldTable);
            occupyTable(newTable, customerId);
            customers[i]->setTable(newTable);
            cout << "Customer ID " << customerId << " moved to Table " << newTable << endl;
            return;
        }
    }
    cout << "Error, Customer ID " << customerId << " not found!" << endl;
}

void Restaurant::checkoutTable(int tableNumber){
    clearTable(tableNumber);
}