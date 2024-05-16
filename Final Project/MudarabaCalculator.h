#ifndef MUDARABA_CALCULATOR_H
#define MUDARABA_CALCULATOR_H

#include <string>
#include "Calculator.h"

class MudarabaCalculator : public Calculator {
public:
    std::string calculate(double investment, double profit, double performanceRatio);
};

#endif // MUDARABA_CALCULATOR_H
