#include "UserInterface.h"
#include <iostream>
#include <limits> // For std::numeric_limits

int main() {
    UserInterface ui;  // Initialize the User Interface

    bool running = true;  // Application state control
    int choice;  // User's menu choice

    while (running) {
        ui.displayMainMenu();  // Display the main menu options
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer

        ui.processMainMenuInput(choice);  // Process input for main menu

        while (ui.isUserLoggedIn()) {
            ui.displayUserMenu();  // Display options for logged-in users
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer

            ui.processUserMenuInput(choice);  // Process input for user menu
        }
    }

    return 0;  // End of the main program
}
