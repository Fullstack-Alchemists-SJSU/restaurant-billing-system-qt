#ifndef ORDER_H
#define ORDER_H

#include "OrderItem.h"
#include <vector>
#include <string>

class Order
{
public:
    Order(); // Constructor to initialize an order with a unique ID.
    //2nd Constructor

    void addItem(const OrderItem &item);                           // Adds an item to the order.
    void removeItem(const std::string &itemName);                  // Removes an item by name.
    void updateItem(const std::string &itemName, int newQuantity); // Updates the quantity of an item.
    void closeOrder();                                             // Marks the order as closed.
    double calculateTotal();                                       // Calculates the total price of the order.

    // Getters
    int getOrderID() const;
    std::string getStatus() const;
    double getTotalPrice() const;
    double totalPrice;            // Total price of all items in the order.

private:
    static int nextOrderID;       // Static counter to assign unique IDs to each order.
    int orderID;                  // Unique identifier for the order.
    std::vector<OrderItem> items; // List of items in the order.
    std::string status;           // Current status of the order ("Open", "Closed").

};

#endif // ORDER_H
