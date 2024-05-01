#include "OrderItem.h"
#include <stdexcept> // For std::invalid_argument

// Constructor with initialization list
OrderItem::OrderItem(const std::string &name, double price, int qty)
{
    if (name.empty())
    {
        throw std::invalid_argument("Item name cannot be empty.");
    }
    if (price <= 0)
    {
        throw std::invalid_argument("Price must be greater than zero.");
    }
    if (qty < 0)
    {
        throw std::invalid_argument("Quantity cannot be negative.");
    }
    menuItemName = name;
    unitPrice = price;
    quantity = qty;
}

// Method to update the quantity of the order item
void OrderItem::updateQuantity(int newQuantity)
{
    if (newQuantity < 0)
    {
        throw std::invalid_argument("Quantity cannot be negative.");
    }
    quantity = newQuantity;
}

// Getter for the item's total price
double OrderItem::getTotalPrice() const
{
    return unitPrice * quantity;
}

// Additional getters
std::string OrderItem::getMenuItemName() const
{
    return menuItemName;
}

double OrderItem::getUnitPrice() const
{
    return unitPrice;
}

int OrderItem::getQuantity() const
{
    return quantity;
}
