#include "Order.h"
#include <algorithm> // For std::find_if
#include <numeric>   // For std::accumulate
#include <stdexcept> // For std::invalid_argument

int Order::nextOrderID = 1; // Initialize the static ID counter

// Constructor
Order::Order() : orderID(nextOrderID++), status("Open"), totalPrice(0.0) {}

// Adds an item to the order and recalculates the total price
void Order::addItem(const OrderItem &item)
{
    if (status == "Closed")
    {
        throw std::runtime_error("Cannot add item to a closed order.");
    }
    items.push_back(item);
    calculateTotal();
}

// Removes an item from the order based on the item name
void Order::removeItem(const std::string &itemName)
{
    if (status == "Closed")
    {
        throw std::runtime_error("Cannot remove item from a closed order.");
    }
    auto originalSize = items.size();
    items.erase(std::remove_if(items.begin(), items.end(),
                               [&itemName](const OrderItem &item)
                               {
                                   return item.getMenuItemName() == itemName;
                               }),
                items.end());
    if (items.size() == originalSize)
    {
        throw std::runtime_error("Item not found.");
    }
    calculateTotal();
}

// Updates the quantity of an existing item
void Order::updateItem(const std::string &itemName, int newQuantity)
{
    if (status == "Closed")
    {
        throw std::runtime_error("Cannot update item in a closed order.");
    }
    auto it = std::find_if(items.begin(), items.end(),
                           [&itemName](const OrderItem &item)
                           {
                               return item.getMenuItemName() == itemName;
                           });
    if (it == items.end())
    {
        throw std::runtime_error("Item not found.");
    }
    it->updateQuantity(newQuantity);
    calculateTotal();
}

// Closes the order, changing its status
void Order::closeOrder()
{
    if (status == "Closed")
    {
        throw std::runtime_error("Order is already closed.");
    }
    status = "Closed";
}

// Calculates the total price of all items in the order
double Order::calculateTotal()
{
    totalPrice = std::accumulate(items.begin(), items.end(), 0.0,
                                 [](double total, const OrderItem &item)
                                 {
                                     return total + item.getTotalPrice();
                                 });
    return totalPrice;
}

// Getters
int Order::getOrderID() const
{
    return orderID;
}

std::string Order::getStatus() const
{
    return status;
}

double Order::getTotalPrice() const
{
    return totalPrice;
}
