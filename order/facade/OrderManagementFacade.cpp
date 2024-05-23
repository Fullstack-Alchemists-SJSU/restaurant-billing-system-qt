#include "OrderManagementFacade.h"
#include "../menu/MenuController.h"
#include <iostream>
#include <QDebug>

OrderManagementFacade::OrderManagementFacade() : nextOrderId(1) {
    MenuController* menuController = new MenuController();
    this->menu = menuController->getMenuItems("C:/Users/patil/CMPE202/restaurant-billing-system/restaurant-billing-system-qt/db/menuitems.csv");
}

int OrderManagementFacade::createOrder()
{
    Order *newOrder = new Order(nextOrderId++);
    orders.push_back(newOrder);
    orderController.setOrder(newOrder);
    return newOrder->getOrderID();
}

void OrderManagementFacade::addItemToOrder(int orderId, const std::string &menuItemName, int quantity)
{
    if (orderExists(orderId) && menu)
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
    if (orderExists(orderId))
    {
        orderController.removeItemFromOrder(menuItemName);
    }
}

void OrderManagementFacade::updateItemInOrder(int orderId, const std::string &menuItemName, int newQuantity)
{
    if (orderExists(orderId))
    {
        orderController.updateItemInOrder(menuItemName, newQuantity);
    }
}

void OrderManagementFacade::closeOrder(int orderId)
{
    if (orderExists(orderId))
    {
        orderController.closeOrder();
    }
}

std::vector<Order *> OrderManagementFacade::getOrders(){
    return orders;
}

Menu* OrderManagementFacade::getMenu(){
    return this->menu;
}
