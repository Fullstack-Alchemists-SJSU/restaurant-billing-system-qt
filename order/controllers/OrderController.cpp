#include "OrderController.h"
#include <iostream>

OrderController::OrderController() : currentOrder(nullptr) {}

void OrderController::setOrder(Order *order)
{
    currentOrder = order;
}

void OrderController::addItemToOrder(MenuItem *menuItem, int quantity)
{
    if (currentOrder && currentOrder->getStatus() == "Open")
    {
        OrderItem *newOrderItem = new OrderItem(menuItem, quantity);
        currentOrder->addItem(newOrderItem);
    }
    else
    {
        std::cerr << "Attempt to add item to a closed or undefined order." << std::endl;
    }
}

void OrderController::removeItemFromOrder(const std::string &menuItemName)
{
    if (currentOrder && currentOrder->getStatus() == "Open")
    {
        currentOrder->removeItem(menuItemName);
    }
    else
    {
        std::cerr << "Attempt to remove item from a closed or undefined order." << std::endl;
    }
}

void OrderController::updateItemInOrder(const std::string &menuItemName, int newQuantity)
{
    if (currentOrder && currentOrder->getStatus() == "Open")
    {
        currentOrder->updateItem(menuItemName, newQuantity);
    }
    else
    {
        std::cerr << "Attempt to update item in a closed or undefined order." << std::endl;
    }
}

void OrderController::closeOrder()
{
    if (currentOrder)
    {
        currentOrder->closeOrder();
    }
    else
    {
        std::cerr << "Attempt to close an undefined order." << std::endl;
    }
}
