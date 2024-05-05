#include "OrderAdapter.h"
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include "../menu/Menu.h"

std::string OrderAdapter::serialize(const Order &order)
{
    std::ostringstream oss;
    oss << order.getOrderID() << "," << order.getStatus();

    order.forEachItem([&oss](const OrderItem &item)
                      { oss << "," << item.getMenuItem()->getName() << ";" << item.getQuantity(); });

    return oss.str();
}

Order OrderAdapter::deserialize(const std::string &csvLine)
{
    std::istringstream ss(csvLine);
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(ss, segment, ','))
    {
        seglist.push_back(segment);
    }

    if (seglist.size() < 3) // Ensure at least ID, status, and one item are present
        throw std::runtime_error("CSV format error");

    int orderID = std::stoi(seglist[0]);
    std::string status = seglist[1];

    Order order(orderID);

    Menu menu;

    for (size_t i = 3; i < seglist.size(); ++i)
    {
        std::istringstream itemStream(seglist[i]);
        std::string itemName;
        std::getline(itemStream, itemName, ';');
        int quantity;
        itemStream >> quantity;

        auto it = menu.findItemByName(itemName);
        if (it != menu.getMenuItems().end())
        {
            OrderItem *orderItem = new OrderItem(&(*it), quantity); // &(*it) gets the address of the item pointed by iterator
            order.addItem(orderItem);
        }
        else
        {
            std::cerr << "MenuItem not found during deserialization: " << itemName << std::endl;
        }
    }

    return order;
}
