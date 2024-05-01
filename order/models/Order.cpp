#include "Order.h"
#include <algorithm>
#include <numeric>
#include <stdexcept>

int Order::nextOrderID = 1; // Static ID initialization

Order::Order() : orderID(nextOrderID++), status("Open"), totalPrice(0.0) {}

void Order::addItem(const OrderItem &item)
{
    items.push_back(item);
    calculateTotal();
}

void Order::removeItem(const std::string &itemName)
{
    auto it = std::remove_if(items.begin(), items.end(), [&itemName](const OrderItem &item)
                             { return item.getMenuItemName() == itemName; });
    if (it == items.end())
        throw std::runtime_error("Item not found.");
    items.erase(it);
    calculateTotal();
}

void Order::updateItem(const std::string &itemName, int newQuantity)
{
    auto it = std::find_if(items.begin(), items.end(), [&itemName](const OrderItem &item)
                           { return item.getMenuItemName() == itemName; });
    if (it == items.end())
        throw std::runtime_error("Item not found.");
    it->updateQuantity(newQuantity);
    calculateTotal();
}

void Order::closeOrder()
{
    status = "Closed";
}

double Order::calculateTotal()
{
    totalPrice = std::accumulate(items.begin(), items.end(), 0.0, [](double sum, const OrderItem &item)
                                 { return sum + item.getTotalPrice(); });
    return totalPrice;
}

// New getters and setters
void Order::setOrderID(int id) { orderID = id; }
void Order::setStatus(const std::string &newStatus) { status = newStatus; }
void Order::setTotalPrice(double price) { totalPrice = price; }
const std::vector<OrderItem> &Order::getItems() const { return items; }

int Order::getOrderID() const { return orderID; }
std::string Order::getStatus() const { return status; }
double Order::getTotalPrice() const { return totalPrice; }
