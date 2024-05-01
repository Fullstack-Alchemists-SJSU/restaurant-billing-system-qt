#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <string>
#include "../menu/MenuItem.h"

class OrderItem
{
public:
    // Constructor
    OrderItem(const std::string &name, double price, int qty);

    //2nd Constructor
    OrderItem(MenuItem* item, int qty);

    // Method to update the item quantity
    void updateQuantity(int newQuantity);

    // Getters
    std::string getMenuItemName() const;
    double getUnitPrice() const;
    int getQuantity() const;
    double getTotalPrice() const;
    void print() const;


private:
    std::string menuItemName; // Name of the menu item
    double unitPrice;         // Price per unit of the item
    int quantity;             // Quantity of the item ordered
};

#endif // ORDERITEM_H
