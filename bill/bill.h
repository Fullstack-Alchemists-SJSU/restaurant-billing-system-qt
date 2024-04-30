// Bill.h
#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <vector>
#include <string>

// Dummy classes till the real classes are added
class Order;
class MenuItem;

class OrderItem {
public:
    MenuItem* menuItem;
    int quantity;

    OrderItem(MenuItem* item, int qty);
    void updateQuantity(int qty);
};

class Order {
public:
    int orderID;
    std::vector<OrderItem> items;
    std::string status;
    double totalPrice;

    Order(int id);
    void addItem(OrderItem item);
    void calculateTotal();
};

class Bill {
public:
    int billID;
    Order* order;
    std::string date;
    double totalAmount;

    Bill(int id, Order* ord, const std::string& billDate);
    void generateBill();
    void printBill();
};

#endif // BILL_H
