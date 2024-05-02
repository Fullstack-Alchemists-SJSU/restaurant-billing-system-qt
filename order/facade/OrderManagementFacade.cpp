#include "OrderManagementFacade.h"

OrderManagementFacade::OrderManagementFacade() : orderController() {}

int OrderManagementFacade::createOrder()
{
    return orderController.createOrder();
}

void OrderManagementFacade::addItemToOrder(int orderID, const std::string &itemName, double price, int quantity)
{
    OrderItem item(itemName, price, quantity);
    orderController.addItemToOrder(orderID, item);
}

void OrderManagementFacade::removeItemFromOrder(int orderID, const std::string &itemName)
{
    orderController.removeItemFromOrder(orderID, itemName);
}

void OrderManagementFacade::updateItemInOrder(int orderID, const std::string &itemName, int newQuantity)
{
    orderController.updateItemInOrder(orderID, itemName, newQuantity);
}

void OrderManagementFacade::closeOrder(int orderID)
{
    orderController.closeOrder(orderID);
}

std::vector<std::string> OrderManagementFacade::getOrderSummaries() const
{
    return orderController.getOrderSummaries();
}

std::vector<Order*> OrderManagementFacade::getOrders(){
    return orderController.getOrders();
}
