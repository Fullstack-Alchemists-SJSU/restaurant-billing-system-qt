#ifndef BILL_INTERFACE_H
#define BILL_INTERFACE_H

class BillInterface {
public:
    virtual ~BillInterface() {}
    virtual double getTotalAmount() const = 0;
};

#endif // BILL_INTERFACE_H
