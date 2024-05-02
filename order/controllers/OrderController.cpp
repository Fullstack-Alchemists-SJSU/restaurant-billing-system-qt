#include "OrderController.h"
#include <algorithm>
#include <stdexcept>
#include <sstream>

OrderController::OrderController() {}

int OrderController::createOrder()
{
    orders.emplace_back(new Order());
    return orders.back()->getOrderID();
}

void OrderController::addItemToOrder(int orderID, const OrderItem &item)
{
    Order* it = findOrder(orderID);
    it->addItem(item);
}

void OrderController::removeItemFromOrder(int orderID, const std::string &itemName)
{
    Order* it = findOrder(orderID);
    it->removeItem(itemName);
}

void OrderController::updateItemInOrder(int orderID, const std::string &itemName, int newQuantity)
{
    Order* it = findOrder(orderID);
    it->updateItem(itemName, newQuantity);
}

void OrderController::closeOrder(int orderID)
{
    Order* it = findOrder(orderID);
    it->closeOrder();
}

std::vector<std::string> OrderController::getOrderSummaries() const
{
    std::vector<std::string> summaries;
    for (const Order *order : orders)
    {
        std::stringstream ss;
        ss << "Order ID: " << order->getOrderID()
           << ", Status: " << order->getStatus()
           << ", Total: $" << order->getTotalPrice();
        summaries.push_back(ss.str());
    }
    return summaries;
}

Order* OrderController::findOrder(int orderID)
{

    for(Order* order : orders){
        if(order->getOrderID() == orderID){
            return order;
        }
    }

    return nullptr;
}

std::vector<Order*> OrderController::getOrders(){
    return orders;
}
