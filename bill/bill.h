#ifndef BILL_H
#define BILL_H

#include <vector>
#include <string>
#include <functional>
#include <memory>
#include "BillInterface.h"  // Include the BillInterface header

class Order;

class Bill : public BillInterface {
public:
    Bill(int id, Order* ord, const std::string& billDate);
    ~Bill();

    void generateBill();
    void printBill() const;
    void addDiscount(std::function<double(double)> discountFunction);
    void removeDiscount(std::function<double(double)> discountFunction);

    double calculateTotal();
    double getTotalAmount() const override;  // Override the virtual function

private:
    int billID;
    Order* order;
    std::string date;
    double totalAmount;
    std::vector<std::function<double(double)>> discounts;
};

#endif // BILL_H
