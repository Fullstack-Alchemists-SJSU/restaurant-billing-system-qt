#ifndef BILL_DECORATOR_H
#define BILL_DECORATOR_H

#include "BillInterface.h"
#include <memory>

class BillDecorator : public BillInterface {
protected:
    std::shared_ptr<BillInterface> wrappedBill;

public:
    BillDecorator(std::shared_ptr<BillInterface> bill) : wrappedBill(bill) {}

    void generateBill() override {
        wrappedBill->generateBill();
    }

    void printBill() const override {
        wrappedBill->printBill();
    }

    double getTotalAmount() const override {
        return wrappedBill->getTotalAmount();
    }
};

#endif // BILL_DECORATOR_H
