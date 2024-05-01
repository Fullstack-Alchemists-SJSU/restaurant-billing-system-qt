#ifndef ORDERCONTROLLER_H
#define ORDERCONTROLLER_H

#include "Order.h"
#include <vector>

class OrderController
{
public:
    OrderController();

    void createOrder();
    void addItemToOrder(int orderID, const OrderItem &item);
    void removeItemFromOrder(int orderID, const std::string &itemName);
    void updateItemInOrder(int orderID, const std::string &itemName, int newQuantity);
    void closeOrder(int orderID);
    std::vector<Order>::iterator findOrder(int orderID);

private:
    std::vector<Order> orders; // List of all orders managed by the controller
};

#endif // ORDERCONTROLLER_H
