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
    static int nextOrderID;

public:
    explicit Order(int id); // Constructor for setting a specific order ID
    Order();                // Constructor for automatically assigning an order ID

    void addItem(OrderItem *item);
    void removeItem(const std::string &menuItemName);
    void updateItem(const std::string &menuItemName, int quantity);
    void closeOrder();

    int getOrderID() const { return orderID; }
    std::string getStatus() const;
    void setStatus(const std::string &status)
    {
        this->status = status;
    }

    // Method to get the number of items in the order
    size_t getItemCount() const
    {
        return items.size();
    }

    // Method to access an item by index
    const OrderItem &getItemAt(size_t index) const
    {
        if (index >= items.size())
        {
            throw std::out_of_range("Index out of range");
        }
        return *items[index]; // Assuming items is a vector of pointers
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
