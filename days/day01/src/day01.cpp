#include <algorithm>
#include <numeric>

#include "day01.h"


std::vector<int> getCaloriesPerElf(std::vector<std::string> const& input) {
    std::vector<int> calories;
    int currentElf = 0;
    for (auto line: input) {
        if (line.length() != 0) {
            currentElf += std::stoi(line);
        }
        else {
            calories.push_back(currentElf);
            currentElf = 0;
        }
    }
    return calories;
}

int getMaxCalories(std::vector<int> caloriesPerElf) {
    return *std::max_element(caloriesPerElf.begin(), caloriesPerElf.end());
}

std::vector<int> getTopThreeCalories(std::vector<int> caloriesPerElf) {
    std::sort(caloriesPerElf.begin(), caloriesPerElf.end(), std::greater{});
    return std::vector<int>(caloriesPerElf.begin(), caloriesPerElf.begin() + 3);
}

int getCaloriesSum(std::vector<int> caloriesPerElf) {
    return std::reduce(caloriesPerElf.begin(), caloriesPerElf.end());
}