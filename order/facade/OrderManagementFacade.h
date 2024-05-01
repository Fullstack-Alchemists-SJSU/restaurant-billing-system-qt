#ifndef ORDERMANAGEMENTFACADE_H
#define ORDERMANAGEMENTFACADE_H

#include "OrderController.h"
#include "OrderItem.h"

class OrderManagementFacade
{
public:
    OrderManagementFacade();

    int createOrder();
    void addItemToOrder(int orderID, const std::string &itemName, double price, int quantity);
    void removeItemFromOrder(int orderID, const std::string &itemName);
    void updateItemInOrder(int orderID, const std::string &itemName, int newQuantity);
    void closeOrder(int orderID);
    std::vector<std::string> getOrderSummaries() const;

private:
    OrderController orderController; // The OrderController instance to handle order management
};

#endif // ORDERMANAGEMENTFACADE_H
