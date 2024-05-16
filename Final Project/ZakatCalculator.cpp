// ZakatCalculator.cpp
#include "ZakatCalculator.h"
#include <sstream>

std::string ZakatCalculator::calculate(double totalWealth, double nisab, double zakatRate) {
    std::stringstream ss;
    if (totalWealth > nisab) {
        double zakatDue = totalWealth * zakatRate;
        ss << "Zakat Calculation: Charity (Yearly)\n"
           << "Total Wealth: $" << totalWealth << "\n"
           << "Zakat Due: $" << zakatDue;
    } else {
        ss << "Wealth below nisab threshold; no Zakat due.";
    }
    return ss.str();
}