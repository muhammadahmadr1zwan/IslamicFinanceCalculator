#include "MudarabaCalculator.h"
#include <sstream>

// Ensure the class and method are correctly defined
std::string MudarabaCalculator::calculate(double investment, double profit, double performanceRatio) {
    double profitShareInvestor = 0.7; // Base share for the investor
    double profitShareEntrepreneur = 0.3; // Base share for the entrepreneur

    // Adjust profit shares based on performance
    if (performanceRatio > 1.0) {
        profitShareInvestor += 0.05; // Increase investor's share by 5%
        profitShareEntrepreneur -= 0.05; // Decrease entrepreneur's share by 5%
    }

    double investorProfit = profit * profitShareInvestor;
    double entrepreneurProfit = profit * profitShareEntrepreneur;

    std::stringstream ss;
    ss << "Mudaraba Calculation: Islamic Investment Partnership \n"
       << "Investment: $" << investment << "\n"
       << "Total Profit: $" << profit << "\n"
       << "Investor's Profit Share: $" << investorProfit << "\n"
       << "Entrepreneur's Profit Share: $" << entrepreneurProfit;
    return ss.str();
}
