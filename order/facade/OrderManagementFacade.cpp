#include "OrderManagementFacade.h"
#include "../menu/MenuController.h"
#include <iostream>
#include <QDebug>
#include <fstream>
#include "../util/Constants.h"

OrderManagementFacade::OrderManagementFacade() : nextOrderId(1) {
    MenuController* menuController = new MenuController();
    this->menu = menuController->getMenuItems(Constants::MENU_FILE);
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

void OrderManagementFacade::loadOrdersFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        OrderAdapter adapter;
        while (std::getline(file, line)) {
            try {
                Order order = adapter.deserialize(line);
                orders.push_back(new Order(order));
            } catch (const std::runtime_error &e) {
                std::cerr << "Error deserializing order: " << e.what() << std::endl;
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
}
