#include <iostream>
#include <vector>

class BillComponent {
public:
    virtual ~BillComponent() {}
    virtual double getTotalAmount() const = 0;
    virtual void print() const = 0;
};

class BillItem : public BillComponent {
    std::string description;
    double price;
public:
    BillItem(const std::string& desc, double price) : description(desc), price(price) {}
    double getTotalAmount() const override { return price; }
    void print() const override {
        std::cout << description << ": $" << price << std::endl;
    }
};

class BillCategory : public BillComponent {
    std::string name;
    std::vector<BillComponent*> children;
public:
    BillCategory(const std::string& name) : name(name) {}
    void add(BillComponent* component) { children.push_back(component); }
    double getTotalAmount() const override {
        double total = 0;
        for (auto* child : children) {
            total += child->getTotalAmount();
        }
        return total;
    }
    void print() const override {
        std::cout << name << std::endl;
        for (auto* child : children) {
            child->print();
        }
    }
};
