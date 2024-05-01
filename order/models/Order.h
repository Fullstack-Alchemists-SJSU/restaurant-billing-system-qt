#ifndef ORDER_H
#define ORDER_H

#include "OrderItem.h"
#include <vector>
#include <string>

class Order
{
public:
    Order(); // Constructor initializes with a unique ID.

    void addItem(const OrderItem &item);
    void removeItem(const std::string &itemName);
    void updateItem(const std::string &itemName, int newQuantity);
    void closeOrder();
    double calculateTotal();

    // Existing getters
    int getOrderID() const;
    std::string getStatus() const;
    double getTotalPrice() const;

    // New getters and setters
    void setOrderID(int id);
    void setStatus(const std::string &status);
    void setTotalPrice(double price);
    const std::vector<OrderItem> &getItems() const; // Provide read-only access to items

private:
    static int nextOrderID;
    int orderID;
    std::vector<OrderItem> items;
    std::string status;
    double totalPrice;
};

#endif // ORDER_H
