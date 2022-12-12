#include "day05.hpp"
#include "tools.h"

int main() {
    auto lines  = AOCTools::parseFile("../../data/day05/input.txt");
    std::vector<std::string> setup, instructions;
    int readMode = 0;
    for (auto const& line: lines) {
        if (line.empty()) {
            readMode = 1;
            continue;
        }
        if(readMode == 1) {
            instructions.push_back(line);
        }
        else {
            setup.push_back(line);
        }
    }    
    std::cout << "Day05 Part1 solution: " << solveDay05Part1(setup, instructions) << "\n";
}