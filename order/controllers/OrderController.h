#ifndef ORDERCONTROLLER_H
#define ORDERCONTROLLER_H

#include "./models/Order.h"
#include <vector>

class OrderController
{
public:
    OrderController();

    int createOrder();
    void addItemToOrder(int orderID, const OrderItem &item);
    void removeItemFromOrder(int orderID, const std::string &itemName);
    void updateItemInOrder(int orderID, const std::string &itemName, int newQuantity);
    void closeOrder(int orderID);
    std::vector<Order*> getOrders();
    std::vector<std::string> getOrderSummaries() const;

private:
    std::vector<Order*> orders; // List of all orders managed by the controller

    Order* findOrder(int orderID);
};

#endif // ORDERCONTROLLER_H