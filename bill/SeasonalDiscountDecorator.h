#ifndef SEASONAL_DISCOUNT_DECORATOR_H
#define SEASONAL_DISCOUNT_DECORATOR_H

#include "BillDecorator.h"

class SeasonalDiscountDecorator : public BillDecorator {
public:
    SeasonalDiscountDecorator(std::shared_ptr<BillInterface> bill) : BillDecorator(bill) {}

    double getTotalAmount() const override {
        // Apply a 15% discount for seasonal orders
        return wrappedBill->getTotalAmount() * 0.85;
    }
};

#endif // SEASONAL_DISCOUNT_DECORATOR_H
