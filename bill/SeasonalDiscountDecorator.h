#ifndef SEASONAL_DISCOUNT_DECORATOR_H
#define SEASONAL_DISCOUNT_DECORATOR_H

#include "BillDecorator.h"

class SeasonalDiscountDecorator : public BillDecorator {
public:
    SeasonalDiscountDecorator(std::shared_ptr<BillInterface> bill) : BillDecorator(bill) {}
    double getTotalAmount() const override {
        return wrappedBill->getTotalAmount() * 0.85;
    }
};

#endif // SEASONAL_DISCOUNT_DECORATOR_H
