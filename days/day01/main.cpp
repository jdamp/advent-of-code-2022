#include "include/day01.h"
#include "tools.h"

#include <iostream>

int main(int argc, char** argv) {
    std::string inputFile{"../../data/day01/input.txt"};
    if (argc > 1) {
        inputFile = argv[1];
    }
    std::vector<std::string> const input = AOCTools::parseFile(inputFile);
    auto caloriesPerElf = getCaloriesPerElf(input);
    std::cout << "Day 01 part 1 solution: Max calories = " << getMaxCalories(caloriesPerElf) << "\n";
    auto topThreeElves = getTopThreeCalories(caloriesPerElf);
    std::cout << "Day 01 part 2 solution: Top three sum = " << getCaloriesSum(topThreeElves) << "\n";
}