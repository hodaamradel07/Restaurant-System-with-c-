#include <iostream>
#include <string>
#include <vector>
#include "Restaurant.h"
#include "Chef.h"
#include "Waiter.h"
#include "Customer.h"
using namespace std;

int main() {
    Restaurant myRestaurant;

    myRestaurant.addCategory("Main Dish");
    myRestaurant.addCategory("Appetizer");
    myRestaurant.addCategory("Drink");

    myRestaurant.addMenuItem(0, 1, "Meat", 300);
    myRestaurant.addMenuItem(0, 2, "Fish", 330);
    myRestaurant.addMenuItem(0, 3, "Sea food", 420);
    myRestaurant.addMenuItem(0, 4, "Pizza", 220);
    myRestaurant.addMenuItem(0, 5, "Chicken", 350);
    myRestaurant.addMenuItem(0, 6, "Vegetarian", 180);

    myRestaurant.addMenuItem(1, 11, "Bread", 15);
    myRestaurant.addMenuItem(1, 12, "Soup", 80);
    myRestaurant.addMenuItem(1, 13, "Fries", 35);
    myRestaurant.addMenuItem(1, 14, "Cheese", 40);
    myRestaurant.addMenuItem(1, 15, "Salad", 25);

    myRestaurant.addMenuItem(2, 21, "Pepsi", 20);
    myRestaurant.addMenuItem(2, 22, "Mint", 15);
    myRestaurant.addMenuItem(2, 23, "Coffee", 25);
    myRestaurant.addMenuItem(2, 24, "Orange", 30);
    myRestaurant.addMenuItem(2, 25, "Lemon", 20);

    Chef* chef1 = new Chef("Chef Mustafa", 45, "mustafa@kitchen.com", 101, "Main Dishes", "Station A");
    Chef* chef2 = new Chef("Chef Sarah", 32, "sarah@pastry.com", 102, "Desserts", "Station B");
    Chef* chef3 = new Chef("Chef Ahmed", 42, "ahmed@grill.com", 103, "Grilled Items", "Station C");
    Waiter* waiter1 = new Waiter("Hassan", 29, "hassan@floor.com", 201, "Morning");
    Waiter* waiter2 = new Waiter("Mona", 26, "mona@floor.com", 202, "Evening");
    Waiter* waiter3 = new Waiter("Ali", 31, "ali@service.com", 203, "Night");

    myRestaurant.addStaff(chef1);
    myRestaurant.addStaff(chef2);
    myRestaurant.addStaff(chef3);
    myRestaurant.addStaff(waiter1);
    myRestaurant.addStaff(waiter2);
    myRestaurant.addStaff(waiter3);

    int password = 123;
    int username = 123;
    int pass, user;
    int askMood = -1;

    while(askMood != 0){
        cout << "\n--- WELCOME TO OUR RESTAURANT ---" << endl;
        cout << "=================================" << endl;
        cout << "1. CUSTOMER MODE  (PLACE ORDERS)   : " << endl;
        cout << "2. MANAGER MODE   (ADMINISTRATION) : " << endl;
        cout << "0. EXIT" << endl;
        cin >> askMood;

        // ========== MANAGER MODE ==========
        if(askMood == 2){
            cout << "------ MANAGER LOGIN REQUIRED -------" << endl;
            cout << "USER NAME : ";
            cin >> user;
            cout << "PASSWORD  : ";
            cin >> pass;

            if(user == username && pass == password){
                int adminChoice = -1;
                while(adminChoice != 0){
                    cout << "\n----- ADMIN PANEL -----" << endl;
                    cout << "1. MANAGE CHEFS   (VIEW, SEARCH, ADD, REMOVE) : " << endl;
                    cout << "2. MANAGE WAITERS (VIEW, SEARCH, ADD, REMOVE) : " << endl;
                    cout << "3. MANAGE MENU    (VIEW, SEARCH, ADD, REMOVE, UPDATE) : " << endl;
                    cout << "4. MANAGE ORDERS  (VIEW, SEARCH BY TABLE, STATUS, BILL) : " << endl;
                    cout << "5. MANAGE CUSTOMERS (VIEW, SEARCH, HISTORY)           : " << endl;
                    cout << "6. MANAGE TABLES  (VIEW, ASSIGN, CLEAR, AVAILABILITY) : " << endl;
                    cout << "0. BACK TO MAIN MENU" << endl;
                    cin >> adminChoice;

                    // ---- Manage Chefs ----
                    if(adminChoice == 1){
                        cout << "----- WHAT DO YOU WISH TO DO ? -----" << endl;
                        cout << "1. VIEW CHEF LIST        : " << endl;
                        cout << "2. SEARCH CHEF BY ID     : " << endl;
                        cout << "3. ADD CHEF TO LIST      : " << endl;
                        cout << "4. REMOVE CHEF FROM LIST : " << endl;
                        int askChef;
                        cin >> askChef;

                        if(askChef == 1){
                            cout << "---- CHEF LIST ----" << endl;
                            myRestaurant.viewChefs();
                        }
                        else if(askChef == 2){
                            int chefId;
                            cout << "Enter Chef ID : ";
                            cin >> chefId;
                            myRestaurant.searchStaff(chefId);
                        }
                        else if(askChef == 3){
                            int i;
                            cout << "Enter ID: ";
                            cin >> i;
                            if(myRestaurant.exists(i)){
                                cout << "Error, A staff member already exists with this ID!" << endl;
                            } else {
                                string n, c, spec, stat;
                                int a;
                                cin.ignore();
                                cout << "Enter Name: ";
                                getline(cin, n);
                                cout << "Enter Age: ";
                                cin >> a;
                                cin.ignore();
                                cout << "Enter Contact Info: ";
                                getline(cin, c);
                                cout << "Enter Specialization: ";
                                getline(cin, spec);
                                cout << "Enter Kitchen Station: ";
                                getline(cin, stat);
                                Chef* newChef = new Chef(n, a, c, i, spec, stat);
                                myRestaurant.addStaff(newChef);
                                cout << "Chef added successfully!" << endl;
                            }
                        }
                        else if(askChef == 4){
                            int idToRemove;
                            cout << "Enter the ID of the Chef to remove: ";
                            cin >> idToRemove;
                            myRestaurant.removeStaff(idToRemove);
                        }
                        else {
                            cout << "Error, invalid input!" << endl;
                        }
                    }

                    // ---- Manage Waiters ----
                    else if(adminChoice == 2){
                        cout << "----- WHAT DO YOU WISH TO DO ? -----" << endl;
                        cout << "1. VIEW WAITERS LIST        : " << endl;
                        cout << "2. SEARCH WAITER BY ID      : " << endl;
                        cout << "3. ADD WAITER TO LIST       : " << endl;
                        cout << "4. REMOVE WAITER FROM LIST  : " << endl;
                        int askWaiter;
                        cin >> askWaiter;

                        if(askWaiter == 1){
                            cout << "---- WAITER LIST ----" << endl;
                            myRestaurant.viewWaiters();
                        }
                        else if(askWaiter == 2){
                            int waiterId;
                            cout << "Enter Waiter ID : ";
                            cin >> waiterId;
                            myRestaurant.searchStaff(waiterId);
                        }
                        else if(askWaiter == 3){
                            int i;
                            cout << "Enter ID: ";
                            cin >> i;
                            if(myRestaurant.exists(i)){
                                cout << "Error, A staff member already exists with this ID!" << endl;
                            } else {
                                string n, c, s;
                                int a;
                                cin.ignore();
                                cout << "Enter Name: ";
                                getline(cin, n);
                                cout << "Enter Age: ";
                                cin >> a;
                                cin.ignore();
                                cout << "Enter Contact Info: ";
                                getline(cin, c);
                                cout << "Enter Shift: ";
                                getline(cin, s);
                                Waiter* newWaiter = new Waiter(n, a, c, i, s);
                                myRestaurant.addStaff(newWaiter);
                                cout << "Waiter added successfully!" << endl;
                            }
                        }
                        else if(askWaiter == 4){
                            int idToRemove;
                            cout << "Enter the ID of the Waiter to remove: ";
                            cin >> idToRemove;
                            myRestaurant.removeStaff(idToRemove);
                        }
                        else {
                            cout << "Error, invalid input!" << endl;
                        }
                    }

                    // ---- Manage Menu ----
                    else if(adminChoice == 3){
                        cout << "----- WHAT DO YOU WISH TO DO ? -----" << endl;
                        cout << "1. VIEW MENU LIST           : " << endl;
                        cout << "2. SEARCH ITEM BY ID        : " << endl;
                        cout << "3. SEARCH ITEM BY NAME      : " << endl;
                        cout << "4. SEARCH ITEMS BY CATEGORY : " << endl;
                        cout << "5. ADD ITEM TO LIST         : " << endl;
                        cout << "6. REMOVE ITEM FROM LIST    : " << endl;
                        cout << "7. UPDATE MENU ITEM         : " << endl;
                        int askMenu;
                        cin >> askMenu;

                        if(askMenu == 1){
                            cout << "---- RESTAURANT MENU ----" << endl;
                            myRestaurant.viewMenu();
                        }
                        else if(askMenu == 2){
                            int searchId;
                            cout << "Enter Item ID To Search: ";
                            cin >> searchId;
                            myRestaurant.searchMenuItem(searchId);
                        }
                        else if(askMenu == 3){
                            string searchName;
                            cout << "Enter Item Name To Search: ";
                            cin.ignore();
                            getline(cin, searchName);
                            myRestaurant.searchMenuItemByName(searchName);
                        }
                        else if(askMenu == 4){
                            string searchCategory;
                            cout << "Enter Category Name (Main Dish / Appetizer / Drink): ";
                            cin.ignore();
                            getline(cin, searchCategory);
                            myRestaurant.searchMenuItemByCategory(searchCategory);
                        }
                        else if(askMenu == 5){
                            int cat, id;
                            double price;
                            string name;
                            cout << "Choose category: 0-Main Dish | 1-Appetizer | 2-Drinks : ";
                            cin >> cat;
                            if(cat >= 0 && cat <= 2){
                                cout << "Enter Item ID: ";
                                cin >> id;
                                cout << "Enter Item Name: ";
                                cin.ignore();
                                getline(cin, name);
                                cout << "Enter Item Price: ";
                                cin >> price;
                                myRestaurant.addMenuItem(cat, id, name, price);
                                cout << "Item added to category successfully!" << endl;
                            }
                            else {
                                cout << "Error, invalid category!" << endl;
                            }
                        }
                        else if(askMenu == 6){
                            int idToRemove;
                            cout << "Enter ID of the item to remove: ";
                            cin >> idToRemove;
                            myRestaurant.removeItemFromMenu(idToRemove);
                        }
                        else if(askMenu == 7){
                            int id, avail;
                            double newPrice;
                            string newName;
                            cout << "Enter Item ID to update: ";
                            cin >> id;
                            cout << "Enter New Name: ";
                            cin.ignore();
                            getline(cin, newName);
                            cout << "Enter New Price: ";
                            cin >> newPrice;
                            cout << "Available? 1-Yes | 0-No : ";
                            cin >> avail;
                            myRestaurant.updateMenuItem(id, newName, newPrice, avail == 1);
                        }
                        else {
                            cout << "Error, invalid input!" << endl;
                        }
                    }

                    // ---- Manage Orders ----
                    else if(adminChoice == 4){
                        cout << "----- WHAT DO YOU WISH TO DO ? -----" << endl;
                        cout << "1. VIEW ALL ORDERS          : " << endl;
                        cout << "2. VIEW SPECIFIC ORDER      : " << endl;
                        cout << "3. SEARCH ORDERS BY TABLE   : " << endl;
                        cout << "4. ADVANCE ORDER STATUS     : " << endl;
                        cout << "5. GENERATE BILL FOR ORDER  : " << endl;
                        int askOrder;
                        cin >> askOrder;

                        if(askOrder == 1){
                            myRestaurant.viewAllOrders();
                        }
                        else if(askOrder == 2){
                            int oid;
                            cout << "Enter Order ID: ";
                            cin >> oid;
                            myRestaurant.viewOrder(oid);
                        }
                        else if(askOrder == 3){
                            int tableNum;
                            cout << "Enter Table Number: ";
                            cin >> tableNum;
                            myRestaurant.searchOrdersByTable(tableNum);
                        }
                        else if(askOrder == 4){
                            int oid;
                            cout << "Enter Order ID to advance status: ";
                            cin >> oid;
                            myRestaurant.advanceOrderStatus(oid);
                        }
                        else if(askOrder == 5){
                            int oid;
                            cout << "Enter Order ID to bill: ";
                            cin >> oid;
                            myRestaurant.generateOrderBill(oid);
                        }
                        else {
                            cout << "Error, invalid input!" << endl;
                        }
                    }

                    // ---- Manage Customers ----
                    else if(adminChoice == 5){
                        cout << "----- WHAT DO YOU WISH TO DO ? -----" << endl;
                        cout << "1. VIEW ALL CUSTOMERS       : " << endl;
                        cout << "2. SEARCH CUSTOMER BY ID    : " << endl;
                        cout << "3. VIEW CUSTOMER ORDER HISTORY : " << endl;
                        int askCust;
                        cin >> askCust;

                        if(askCust == 1){
                            myRestaurant.viewCustomers();
                        }
                        else if(askCust == 2){
                            int cid;
                            cout << "Enter Customer ID: ";
                            cin >> cid;
                            myRestaurant.searchCustomer(cid);
                        }
                        else if(askCust == 3){
                            int cid;
                            cout << "Enter Customer ID: ";
                            cin >> cid;
                            myRestaurant.viewCustomerHistory(cid);
                        }
                        else {
                            cout << "Error, invalid input!" << endl;
                        }
                    }

                    // ---- Manage Tables ----
                    else if(adminChoice == 6){
                        cout << "----- WHAT DO YOU WISH TO DO ? -----" << endl;
                        cout << "1. VIEW ALL TABLES              : " << endl;
                        cout << "2. ASSIGN TABLE TO CUSTOMER     : " << endl;
                        cout << "3. CLEAR TABLE (CHECKOUT)       : " << endl;
                        cout << "4. SET TABLE AVAILABILITY       : " << endl;
                        cout << "5. UPDATE CUSTOMER TABLE        : " << endl;
                        int askTable;
                        cin >> askTable;

                        if(askTable == 1){
                            myRestaurant.viewTables();
                        }
                        else if(askTable == 2){
                            int tableNum, custId;
                            cout << "Enter Table Number: ";
                            cin >> tableNum;
                            cout << "Enter Customer ID: ";
                            cin >> custId;
                            myRestaurant.occupyTable(tableNum, custId);
                        }
                        else if(askTable == 3){
                            int tableNum;
                            cout << "Enter Table Number to clear: ";
                            cin >> tableNum;
                            myRestaurant.clearTable(tableNum);
                        }
                        else if(askTable == 4){
                            int tableNum, avail;
                            cout << "Enter Table Number: ";
                            cin >> tableNum;
                            cout << "Set Available? 1-Yes | 0-No : ";
                            cin >> avail;
                            myRestaurant.setTableAvailability(tableNum, avail == 1);
                        }
                        else if(askTable == 5){
                            int custId, newTable;
                            cout << "Enter Customer ID: ";
                            cin >> custId;
                            cout << "Enter New Table Number: ";
                            cin >> newTable;
                            myRestaurant.updateCustomerTable(custId, newTable);
                        }
                        else {
                            cout << "Error, invalid input!" << endl;
                        }
                    }

                    else if(adminChoice != 0){
                        cout << "Error, invalid input!" << endl;
                    }
                }
            } else {
                cout << "Incorrect username or password!" << endl;
            }
        }

        // ========== CUSTOMER MODE ==========
        else if(askMood == 1){
            cout << "\n---- Welcome To Customer Mode ----" << endl;
            string n, c;
            int a, t, i;

            cout << "====================================" << endl;
            cout << "---- Enter Customer Details ----" << endl;
            cout << "Enter Customer Name: ";
            cin >> n;
            cout << "Enter Customer Age: ";
            cin >> a;
            cout << "Enter Customer Contact Info: ";
            cin >> c;
            cout << "Enter Customer ID: ";
            cin >> i;

            if(myRestaurant.customerExists(i)){
                cout << "Customer ID already exists. Loading existing customer." << endl;
            } else {
                cout << "Enter Table Number: ";
                cin >> t;
                Customer* newCust = new Customer(n, a, c, i, t);
                myRestaurant.addCustomer(newCust);
                myRestaurant.occupyTable(t, i);
                cout << "Customer registered successfully!" << endl;
                t = newCust->getTable();

                // Create order for this customer
                int orderId = myRestaurant.createOrder(i, t);

                myRestaurant.viewMenu();

                int custChoice = -1;
                while(custChoice != 0){
                    cout << "\n---- Customer Menu ----" << endl;
                    cout << "1. ADD ITEM TO ORDER      : " << endl;
                    cout << "2. REMOVE ITEM FROM ORDER : " << endl;
                    cout << "3. VIEW MY ORDER          : " << endl;
                    cout << "4. GENERATE BILL          : " << endl;
                    cout << "0. DONE / EXIT            : " << endl;
                    cin >> custChoice;

                    if(custChoice == 1){
                        int itemId, qty;
                        cout << "Enter Item ID: ";
                        cin >> itemId;
                        cout << "Enter Quantity: ";
                        cin >> qty;
                        myRestaurant.addItemToOrder(orderId, itemId, qty);
                        newCust->placeOrder(itemId, qty);
                    }
                    else if(custChoice == 2){
                        int itemId;
                        cout << "Enter Item ID to remove: ";
                        cin >> itemId;
                        myRestaurant.removeItemFromOrder(orderId, itemId);
                    }
                    else if(custChoice == 3){
                        myRestaurant.viewOrder(orderId);
                    }
                    else if(custChoice == 4){
                        myRestaurant.generateOrderBill(orderId);
                    }
                    else if(custChoice != 0){
                        cout << "Error, invalid input!" << endl;
                    }
                }

                cout << "\n---- Final Order Summary ----" << endl;
                newCust->viewHistory();
                myRestaurant.checkoutTable(t);
                cout << "Thank you! Your table has been cleared." << endl;
            }
        }

        else if(askMood != 0){
            cout << "Error, invalid input!" << endl;
        }
    }

    cout << "\nThank you for visiting! Goodbye." << endl;
    return 0;
}