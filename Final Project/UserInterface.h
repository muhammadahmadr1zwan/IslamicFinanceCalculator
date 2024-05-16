#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "LocalizationManager.h"
#include "MurabahaCalculator.h"
#include "IjaraCalculator.h"
#include "MudarabaCalculator.h"
#include "ZakatCalculator.h"
#include "SadaqahCalculator.h"
#include "UserLoginManager.h"
#include <iostream>
#include <fstream>
#include <string>

class UserInterface {
private:
    LocalizationManager* localizer;
    bool isLoggedIn;
    std::vector<UserLogin> userLogins;

public:
    UserInterface();
    ~UserInterface();

    void displayMainMenu();
    void processMainMenuInput(int choice);
    void login();
    void signUp();
    bool isUsernameTaken(const std::string& username) const;
    void changeLanguage();
    bool isUserLoggedIn() const;
    void displayUserMenu();
    void processUserMenuInput(int choice);

    void askForExport(const std::string& data, const std::string& fileName); // Updated declaration
    void displayCalculationOptions();
    std::string handleMurabahaCalculation();
    std::string handleIjaraCalculation();
    std::string handleMudarabaCalculation();
    std::string handleZakatCalculation();
    std::string handleSadaqahCalculation();
};

#endif
