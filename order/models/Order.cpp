#include "Order.h"
#include <algorithm>

Order::Order(int id) : orderID(id), status("Open") {}

void Order::addItem(OrderItem *item)
{
    if (status != "Closed")
    {
        items.push_back(item);
    }
}

void Order::removeItem(const std::string &menuItemName)
{
    if (status != "Closed")
    {
        items.erase(std::remove_if(items.begin(), items.end(),
                                   [&menuItemName](OrderItem *item)
                                   {
                                       return item->getMenuItemName() == menuItemName;
                                   }),
                    items.end());
    }
}

void Order::updateItem(const std::string &menuItemName, int quantity)
{
    if (status != "Closed")
    {
        auto it = std::find_if(items.begin(), items.end(),
                               [&menuItemName](OrderItem *item)
                               {
                                   return item->getMenuItemName() == menuItemName;
                               });
        if (it != items.end())
        {
            (*it)->updateQuantity(quantity);
        }
    }
}

void Order::closeOrder()
{
    status = "Closed";
}

int Order::getOrderID() const
{
    return orderID;
}

std::string Order::getStatus() const
{
    return status;
}
