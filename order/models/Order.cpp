#include "Order.h"
#include <algorithm>

int Order::nextOrderID = 1;

// Constructor that sets a specific order ID, use for deserialization/loading
Order::Order(int id) : orderID(id), status("Open") {
    if (id >= nextOrderID) {
        nextOrderID = id + 1;
    }
}

// Default constructor for creating new orders with unique IDs
Order::Order() : orderID(nextOrderID++), status("Open") {
    // Automatically increment to the next ID
}

// Custom copy constructor
Order::Order(const Order& other) : orderID(other.orderID), status(other.status) {
    for (OrderItem* item : other.items) {
        items.push_back(new OrderItem(*item));
    }
}

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

std::string Order::getStatus() const
{
    return status;
}

std::vector<OrderItem *> Order::getItems(){
    return items;
}

size_t Order::getItemCount() const {
    return items.size();
}
