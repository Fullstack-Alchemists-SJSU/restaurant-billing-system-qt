#include "OrderController.h"
#include <algorithm>
#include <stdexcept>
#include <sstream>

OrderController::OrderController() {}

int OrderController::createOrder()
{
    orders.emplace_back();
    return orders.back().getOrderID();
}

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

std::vector<std::string> OrderController::getOrderSummaries() const
{
    std::vector<std::string> summaries;
    for (const Order &order : orders)
    {
        std::stringstream ss;
        ss << "Order ID: " << order.getOrderID()
           << ", Status: " << order.getStatus()
           << ", Total: $" << order.getTotalPrice();
        summaries.push_back(ss.str());
    }
    return summaries;
}

std::vector<Order>::iterator OrderController::findOrder(int orderID)
{
    auto it = std::find_if(orders.begin(), orders.end(), [orderID](const Order &order)
                           { return order.getOrderID() == orderID; });
    if (it == orders.end())
    {
        throw std::runtime_error("Order not found.");
    }
    return it;
}
