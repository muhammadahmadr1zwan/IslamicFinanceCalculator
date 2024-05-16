#ifndef ZAKAT_CALCULATOR_H
#define ZAKAT_CALCULATOR_H

#include <string>
#include "Calculator.h"

class ZakatCalculator : public Calculator {
public:
    std::string calculate(double totalWealth, double nisab, double zakatRate);
};

#endif // ZAKAT_CALCULATOR_H
