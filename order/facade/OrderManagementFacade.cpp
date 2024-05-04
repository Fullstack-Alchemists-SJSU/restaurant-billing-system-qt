#include "OrderManagementFacade.h"
#include <iostream>

OrderManagementFacade::OrderManagementFacade(Menu *menu) : nextOrderId(1), menu(menu) {}

int OrderManagementFacade::createOrder()
{
    Order *newOrder = new Order(nextOrderId++);
    orders[newOrder->getOrderID()] = newOrder;
    orderController.setOrder(newOrder);
    return newOrder->getOrderID();
}

void OrderManagementFacade::addItemToOrder(int orderId, const std::string &menuItemName, int quantity)
{
    if (orders.find(orderId) != orders.end() && menu)
    {
        auto it = menu->findItemByName(menuItemName);
        if (it != menu->getMenuItems().end())
        {
            orderController.addItemToOrder(&(*it), quantity);
        }
        else
        {
            std::cerr << "MenuItem not found: " << menuItemName << std::endl;
        }
    }
}

void OrderManagementFacade::removeItemFromOrder(int orderId, const std::string &menuItemName)
{
    if (orders.find(orderId) != orders.end())
    {
        orderController.removeItemFromOrder(menuItemName);
    }
}

void OrderManagementFacade::updateItemInOrder(int orderId, const std::string &menuItemName, int newQuantity)
{
    if (orders.find(orderId) != orders.end())
    {
        orderController.updateItemInOrder(menuItemName, newQuantity);
    }
}

void OrderManagementFacade::closeOrder(int orderId)
{
    if (orders.find(orderId) != orders.end())
    {
        orderController.closeOrder();
    }
}
