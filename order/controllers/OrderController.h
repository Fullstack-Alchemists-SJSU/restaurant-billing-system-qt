#ifndef ORDERCONTROLLER_H
#define ORDERCONTROLLER_H

#include "../models/Order.h"

class OrderController
{
public:
    OrderController();

    void setOrder(Order *order);
    void addItemToOrder(MenuItem *menuItem, int quantity);
    void removeItemFromOrder(const std::string &menuItemName);
    void updateItemInOrder(const std::string &menuItemName, int newQuantity);
    void closeOrder();

private:
    Order *currentOrder; // Pointer to the current order being managed
};

#endif // ORDERCONTROLLER_H
