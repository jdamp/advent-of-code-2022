#include <fstream>
#include <iostream>

#include "tools.h"

std::vector<std::string> AOCTools::parseFile(const std::string& path) {
    std::vector<std::string> data;
    std::fstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error opening file " << path << "\n";
        return {};
    }
    std::string line;
    while (std::getline(file, line)) {        
        data.push_back(line);
    }
    return data;
}
