#ifndef ORDER_H
#define ORDER_H

#include "OrderItem.h"
#include <vector>
#include <numeric>

class Order
{
public:
    Order() : orderID(nextOrderID++), totalPrice(0.0), status("Open") {}

    void addItem(const OrderItem &item)
    {
        items.push_back(item);
        calculateTotal();
    }

    // This function would need a proper identifier for the item
    void removeItem(const std::string &itemName)
    {
        items.erase(std::__remove_if(items.begin(), items.end(),
                                   [&itemName](const OrderItem &item)
                                   {
                                       return item.getMenuItemName() == itemName;
                                   }),
                    items.end());
        calculateTotal();
    }

    void updateItemQuantity(const std::string &itemName, int newQuantity)
    {
        auto it = std::__find_if(items.begin(), items.end(),
                               [&itemName](const OrderItem &item)
                               {
                                   return item.getMenuItemName() == itemName;
                               });
        if (it != items.end())
        {
            it->updateQuantity(newQuantity);
        }
        calculateTotal();
    }

    void closeOrder()
    {
        status = "Closed";
    }

    double getTotalPrice() const { return totalPrice; }

private:
    static int nextOrderID;
    int orderID;
    std::vector<OrderItem> items;
    std::string status;
    double totalPrice;

    void calculateTotal()
    {
        totalPrice = std::accumulate(items.begin(), items.end(), 0.0,
                                     [](double total, const OrderItem &item)
                                     {
                                         return total + item.getTotalPrice();
                                     });
    }
};

int Order::nextOrderID = 1;

#endif // ORDER_H
