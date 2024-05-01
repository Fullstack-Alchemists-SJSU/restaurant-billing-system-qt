// Bill.cpp
#include "Bill.h"
#include "../order/Order.h"
#include "../order/OrderItem.h"
#include "../menu/MenuItem.h"
// Include other necessary headers

// Definitions of Bill member functions
Bill::Bill(int id, Order* ord, const std::string& billDate)
    : billID(id), order(ord), date(billDate), totalAmount(0.0) {}


// Generates a bill by calculating total from the Order object
void Bill::generateBill() {
    if (order) {
        totalAmount = order->calculateTotal();  // Directly use the returned value from calculateTotal
        std::cout << "Bill is generated." << std::endl;
    } else {
        std::cerr << "Order pointer is null. Cannot generate bill." << std::endl;
    }
}

// Prints the bill details
void Bill::printBill() const {
    if (order) {
        std::cout << "Bill ID: " << billID << std::endl;
        std::cout << "Date: " << date << std::endl;
        std::cout << "Total amount: $" << totalAmount << std::endl;
        std::cerr << "Order pointer is null. Cannot print bill." << std::endl;
    }
}
