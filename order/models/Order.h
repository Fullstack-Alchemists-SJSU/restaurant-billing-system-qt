#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include <functional>
#include "OrderItem.h"
#include <stdexcept>
#include <QString>

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
    Order(const Order& other); // Custom copy constructor

    void addItem(OrderItem *item);
    void removeItem(const std::string &menuItemName);
    void updateItem(const std::string &menuItemName, int quantity);
    void closeOrder();
    std::vector<OrderItem *> getItems();
    size_t getItemCount() const;

    int getOrderID() const { return orderID; }
    std::string getStatus() const;
    void setStatus(const std::string &status)
    {
        this->status = status;
    }

    const OrderItem &getItemAt(size_t index) const
    {
        if (index >= items.size())
        {
            throw std::out_of_range("Index out of range");
        }
        return *items[index];
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

    bool operator==(const Order& other) const {
        return this->orderID == other.orderID;
    }

    bool itemExists(QString itemName) const {
        auto it = std::find_if(items.begin(), items.end(), [itemName](const OrderItem* obj) {
            return obj->getMenuItem()->getName().compare(itemName.toStdString()) == 0;
        });

        return it != items.end();
    }
};

#endif // ORDER_H
