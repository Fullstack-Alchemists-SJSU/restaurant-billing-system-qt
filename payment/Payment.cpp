// Payment.cpp
#include "Payment.h"
#include <iostream>

// Constructor
Payment::Payment(int paymentID, Bill* bill, double amount, PaymentMethod method, const std::string& date)
    : paymentID(paymentID), bill(bill), amount(amount), method(method), date(date) {}

// Destructor
Payment::~Payment() {}

// Getters and setters implementations
int Payment::getPaymentID() const { return paymentID; }
void Payment::setPaymentID(int paymentID) { this->paymentID = paymentID; }

Bill* Payment::getBill() const { return bill; }
void Payment::setBill(Bill* bill) { this->bill = bill; }

double Payment::getAmount() const { return amount; }
void Payment::setAmount(double amount) { this->amount = amount; }

Payment::PaymentMethod Payment::getMethod() const { return method; }
void Payment::setMethod(PaymentMethod method) { this->method = method; }

std::string Payment::getDate() const { return date; }
void Payment::setDate(const std::string& date) { this->date = date; }

// Payment processing methods
void Payment::processPayment() const {
    switch (method) {
    case PaymentMethod::CARD:
        processCardPayment();
        break;
    case PaymentMethod::CASH:
        processCashPayment();
        break;
    }
}

void Payment::processCardPayment() const {
    std::cout << "Processing card payment ID " << paymentID << " for amount $" << amount << std::endl;
    // Additional card processing logic here
}

void Payment::processCashPayment() const {
    std::cout << "Processing cash payment ID " << paymentID << " for amount $" << amount << std::endl;
    // Additional cash processing logic here
}
