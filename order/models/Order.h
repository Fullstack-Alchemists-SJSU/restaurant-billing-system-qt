#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include "OrderItem.h"

class Order
{
public:
    Order(int id);

    void addItem(OrderItem *item);
    void removeItem(const std::string &menuItemName);
    void updateItem(const std::string &menuItemName, int quantity);
    void closeOrder();

    int getOrderID() const;
    std::string getStatus() const;

private:
    int orderID;
    std::vector<OrderItem *> items;
    std::string status; // Open, Closed, etc.
};

#endif // ORDER_H
