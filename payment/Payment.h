#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include "../bill/Bill.h" // Ensure this include is correct based on your project structure

class Payment {
public:
    Payment(int id, double amount, const std::string& method, const std::string& date, Bill* bill);

    // Method to process the payment
    void processPayment();

    // Getters and setters for private members
    int getPaymentID() const;
    double getAmount() const;
    std::string getMethod() const;
    std::string getDate() const;
    Bill* getBill() const;

    void setAmount(double amount);
    void setMethod(const std::string& method);
    void setDate(const std::string& date);
    void setBill(Bill* bill);

private:
    int paymentID;     // Unique identifier for the payment
    double amount;     // Amount of the payment
    std::string method; // Payment method (e.g., cash, credit card)
    std::string date;  // Date of the payment
    Bill* bill;        // Pointer to the associated Bill
};

#endif // PAYMENT_H
