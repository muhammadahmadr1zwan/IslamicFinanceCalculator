#ifndef LOCALIZATION_MANAGER_H
#define LOCALIZATION_MANAGER_H

#include <map>
#include <string>

class LocalizationManager {
private:
    std::map<std::string, std::map<std::string, std::string>> translations;
    std::string currentLanguage;

public:
    LocalizationManager();
    void setLanguage(const std::string& language);
    std::string translate(const std::string& key) const;
    void addTranslation(const std::string& language, const std::string& key, const std::string& translation);
};

#endif // LOCALIZATION_MANAGER_H
