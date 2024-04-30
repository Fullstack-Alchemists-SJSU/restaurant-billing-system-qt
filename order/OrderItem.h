#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <string>

class OrderItem
{
public:
    OrderItem(const std::string &name, double price, int qty)
        : menuItemName(name), unitPrice(price), quantity(qty) {}

    void updateQuantity(int newQuantity)
    {
        quantity = newQuantity;
    }

    std::string getMenuItemName() const { return menuItemName; }
    double getUnitPrice() const { return unitPrice; }
    int getQuantity() const { return quantity; }
    double getTotalPrice() const { return unitPrice * quantity; }

private:
    std::string menuItemName;
    double unitPrice;
    int quantity;
};

#endif // ORDERITEM_H
