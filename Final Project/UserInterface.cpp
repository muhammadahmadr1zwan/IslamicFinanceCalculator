#include "UserInterface.h"
#include "MurabahaCalculator.h"
#include "IjaraCalculator.h"
#include "MudarabaCalculator.h"
#include "ZakatCalculator.h"
#include "SadaqahCalculator.h"
#include "UserLoginManager.h" // Include UserLoginManager header
#include <iostream>
#include <limits> // For std::numeric_limits

UserInterface::UserInterface() : localizer(new LocalizationManager()), isLoggedIn(false) {
    userLogins = UserLoginManager::readUserLoginsFromFile("user_logins.csv");
}

UserInterface::~UserInterface() {
    delete localizer;
}

void UserInterface::displayMainMenu() {
    std::cout << localizer->translate("main_menu") << std::endl;
    std::cout << "1. " << localizer->translate("login") << std::endl;
    std::cout << "2. " << localizer->translate("sign_up") << std::endl;
    std::cout << "3. " << localizer->translate("change_language") << std::endl;
    std::cout << "4. " << localizer->translate("exit") << std::endl;
}

void UserInterface::processMainMenuInput(int choice) {
    switch (choice) {
        case 1: login(); break;
        case 2: signUp(); break;
        case 3: changeLanguage(); break;
        case 4: std::cout << localizer->translate("exiting_application") << std::endl; exit(0); break;
        default: std::cout << localizer->translate("invalid_option") << std::endl;
    }
}

void UserInterface::login() {
    std::string username, password;
    std::cout << localizer->translate("enter_username") << ": ";
    std::cin >> username;
    std::cout << localizer->translate("enter_password") << ": ";
    std::cin >> password;

    for (const auto& login : userLogins) {
        if (login.username == username && login.password == password) {
            isLoggedIn = true;
            std::cout << localizer->translate("login_successful") << std::endl;
            displayUserMenu(); // Display user menu after successful login
            return;
        }
    }
    
    std::cout << localizer->translate("invalid_username_or_password") << std::endl;
}

void UserInterface::signUp() {
    std::string username, password;
    std::cout << localizer->translate("choose_username") << ": ";
    std::cin >> username;
    if (isUsernameTaken(username)) {
        std::cout << localizer->translate("username_taken") << std::endl;
        return;
    }
    std::cout << localizer->translate("set_password") << ": ";
    std::cin >> password;
    userLogins.push_back({username, password});
    UserLoginManager::writeUserLoginToFile({username, password}, "user_logins.csv"); // Write to file
    std::cout << localizer->translate("registration_successful") << ". " << localizer->translate("please_login") << std::endl;
}

bool UserInterface::isUsernameTaken(const std::string& username) const {
    for (const auto& login : userLogins) {
        if (login.username == username) {
            return true;
        }
    }
    return false;
}

void UserInterface::changeLanguage() {
    std::string language;
    std::cout << localizer->translate("enter_language") << ": ";
    std::cin >> language;
    localizer->setLanguage(language);
    std::cout << localizer->translate("language_changed") << std::endl;
}

bool UserInterface::isUserLoggedIn() const {
    return isLoggedIn;
}

void UserInterface::displayUserMenu() {
    std::cout << localizer->translate("user_menu_displayed") << std::endl;
    displayCalculationOptions(); // Display calculation options after showing user menu

    // Ask user if they want to return to the main menu
    std::cout << localizer->translate("return_to_main_menu") << std::endl;
    std::string response;
    std::cin >> response;
    if (response == "yes") {
        isLoggedIn = false; // Reset login status
        displayMainMenu(); // Return to the main menu
    }
}

void UserInterface::processUserMenuInput(int choice) {
    std::cout << "Processing User Menu Input" << std::endl;
}

void UserInterface::askForExport(const std::string& data, const std::string& fileName) {
    std::ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        outputFile << data << std::endl;
        outputFile.close();
        std::cout << localizer->translate("export_success") << std::endl;
    } else {
        std::cout << localizer->translate("export_failed") << std::endl;
    }
}

