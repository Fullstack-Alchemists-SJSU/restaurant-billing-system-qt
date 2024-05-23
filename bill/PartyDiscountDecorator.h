#ifndef PARTY_DISCOUNT_DECORATOR_H
#define PARTY_DISCOUNT_DECORATOR_H

#include "BillDecorator.h"

class PartyDiscountDecorator : public BillDecorator {
public:
    PartyDiscountDecorator(std::shared_ptr<BillInterface> bill) : BillDecorator(bill) {}
    double getTotalAmount() const override {
        return wrappedBill->getTotalAmount() * 0.9;
    }
};

#endif // PARTY_DISCOUNT_DECORATOR_H
