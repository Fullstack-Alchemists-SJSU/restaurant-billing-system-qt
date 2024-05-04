#ifndef SEASONAL_DISCOUNT_DECORATOR_H
#define SEASONAL_DISCOUNT_DECORATOR_H

#include "BillDecorator.h"

class SeasonalDiscountDecorator : public BillDecorator {
public:
    SeasonalDiscountDecorator(std::shared_ptr<BillInterface> bill) : BillDecorator(bill) {}

    double getTotalAmount() const override {
        // Apply a 10% discount for party orders
        return wrappedBill->getTotalAmount() * 0.85;
    }
};

#endif // PARTY_DISCOUNT_DECORATOR_H
