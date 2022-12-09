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


std::vector<std::string> AOCTools::splitString(std::string const& str, std::string const& delimiter) {
    size_t last = 0;
    size_t next = 0;
    std::vector<std::string> result;
    while ((next = str.find(delimiter, last)) != std::string::npos) {
        result.push_back(str.substr(last, next-last));
        last = next + 1;
    }
    result.push_back(str.substr(last));
    return result;
}