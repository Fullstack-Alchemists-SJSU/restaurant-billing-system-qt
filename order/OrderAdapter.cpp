#include "OrderAdapter.h"
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <iterator>
#include <iostream>

std::string OrderAdapter::serialize(const Order &order)
{
    std::ostringstream oss;
    oss << order.getOrderID() << "," << order.getStatus() << "," << order.getTotalPrice();

    // Serialize each item in the order
    for (const auto &item : order.getItems())
    {
        oss << "," << item.getMenuItemName() << ";" << item.getUnitPrice() << ";" << item.getQuantity();
    }
    return oss.str();
}

Order OrderAdapter::deserialize(const std::string &csvLine)
{
    std::istringstream ss(csvLine);
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(ss, segment, ','))
    {
        seglist.push_back(segment);
    }

    if (seglist.size() < 3)
        throw std::runtime_error("CSV format error");

    // Parsing the order data
    int orderID = std::stoi(seglist[0]);
    std::string status = seglist[1];
    double totalPrice = std::stod(seglist[2]);

    Order order;
    order.setOrderID(orderID);
    order.setStatus(status);
    order.setTotalPrice(totalPrice);

    // Deserialize each item (assumed to be from the fourth segment onwards)
    for (size_t i = 3; i < seglist.size(); i++)
    {
        std::istringstream itemStream(seglist[i]);
        std::string itemDetails;
        std::vector<std::string> itemData;
        while (std::getline(itemStream, itemDetails, ';'))
        {
            itemData.push_back(itemDetails);
        }
        if (itemData.size() == 3)
        {
            OrderItem item(itemData[0], std::stod(itemData[1]), std::stoi(itemData[2]));
            order.addItem(item);
        }
    }

    return order;
}

void OrderAdapter::saveOrdersToCSV(const std::vector<Order> &orders, const std::string &filename)
{
    std::ofstream outFile(filename, std::ios::out);
    if (!outFile.is_open())
        throw std::runtime_error("Failed to open file for writing: " + filename);
    for (const auto &order : orders)
    {
        outFile << OrderAdapter::serialize(order) << std::endl;
    }
    outFile.close();
}

std::vector<Order> OrderAdapter::loadOrdersFromCSV(const std::string &filename)
{
    std::vector<Order> orders;
    std::ifstream inFile(filename);
    std::string line;
    if (!inFile.is_open())
        throw std::runtime_error("Failed to open file for reading: " + filename);
    while (getline(inFile, line))
    {
        try
        {
            orders.push_back(OrderAdapter::deserialize(line));
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Failed to parse order from line: " << e.what() << ". Line was: " << line << std::endl;
        }
    }
    inFile.close();
    return orders;
}
