#ifndef COUPON_DISCOUNT_DECORATOR_H
#define COUPON_DISCOUNT_DECORATOR_H

#include "BillDecorator.h"

class CouponDiscountDecorator : public BillDecorator {
public:
    CouponDiscountDecorator(std::shared_ptr<BillInterface> bill) : BillDecorator(bill) {}
    double getTotalAmount() const override {
        return wrappedBill->getTotalAmount() * 0.95;
    }
};

#endif // COUPON_DISCOUNT_DECORATOR_H
