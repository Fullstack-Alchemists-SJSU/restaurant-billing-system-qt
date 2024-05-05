#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include <functional>
#include "OrderItem.h"

class Order
{
private:
    int orderID;
    std::vector<OrderItem *> items;
    std::string status; // Open, Closed, etc.
public:
    Order(int id);

    void addItem(OrderItem *item);
    void removeItem(const std::string &menuItemName);
    void updateItem(const std::string &menuItemName, int quantity);
    void closeOrder();

    int getOrderID() const;
    std::string getStatus() const;
    void setStatus(const std::string &status)
    {
        this->status = status;
    }

    typedef std::vector<OrderItem *>::const_iterator const_iterator;
    const_iterator begin() const { return items.begin(); }
    const_iterator end() const { return items.end(); }

    void forEachItem(std::function<void(const OrderItem &)> func) const
    {
        for (const auto &item : items)
        {
            func(*item); // Dereference pointer to pass by reference
        }
    }

    ~Order()
    {
        for (auto item : items)
        {
            delete item;
        }
    }
};

#endif // ORDER_H