void UserInterface::displayCalculationOptions() {
    if (!isLoggedIn) {
        std::cout << localizer->translate("login_required") << std::endl;
        return;
    }

    std::cout << localizer->translate("calc_options") << std::endl;
    std::cout << "1. " << localizer->translate("murabaha_calculator") << std::endl;
    std::cout << "2. " << localizer->translate("ijara_calculator") << std::endl;
    std::cout << "3. " << localizer->translate("mudaraba_calculator") << std::endl;
    std::cout << "4. " << localizer->translate("zakat_calculator") << std::endl;
    std::cout << "5. " << localizer->translate("sadaqah_calculator") << std::endl;

    int choice;
    std::cout << localizer->translate("enter_choice") << ": ";
    std::cin >> choice;

    std::string result;
    switch (choice) {
        case 1:
            result = handleMurabahaCalculation();
            break;
        case 2:
            result = handleIjaraCalculation();
            break;
        case 3:
            result = handleMudarabaCalculation();
            break;
        case 4:
            result = handleZakatCalculation();
            break;
        case 5:
            result = handleSadaqahCalculation();
            break;
        default:
            std::cout << localizer->translate("invalid_option") << std::endl;
            return;
    }

    std::cout << result << std::endl;

    // Ask the user if they want to export the calculation result
    std::cout << localizer->translate("export_result_question") << " ";
    std::string exportChoice;
    std::cin >> exportChoice;
    if (exportChoice == "yes") {
        std::string fileName;
        std::cout << localizer->translate("enter_file_name") << ": ";
        std::cin >> fileName;
        askForExport(result, fileName);
    }
}

std::string UserInterface::handleMurabahaCalculation() {
    double purchasePrice, profitMargin, adminFees, taxRate;
    std::cout << localizer->translate("enter_purchase_price") << ": ";
    std::cin >> purchasePrice;
    std::cout << localizer->translate("enter_profit_margin") << " (" << localizer->translate("example_15_percent") << "): ";
    std::cin >> profitMargin;
    std::cout << localizer->translate("enter_admin_fees") << ": ";
    std::cin >> adminFees;
    std::cout << localizer->translate("enter_tax_rate") << " (" << localizer->translate("example_5_percent") << "): ";
    std::cin >> taxRate;

    MurabahaCalculator calculator;
    return calculator.calculate(purchasePrice, profitMargin, adminFees, taxRate);
}

std::string UserInterface::handleIjaraCalculation() {
    double assetValue, maintenanceCost, insuranceCost;
    int leaseTerm;
    std::cout << localizer->translate("enter_asset_value") << ": ";
    std::cin >> assetValue;
    std::cout << localizer->translate("enter_lease_term") << " (" << localizer->translate("in_months") << "): ";
    std::cin >> leaseTerm;
    std::cout << localizer->translate("enter_monthly_maintenance_cost") << ": ";
    std::cin >> maintenanceCost;
    std::cout << localizer->translate("enter_monthly_insurance_cost") << ": ";
    std::cin >> insuranceCost;

    IjaraCalculator calculator;
    return calculator.calculate(assetValue, leaseTerm, maintenanceCost, insuranceCost);
}

std::string UserInterface::handleMudarabaCalculation() {
    double investment, profit, performanceRatio;
    std::cout << localizer->translate("enter_total_investment") << ": ";
    std::cin >> investment;
    std::cout << localizer->translate("enter_profit") << ": ";
    std::cin >> profit;
    std::cout << localizer->translate("enter_performance_ratio") << " (" << localizer->translate("example_1.2") << "): ";
    std::cin >> performanceRatio;

    MudarabaCalculator calculator;
    return calculator.calculate(investment, profit, performanceRatio);
}

std::string UserInterface::handleZakatCalculation() {
    double totalWealth, nisab, zakatRate;
    std::cout << localizer->translate("enter_total_wealth") << ": ";
    std::cin >> totalWealth;
    std::cout << localizer->translate("enter_nisab") << " (" << localizer->translate("minimum_amount") << "): ";
    std::cin >> nisab;
    std::cout << localizer->translate("enter_zakat_rate") << " (" << localizer->translate("example_2.5_percent") << "): ";
    std::cin >> zakatRate;

    ZakatCalculator calculator;
    return calculator.calculate(totalWealth, nisab, zakatRate);
}

std::string UserInterface::handleSadaqahCalculation() {
    double income, sadaqahRate;
    std::cout << localizer->translate("enter_annual_income") << ": ";
    std::cin >> income;
    std::cout << localizer->translate("enter_sadaqah_rate") << " (" << localizer->translate("example_10_percent") << "): ";
    std::cin >> sadaqahRate;

    SadaqahCalculator calculator;
    return calculator.calculate(income, sadaqahRate);
}
