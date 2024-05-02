#ifndef ORDERMANAGEMENTFACADE_H
#define ORDERMANAGEMENTFACADE_H

#include "./models/Order.h"
#include "./models/OrderItem.h"
#include "./controllers/OrderController.h"

class OrderManagementFacade
{
public:
    OrderManagementFacade();

    int createOrder();
    void addItemToOrder(int orderID, const std::string &itemName, double price, int quantity);
    void removeItemFromOrder(int orderID, const std::string &itemName);
    void updateItemInOrder(int orderID, const std::string &itemName, int newQuantity);
    void closeOrder(int orderID);
    std::vector<Order*> getOrders();
    std::vector<std::string> getOrderSummaries() const;

private:
    OrderController orderController; // The OrderController instance to handle order management
};

#endif // ORDERMANAGEMENTFACADE_H
