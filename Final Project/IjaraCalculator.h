#ifndef IJARA_CALCULATOR_H
#define IJARA_CALCULATOR_H

#include <string>
#include "Calculator.h"

class IjaraCalculator : public Calculator {
public:
    std::string calculate(double assetValue, int leaseTerm, double maintenanceCost, double insuranceCost);
};

#endif // IJARA_CALCULATOR_H
