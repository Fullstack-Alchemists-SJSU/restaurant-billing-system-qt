#include "OrderAdapter.h"
#include <sstream>
#include <stdexcept>
#include <iostream>
#include "../menu/Menu.h"

std::string OrderAdapter::serialize(const Order &order) {
    std::ostringstream oss;
    oss << order.getOrderID() << "," << order.getStatus();

    order.forEachItem([&oss](const OrderItem &item) {
        oss << "," << item.getMenuItem()->getName() << ";"
            << item.getMenuItem()->getPrice() << ";"
            << item.getQuantity();
    });

    return oss.str();
}

Order OrderAdapter::deserialize(const std::string &csvLine) {
    std::istringstream ss(csvLine);
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(ss, segment, ',')) {
        seglist.push_back(segment);
    }

    if (seglist.size() < 3)
        throw std::runtime_error("CSV format error");

    int orderID = std::stoi(seglist[0]);
    std::string status = seglist[1];

    Order order(orderID);
    order.setStatus(status);

    for (size_t i = 2; i < seglist.size(); ++i) {
        std::istringstream itemStream(seglist[i]);
        std::string itemName, itemPriceStr, itemQuantityStr;

        std::getline(itemStream, itemName, ';');
        std::getline(itemStream, itemPriceStr, ';');
        std::getline(itemStream, itemQuantityStr, ';');

        double itemPrice = std::stod(itemPriceStr);
        int itemQuantity = std::stoi(itemQuantityStr);

        MenuItem *menuItem = new MenuItem(itemName, itemPrice, "", "", Category::MainCourse, {}, Availability::Available);
        OrderItem *orderItem = new OrderItem(menuItem, itemQuantity);
        order.addItem(orderItem);
    }

    return order;
}
