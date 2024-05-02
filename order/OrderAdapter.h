#pragma once
#include "./models/Order.h"
#include <string>
#include <vector>

class OrderAdapter
{
public:
    static std::string serialize(const Order &order);
    static Order deserialize(const std::string &csvLine);
    static void saveOrdersToCSV(const std::vector<Order> &orders, const std::string &filename);
    static std::vector<Order> loadOrdersFromCSV(const std::string &filename);
};