#ifndef BILL_INTERFACE_H
#define BILL_INTERFACE_H

class BillInterface {
public:
    virtual ~BillInterface() {}
    virtual double getTotalAmount() const = 0;  // Ensure this function is virtual
};

#endif // BILL_INTERFACE_H
