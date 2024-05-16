#include "ComplianceModule.h"
#include <iostream>

bool ComplianceModule::checkCompliance(const std::string& transactionType, double transactionAmount) {
    if (transactionType == "ExampleTransaction" && transactionAmount > 500) {
        std::cout << "Transaction is compliant." << std::endl;
        return true;
    } else {
        std::cout << "Transaction is non-compliant." << std::endl;
        return false;
    }
}
