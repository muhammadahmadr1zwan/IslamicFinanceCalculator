#ifndef EXPORT_TOOL_H
#define EXPORT_TOOL_H

#include <string>
#include <vector>

class ExportTool {
public:
    bool exportToCSV(const std::string& filename, const std::vector<std::vector<std::string>>& data);
};

#endif // EXPORT_TOOL_H
