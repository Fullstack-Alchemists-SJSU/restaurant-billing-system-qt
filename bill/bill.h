#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "BillDecorator.h" // Include the BillDecorator header file
#include "BillInterface.h"
#include <memory>


class Order; // Forward declaration of the Order class

class Bill   {
public:
    // Constructor to initialize a Bill object
    Bill(int id, Order* ord, const std::string& billDate);

    // Destructor
    ~Bill();

    // Generates a bill by calculating the total from the Order object
    void generateBill();

    // Prints the bill details
    void printBill() const;

    // Add a discount decorator
    void addDiscountDecorator(std::shared_ptr<BillDecorator> decorator);

    // Remove a discount decorator
    void removeDiscountDecorator(std::shared_ptr<BillDecorator> decorator);

    void applyDiscounts();

    double calculateTotal();
    void refreshTotal();



private:
    int billID;                  // Unique identifier for the bill
    Order* order;                // Pointer to the associated order
    std::string date;            // Date when the bill was generated
    double totalAmount;          // Total amount of the bill
    std::vector<std::shared_ptr<BillDecorator>> discountDecorators;  // Store discount decorators
};

#endif // BILL_H
