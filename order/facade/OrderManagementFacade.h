#ifndef ORDERMANAGEMENTFACADE_H
#define ORDERMANAGEMENTFACADE_H

#include "../controllers/OrderController.h"
#include "../menu/Menu.h"

#include <map>

class OrderManagementFacade
{
public:
    OrderManagementFacade(Menu *menu); // Constructor now takes a Menu pointer

    int createOrder();
    void addItemToOrder(int orderId, const std::string &menuItemName, int quantity);
    void removeItemFromOrder(int orderId, const std::string &menuItemName);
    void updateItemInOrder(int orderId, const std::string &menuItemName, int newQuantity);
    void closeOrder(int orderId);

private:
    OrderController orderController;
    std::map<int, Order *> orders;
    int nextOrderId;
    Menu *menu; // Pointer to a Menu object
};

#endif // ORDERMANAGEMENTFACADE_H
