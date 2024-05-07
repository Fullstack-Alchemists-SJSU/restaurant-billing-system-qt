#ifndef BILL_H
#define BILL_H


#include <vector>
#include <string>
#include <functional>
#include <memory>


class Order; // Forward declaration of the Order class

class Bill  {
public:
    // Constructor to initialize a Bill object
    Bill(int id, Order* ord, const std::string& billDate);

    // Destructor
    ~Bill();



    // Generates a bill by calculating the total from the Order object
    void generateBill();

    // Prints the bill details
    void printBill() const;

    void addDiscount(std::function<double(double)> discountFunction);
    void removeDiscount(std::function<double(double)> discountFunction);

    void applyDiscount(std::function<double(double)> discountFunction);
    double calculateTotal();
    //void refreshTotal();



private:
    int billID;                  // Unique identifier for the bill
    Order* order;                // Pointer to the associated order
    std::string date;            // Date when the bill was generated
    double totalAmount;          // Total amount of the bill
    std::vector<std::function<double(double)>> discounts;  // Discount functions
};

#endif // BILL_H
