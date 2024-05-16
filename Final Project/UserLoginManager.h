#ifndef USER_LOGIN_MANAGER_H
#define USER_LOGIN_MANAGER_H

#include <string>
#include <vector>

struct UserLogin {
    std::string username;
    std::string password;
};

class UserLoginManager {
public:
    static std::vector<UserLogin> readUserLoginsFromFile(const std::string& filename);
    static void writeUserLoginToFile(const UserLogin& login, const std::string& filename);
};

#endif // USER_LOGIN_MANAGER_H
