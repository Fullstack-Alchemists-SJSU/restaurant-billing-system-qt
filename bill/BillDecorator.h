#ifndef BILL_DECORATOR_H
#define BILL_DECORATOR_H

#include "BillInterface.h"
#include <memory>

class BillDecorator : public BillInterface {
public:
    explicit BillDecorator(std::shared_ptr<BillInterface> bill) : wrappedBill(bill) {}
    double getTotalAmount() const override {
        return wrappedBill->getTotalAmount();
    }
protected:
    std::shared_ptr<BillInterface> wrappedBill;
};

#endif // BILL_DECORATOR_H
