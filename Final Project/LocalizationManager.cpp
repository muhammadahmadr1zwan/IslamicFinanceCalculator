#include "LocalizationManager.h"
#include <iostream>

LocalizationManager::LocalizationManager() {
    translations["English"] = {
        {"main_menu", "Main Menu"},
        {"user_menu", "User Menu"},
        {"login", "Login"},
	{"enter_username", "Enter Username"},
	{"enter_password", "Enter Password"},
	{"example_15_percent", "e.g. 15%"},
	{"example_5_percent", "e.g. 5%"},
	{"in_months", "in months"},
	{"example_1.2", "e.g. 1.2"},
	{"language_changed", "Language Changed"},
	{"minimum_amount", "Minimum Amount"},
	{"example_2.5_percent", "e.g. 2.5%"},
	{"example_10_percent", "e.g. 10%"},
	{"enter_file_name", "Enter the file name"},
	{"enter_language", "Enter language (English or Spanish)"},
        {"sign_up", "Sign Up"},
        {"change_language", "Change Language"},
        {"exit", "Exit"},
        {"choose_username", "Choose Username"},
        {"set_password", "Set Password"},
        {"registration_successful", "Registration Successful"},
        {"please_login", "Please Login"},
        {"invalid_username_or_password", "Invalid Username or Password"},
        {"username_taken", "Username is already taken"},
        {"login_successful", "Login Successful"},
        {"exiting_application", "Exiting Application"},
        {"invalid_option", "Invalid Option"},
        {"calc_options", "Calculation Options"},
        {"murabaha_calculator", "Murabaha Calculator"},
        {"ijara_calculator", "Ijara Calculator"},
        {"mudaraba_calculator", "Mudaraba Calculator"},
        {"zakat_calculator", "Zakat Calculator"},
        {"sadaqah_calculator", "Sadaqah Calculator"},
        {"enter_choice", "Enter your choice"},
        {"enter_purchase_price", "Enter Purchase Price"},
        {"enter_profit_margin", "Enter Profit Margin"},
        {"enter_admin_fees", "Enter Admin Fees"},
        {"enter_tax_rate", "Enter Tax Rate"},
        {"enter_asset_value", "Enter Asset Value"},
        {"enter_lease_term", "Enter Lease Term"},
        {"enter_monthly_maintenance_cost", "Enter Monthly Maintenance Cost"},
        {"enter_monthly_insurance_cost", "Enter Monthly Insurance Cost"},
        {"enter_total_investment", "Enter Total Investment"},
        {"enter_profit", "Enter Profit"},
        {"enter_performance_ratio", "Enter Performance Ratio"},
        {"enter_total_wealth", "Enter Total Wealth"},
	{"export_result_question", "Would you like to export the calculation result? (yes/no)"},
        {"enter_nisab", "Enter Nisab"},
        {"enter_zakat_rate", "Enter Zakat Rate"},
        {"enter_annual_income", "Enter Annual Income"},
        {"enter_sadaqah_rate", "Enter Sadaqah Rate"},
        {"export_success", "Export successful"},
        {"export_declined", "Export declined"},
        {"login_required", "Login is required to access this feature"},
        {"user_menu_displayed", "User Menu Displayed"},
        {"return_to_main_menu", "Would you like to return to the main menu? (yes/no)"}
    };

    translations["Spanish"] = {
        {"main_menu", "Menú Principal"},
        {"user_menu", "Menú de Usuario"},
        {"login", "Inicio de Sesión"},
	{"enter_language", "Introduzca el idioma (Inglés or Español)"}, // Spanish translation
	{"enter_file_name", "Introduzca el nombre del archivo"},
        {"sign_up", "Registrarse"},
        {"change_language", "Cambiar Idioma"},
        {"exit", "Salir"},
	{"enter_username", "Ingrese el Nombre de Usuario"},
    	{"enter_password", "Ingrese la Contraseña"},
    	{"example_15_percent", "e.g. 15%"},
	{"language_changed", "Idioma cambiado"},  // Spanish translation
    	{"example_5_percent", "e.g. 5%"},
    	{"in_months", "en meses"},
	{"enter_file_name", "Introduzca el nombre del archivo"}, // Spanish translation
    	{"example_1.2", "e.g. 1.2"},
    	{"minimum_amount", "Cantidad Mínima"},
    	{"example_2.5_percent", "e.g. 2.5%"},
    	{"example_10_percent", "e.g. 10%"},
        {"choose_username", "Elegir Nombre de Usuario"},
        {"set_password", "Establecer Contraseña"},
        {"registration_successful", "Registro Exitoso"},
        {"please_login", "Por favor, Inicie Sesión"},
        {"invalid_username_or_password", "Nombre de usuario o contraseña inválidos"},
        {"username_taken", "El nombre de usuario ya está en uso"},
        {"login_successful", "Inicio de Sesión Exitoso"},
        {"exiting_application", "Saliendo de la Aplicación"},
        {"invalid_option", "Opción Inválida"},
        {"calc_options", "Opciones de Cálculo"},
        {"murabaha_calculator", "Calculadora de Murabaha"},
        {"ijara_calculator", "Calculadora de Ijara"},
        {"mudaraba_calculator", "Calculadora de Mudaraba"},
        {"zakat_calculator", "Calculadora de Zakat"},
        {"sadaqah_calculator", "Calculadora de Sadaqah"},
        {"enter_choice", "Ingrese su elección"},
        {"enter_purchase_price", "Ingrese el Precio de Compra"},
        {"enter_profit_margin", "Ingrese el Margen de Ganancia (e.g. 15%)"},
        {"enter_admin_fees", "Ingrese las Tarifas Administrativas"},
        {"enter_tax_rate", "Ingrese la Tasa de Impuestos (e.g. 5%)"},
        {"enter_asset_value", "Ingrese el Valor del Activo"},
        {"enter_lease_term", "Ingrese el Plazo del Arrendamiento (en meses)"},
        {"enter_monthly_maintenance_cost", "Ingrese el Costo Mensual de Mantenimiento"},
        {"enter_monthly_insurance_cost", "Ingrese el Costo Mensual de Seguro"},
        {"enter_total_investment", "Ingrese la Inversión Total"},
        {"enter_profit", "Ingrese la Ganancia"},
        {"enter_performance_ratio", "Ingrese el Ratio de Rendimiento (e.g. 1.2)"},
        {"enter_total_wealth", "Ingrese la Riqueza Total"},
        {"enter_nisab", "Ingrese el Nisab (Cantidad Mínima)"},
        {"enter_zakat_rate", "Ingrese la Tasa de Zakat (e.g. 2.5%)"},
        {"enter_annual_income", "Ingrese el Ingreso Anual"},
        {"enter_sadaqah_rate", "Ingrese la Tasa de Sadaqah (e.g. 10%)"},
        {"export_result_question", "¿Desea exportar el resultado del cálculo? (sí/no)"},
        {"export_success", "Exportación exitosa"},
        {"export_declined", "Exportación cancelada"},
        {"login_required", "Es necesario iniciar sesión para acceder a esta función"},
        {"user_menu_displayed", "Menú de Usuario Mostrado"},
        {"return_to_main_menu", "¿Desea regresar al menú principal? (sí/no)"}
    };

    currentLanguage = "English"; // Set default language
}

void LocalizationManager::setLanguage(const std::string& language) {
    if (translations.find(language) != translations.end()) {
        currentLanguage = language;
    } else {
        std::cout << "Language not supported." << std::endl;
    }
}

std::string LocalizationManager::translate(const std::string& key) const {
    auto it = translations.find(currentLanguage);
    if (it != translations.end()) {
        auto innerIt = it->second.find(key);
        if (innerIt != it->second.end()) {
            return innerIt->second;
        }
    }
    return "Translation missing for " + key;
}

void LocalizationManager::addTranslation(const std::string& language, const std::string& key, const std::string& translation) {
    translations[language][key] = translation;
}
