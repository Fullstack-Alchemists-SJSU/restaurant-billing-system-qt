#include "bill.h"
#include "../order/models/Order.h"
#include <algorithm>

// Constructor
Bill::Bill(int id, Order* ord, const std::string& billDate)
    : billID(id), order(ord), date(billDate), totalAmount(0.0) {}

// Destructor
Bill::~Bill() {}

// Add a discount decorator
void Bill::addDiscountDecorator(std::shared_ptr<BillDecorator> decorator) {
    discountDecorators.push_back(decorator);
}

// Apply all added discount decorators to calculate total amount
void Bill::applyDiscounts() {
    double discountedTotal = totalAmount;
    for (auto& decorator : discountDecorators) {
        discountedTotal = decorator->getTotalAmount();
    }
    totalAmount = discountedTotal;
}


// Remove a discount decorator
void Bill::removeDiscountDecorator(std::shared_ptr<BillDecorator> decorator) {
    auto it = std::find_if(discountDecorators.begin(), discountDecorators.end(),
                           [decorator](const std::shared_ptr<BillDecorator>& item) {
                               return item == decorator;
                           });
    if (it != discountDecorators.end()) {
        discountDecorators.erase(it);
    }
}

// Generates a bill including applied discounts
void Bill::generateBill() {
    if (order) {
        totalAmount = calculateTotal();  // Calculate total without discounts initially
        applyDiscounts();  // Apply discounts if any
        std::cout << "Bill is generated." << std::endl;
    } else {
        std::cerr << "Order pointer is null. Cannot generate bill." << std::endl;
    }
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

double Bill::calculateTotal(){
    if(order != nullptr){
        double orderTotal = 0;
        for(OrderItem* item: order->getItems()){
            orderTotal += (item->getQuantity() * item->getMenuItem()->getPrice());
        }

        return orderTotal;
    }

    return 0;
}
