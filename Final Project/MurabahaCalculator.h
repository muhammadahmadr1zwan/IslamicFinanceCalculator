#ifndef MURABAHA_CALCULATOR_H
#define MURABAHA_CALCULATOR_H

#include <string>
#include "Calculator.h"

class MurabahaCalculator : public Calculator {
public:
    std::string calculate(double purchasePrice, double profitMargin, double adminFees, double taxRate);
};

#endif // MURABAHA_CALCULATOR_H
