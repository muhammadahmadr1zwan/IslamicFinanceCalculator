#ifndef COMPLIANCE_MODULE_H
#define COMPLIANCE_MODULE_H

#include <string>

class ComplianceModule {
public:
    ComplianceModule() = default;

    // Checks if the transaction details comply with Islamic finance principles
    bool checkCompliance(const std::string& transactionType, double transactionAmount);
};

#endif // COMPLIANCE_MODULE_H
