#include "Order.h"

Order::Order(){
    orderId = 0;
    customerId = 0;
    tableNumber = 0;
    status = "placed";
    tax = 0.14;
    discount = 0.0;
}

Order::Order(int oid, int cid, int table){
    orderId = oid;
    customerId = cid;
    tableNumber = table;
    status = "placed";
    tax = 0.14;
    discount = 0.0;
}

void Order::addItem(int itemId, int qty, double price){
    itemIds.push_back(itemId);
    quantities.push_back(qty);
    prices.push_back(price);
    cout << "Item " << itemId << " added to order." << endl;
}

void Order::removeItem(int itemId){
    bool found = false;
    for(int i = 0; i < itemIds.size(); i++){
        if(itemIds[i] == itemId){
            itemIds.erase(itemIds.begin() + i);
            quantities.erase(quantities.begin() + i);
            prices.erase(prices.begin() + i);
            cout << "Item " << itemId << " removed from order." << endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Item not found in order." << endl;
    }
}

void Order::updateStatus(string newStatus){
    status = newStatus;
    cout << "Order " << orderId << " status updated to: " << status << endl;
}

void Order::setDiscount(double d){
    discount = d;
}

void Order::viewOrder(){
    cout << "\n---- Order ID: " << orderId << " ----" << endl;
    cout << "Customer ID : " << customerId << endl;
    cout << "Table       : " << tableNumber << endl;
    cout << "Status      : " << status << endl;
    cout << "Items:" << endl;
    for(int i = 0; i < itemIds.size(); i++){
        cout << "  - Item ID: " << itemIds[i]
             << "  Qty: " << quantities[i]
             << "  Price: " << prices[i] << "$" << endl;
    }
}

void Order::generateBill(){
    double subtotal = 0;
    cout << "\n======= BILL =======" << endl;
    cout << "Order ID : " << orderId << endl;
    cout << "Table    : " << tableNumber << endl;
    cout << "Items:" << endl;
    for(int i = 0; i < itemIds.size(); i++){
        double lineTotal = quantities[i] * prices[i];
        cout << "  Item ID: " << itemIds[i]
             << "  x" << quantities[i]
             << "  = " << lineTotal << "$" << endl;
        subtotal += lineTotal;
    }
    cout << "--------------------" << endl;
    cout << "Subtotal : " << subtotal << "$" << endl;
    double discountAmount = subtotal * discount;
    double afterDiscount = subtotal - discountAmount;
    double taxAmount = afterDiscount * tax;
    double total = afterDiscount + taxAmount;
    if(discount > 0){
        cout << "Discount (" << discount * 100 << "%) : -" << discountAmount << "$" << endl;
    }
    cout << "Tax (14%)  : +" << taxAmount << "$" << endl;
    cout << "--------------------" << endl;
    cout << "TOTAL    : " << total << "$" << endl;
    cout << "====================" << endl;
}

int Order::getOrderId(){
    return orderId;
}

int Order::getCustomerId(){
    return customerId;
}

int Order::getTableNumber(){
    return tableNumber;
}

string Order::getStatus(){
    return status;
}

bool Order::isEmpty(){
    return itemIds.size() == 0;
}