#pragma once

#include <string>
#include <vector>

namespace AOCTools {
    std::vector<std::string> parseFile(std::string const& path);

    std::vector<std::string> splitString(std::string const& str, std::string const& delimiter);

}