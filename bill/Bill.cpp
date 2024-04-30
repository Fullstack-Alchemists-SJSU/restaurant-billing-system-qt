// Bill.cpp
#include "Bill.h"
#include "MenuItem.h" // Include other necessary headers

// Definitions of OrderItem member functions
OrderItem::OrderItem(MenuItem* item, int qty) : menuItem(item), quantity(qty) {}

void OrderItem::updateQuantity(int qty) {
    quantity = qty;
    std::cout << "Quantity updated to " << quantity << std::endl;
}

// Definitions of Order member functions
Order::Order(int id) : orderID(id), totalPrice(0) {}

void Order::addItem(OrderItem item) {
    items.push_back(item);
}

void Order::calculateTotal() {
    totalPrice = 0;
    for (const auto& item : items) {
        totalPrice += item.menuItem->price * item.quantity; // Assumes price is a member of MenuItem
    }
}

// Definitions of Bill member functions
Bill::Bill(int id, Order* ord, const std::string& billDate)
    : billID(id), order(ord), date(billDate), totalAmount(0) {}

void Bill::generateBill() {
    order->calculateTotal();
    totalAmount = order->totalPrice;
    std::cout << "Bill is generated." << std::endl;
}

void Bill::printBill() {
    std::cout << "Bill ID: " << billID << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Total amount: " << totalAmount << std::endl;
}
