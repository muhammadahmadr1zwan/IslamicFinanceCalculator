#ifndef SADAQAH_CALCULATOR_H
#define SADAQAH_CALCULATOR_H

#include <string>
#include "Calculator.h"

class SadaqahCalculator : public Calculator {
public:
    std::string calculate(double income, double sadaqahRate);
};

#endif // SADAQAH_CALCULATOR_H
