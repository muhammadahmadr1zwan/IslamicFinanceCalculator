#include "UserLoginManager.h"
#include <fstream>
#include <sstream>

std::vector<UserLogin> UserLoginManager::readUserLoginsFromFile(const std::string& filename) {
    std::vector<UserLogin> logins;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string username, password;
        if (std::getline(iss, username, ',') && std::getline(iss, password)) {
            logins.push_back({username, password});
        }
    }
    return logins;
}

void UserLoginManager::writeUserLoginToFile(const UserLogin& login, const std::string& filename) {
    std::ofstream file(filename, std::ios_base::app);
    file << login.username << "," << login.password << "\n";
}
