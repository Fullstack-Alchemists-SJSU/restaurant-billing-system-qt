#ifndef BILL_H
#define BILL_H

#include <string>
#include <vector>

// Forward declaration for OrderItem and Order classes
class OrderItem;
class Order;

class Bill {
private:
    int billID;
    std::string date;
    double totalAmount;

public:
    // Constructor
    Bill(int id, const std::string& dt, double amt)
        : billID(id), date(dt), totalAmount(amt) {}

    // Methods
    void generateBill(); // This will be a placeholder
    void printBill(); // This will print the bill information

    // Setters and getters
    int getBillID() const { return billID; }
    void setBillID(int id) { billID = id; }

    std::string getDate() const { return date; }
    void setDate(const std::string& dt) { date = dt; }

    double getTotalAmount() const { return totalAmount; }
    void setTotalAmount(double amt) { totalAmount = amt; }
};

#endif // BILL_H
