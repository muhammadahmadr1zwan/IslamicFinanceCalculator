// SadaqahCalculator.cpp
#include "SadaqahCalculator.h"
#include <sstream>

std::string SadaqahCalculator::calculate(double income, double sadaqahRate) {
    std::stringstream ss;
    double sadaqahAmount = income * sadaqahRate;
    ss << "Sadaqah Calculation: Charity (anytime of year)\n"
       << "Annual Income: $" << income << "\n"
       << "Sadaqah Amount: $" << sadaqahAmount;
    return ss.str();
}