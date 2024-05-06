#ifndef ORDERITEM_H
#define ORDERITEM_H

#include "../menu/MenuItem.h"

class OrderItem
{
public:
    OrderItem(MenuItem *menuItem, int quantity); // Constructor

    void updateQuantity(int newQuantity);
    MenuItem *getMenuItem() const;
    int getQuantity() const;
    std::string getMenuItemName() const; // To get the name of the MenuItem

private:
    MenuItem *menuItem; // Pointer to MenuItem, ensuring direct reference
    int quantity;       // Quantity of the item ordered
};

#endif // ORDERITEM_H
