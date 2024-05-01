// Bill.h
#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <vector>
#include <string>
#include "../order/Order.h"


class Bill {
public:
    // Constructor to initialize a Bill object
    Bill(int id, Order* ord, const std::string& billDate);

    // Generates a bill by calculating the total from the Order object
    void generateBill();

    // Prints the bill details
    void printBill() const;

private:
    int billID;                  // Unique identifier for the bill
    Order* order;                // Pointer to the associated order
    std::string date;            // Date when the bill was generated
    double totalAmount;          // Total amount of the bill
};

#endif // BILL_H
