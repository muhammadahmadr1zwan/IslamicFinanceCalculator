#include "IjaraCalculator.h"
#include <sstream>

std::string IjaraCalculator::calculate(double assetValue, int leaseTerm, double maintenanceCost, double insuranceCost) {
    double monthlyRent = (assetValue / leaseTerm) + maintenanceCost + insuranceCost;

    std::stringstream ss;
    ss << "Ijara Calculation: Islamic Leasing \n"
       << "Asset Value: $" << assetValue << "\n"
       << "Lease Term: " << leaseTerm << " months\n"
       << "Monthly Maintenance: $" << maintenanceCost << "\n"
       << "Insurance per Month: $" << insuranceCost << "\n"
       << "Monthly Rent: $" << monthlyRent;
    return ss.str();
}
