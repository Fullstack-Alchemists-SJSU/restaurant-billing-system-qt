#ifndef BILL_INTERFACE_H
#define BILL_INTERFACE_H

class BillInterface {
public:
    virtual ~BillInterface() {}
    virtual void generateBill() = 0;
    virtual void printBill() const = 0;
    virtual double getTotalAmount() const = 0;
};

#endif // BILL_INTERFACE_H
