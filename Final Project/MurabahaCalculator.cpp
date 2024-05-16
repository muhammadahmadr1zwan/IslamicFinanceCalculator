#include "MurabahaCalculator.h"
#include <sstream>

std::string MurabahaCalculator::calculate(double purchasePrice, double profitMargin, double adminFees, double taxRate) {
    double taxes = purchasePrice * taxRate;
    double profit = purchasePrice * profitMargin;
    double totalCost = purchasePrice + adminFees + taxes;
    double sellingPrice = totalCost + profit;

    std::stringstream ss;
    ss << "Murabaha Calculation: A Set Profit on Merchandise \n"
       << "Purchase Price: $" << purchasePrice << "\n"
       << "Profit Margin: " << profitMargin << "\n"
       << "Admin Fees: $" << adminFees << "\n"
       << "Taxes: $" << taxes << "\n"
       << "Total Selling Price: $" << sellingPrice;
    return ss.str();
}
