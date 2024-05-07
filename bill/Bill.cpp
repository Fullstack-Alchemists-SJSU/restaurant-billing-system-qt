#include "bill.h"
#include "../order/models/Order.h"
#include <algorithm>
#include <iostream>

// Constructor
Bill::Bill(int id, Order* ord, const std::string& billDate)
    : billID(id), order(ord), date(billDate), totalAmount(0.0) {}

// Destructor
Bill::~Bill() {}

void Bill::addDiscount(std::function<double(double)> discountFunction) {
    discounts.push_back(discountFunction);
}

void Bill::removeDiscount(std::function<double(double)> discountFunction) {
    discounts.erase(std::remove_if(discounts.begin(), discounts.end(),
                                   [&discountFunction](const std::function<double(double)>& f) {
                                       return f.target_type() == discountFunction.target_type();
                                   }), discounts.end());
}

void Bill::applyDiscount(std::function<double(double)> discountFunction) {
    discounts.push_back(discountFunction);
    totalAmount = calculateTotal();  // Recalculate total immediately
}

double Bill::calculateTotal() {
    double baseTotal = 0;
    if (order != nullptr) {
        for (const OrderItem* item : order->getItems()) {
            baseTotal += item->getQuantity() * item->getMenuItem()->getPrice();
        }
    }
    for (const auto& discount : discounts) {
        baseTotal = discount(baseTotal);  // Apply each discount in turn
    }
    return baseTotal;
}

// Generates a bill including applied discounts
void Bill::generateBill() {
    totalAmount = calculateTotal();
}

// Print the bill details
void Bill::printBill() const {
    if (order) {
        std::cout << "Bill ID: " << billID << std::endl;
        std::cout << "Date: " << date << std::endl;
        std::cout << "Total amount: $" << totalAmount << std::endl;
    } else {
        std::cerr << "Order pointer is null. Cannot view bill." << std::endl;
    }
}
/*
double Bill::calculateTotal(){
    if(order != nullptr){
        double orderTotal = 0;
        for(OrderItem* item: order->getItems()){
            orderTotal += (item->getQuantity() * item->getMenuItem()->getPrice());
        }

        return orderTotal;
    }

    return 0;
}*/
