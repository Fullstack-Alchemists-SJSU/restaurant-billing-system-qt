#ifndef ORDERMANAGEMENTFACADE_H
#define ORDERMANAGEMENTFACADE_H

#include "../controllers/OrderController.h"
#include "../menu/Menu.h"
#include "OrderAdapter.h"

class OrderManagementFacade
{
public:
    OrderManagementFacade();

    int createOrder();
    void addItemToOrder(int orderId, const std::string &menuItemName, int quantity);
    void removeItemFromOrder(int orderId, const std::string &menuItemName);
    void updateItemInOrder(int orderId, const std::string &menuItemName, int newQuantity);
    void closeOrder(int orderId);
    std::vector<Order *> getOrders();

    bool orderExists(int orderId) const {
        auto it = std::find_if(orders.begin(), orders.end(), [orderId](const Order* obj) {
            return obj->getOrderID() == orderId;
        });

        return it != orders.end();
    }

    Menu* getMenu();
    void loadOrdersFromFile(const std::string &filename);

private:
    OrderController orderController;
    std::vector<Order *> orders;
    int nextOrderId;
    Menu *menu; // Pointer to a Menu object
};

#endif // ORDERMANAGEMENTFACADE_H
