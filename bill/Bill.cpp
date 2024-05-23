#include "bill.h"
#include "../order/models/Order.h"
#include <algorithm>
#include <iostream>

Bill::Bill(int id, Order* ord, const std::string& billDate)
    : billID(id), order(ord), date(billDate), totalAmount(0.0) {}

Bill::~Bill() {}

void Bill::generateBill() {
    totalAmount = calculateTotal();
}

void Bill::printBill() const {
    if (order) {
        std::cout << "Bill ID: " << billID << std::endl;
        std::cout << "Date: " << date << std::endl;
        std::cout << "Total amount: $" << totalAmount << std::endl;
    } else {
        std::cerr << "Order pointer is null. Cannot view bill." << std::endl;
    }
}

double Bill::calculateTotal() {
    double baseTotal = 0;
    if (order != nullptr) {
        for (const OrderItem* item : order->getItems()) {
            baseTotal += item->getQuantity() * item->getMenuItem()->getPrice();
        }
    }
    for (const auto& discount : discounts) {
        baseTotal = discount(baseTotal);
    }
    return baseTotal;
}

void Bill::addDiscount(std::function<double(double)> discountFunction) {
    discounts.push_back(discountFunction);
}

void Bill::removeDiscount(std::function<double(double)> discountFunction) {
    discounts.erase(std::remove_if(discounts.begin(), discounts.end(),
                                   [&discountFunction](const std::function<double(double)>& f) {
                                       return f.target_type() == discountFunction.target_type();
                                   }), discounts.end());
}

double Bill::getTotalAmount() const {
    return totalAmount;
}
