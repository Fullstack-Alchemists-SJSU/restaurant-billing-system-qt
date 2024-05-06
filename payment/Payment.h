// Payment.h
#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include "../bill/bill.h"  // Assuming Bill is a class defined in another header

class Payment {
public:
    enum class PaymentMethod {
        CARD, CASH
    };

    // Constructor
    Payment(int paymentID, Bill* bill, double amount, PaymentMethod method, const std::string& date);

    // Destructor
    ~Payment();

    // Getters and setters
    int getPaymentID() const;
    void setPaymentID(int paymentID);

    Bill* getBill() const;
    void setBill(Bill* bill);

    double getAmount() const;
    void setAmount(double amount);

    PaymentMethod getMethod() const;
    void setMethod(PaymentMethod method);

    std::string getDate() const;
    void setDate(const std::string& date);

    // Payment processing
    void processPayment() const;

private:
    int paymentID;
    Bill* bill;
    double amount;
    PaymentMethod method;
    std::string date;

    // Private methods for different payment methods
    void processCardPayment() const;
    void processCashPayment() const;
};

#endif  // PAYMENT_H
