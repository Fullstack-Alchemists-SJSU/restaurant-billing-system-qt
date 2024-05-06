#include "OrderItem.h"
#include <stdexcept>

OrderItem::OrderItem(MenuItem *menuItem, int quantity)
    : menuItem(menuItem), quantity(quantity)
{
    if (!menuItem)
    {
        throw std::invalid_argument("MenuItem cannot be null.");
    }
    if (quantity <= 0)
    {
        throw std::invalid_argument("Quantity must be greater than zero.");
    }
}

void OrderItem::updateQuantity(int newQuantity)
{
    if (newQuantity <= 0)
    {
        throw std::invalid_argument("Quantity must be greater than zero.");
    }
    quantity = newQuantity;
}

MenuItem *OrderItem::getMenuItem() const
{
    return menuItem;
}

int OrderItem::getQuantity() const
{
    return quantity;
}

std::string OrderItem::getMenuItemName() const
{
    return menuItem->getName();
}
