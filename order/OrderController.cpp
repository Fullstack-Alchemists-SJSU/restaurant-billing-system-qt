#include "OrderController.h"
#include <stdexcept> // Include for std::invalid_argument

void OrderController::addItemToOrder(int orderID, const OrderItem &item)
{
    auto it = findOrder(orderID);
    it->addItem(item);
}

void OrderController::removeItemFromOrder(int orderID, const std::string &itemName)
{
    auto it = findOrder(orderID);
    it->removeItem(itemName);
}

void OrderController::updateItemInOrder(int orderID, const std::string &itemName, int newQuantity)
{
    auto it = findOrder(orderID);
    it->updateItem(itemName, newQuantity);
}

void OrderController::closeOrder(int orderID)
{
    auto it = findOrder(orderID);
    it->closeOrder();
}

std::vector<Order>::iterator OrderController::findOrder(int orderID)
{
    auto it = std::find_if(orders.begin(), orders.end(), [orderID](const Order &order)
                           { return order.getOrderID() == orderID; });
    if (it == orders.end())
    {
        throw std::invalid_argument("Order not found.");
    }
    return it;
}
