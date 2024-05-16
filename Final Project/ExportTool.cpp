#include "ExportTool.h"
#include <iostream>
#include <fstream>
#include <sstream>

bool ExportTool::exportToCSV(const std::string& filename, const std::vector<std::vector<std::string>>& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file for writing: " << filename << std::endl;
        return false;
    }

    for (const auto& row : data) {
        std::ostringstream lineStream;
        for (size_t i = 0; i < row.size(); ++i) {
            std::string entry = row[i];
            // Handle potential commas in the data by encapsulating the field in quotes
            if (entry.find(',') != std::string::npos) {
                entry = "\"" + entry + "\"";
            }
            lineStream << entry;
            if (i < row.size() - 1) lineStream << ",";
        }
        file << lineStream.str() << "\n";
    }

    file.close();
    std::cout << "Data exported to CSV file: " << filename << std::endl;
    return true;
}
