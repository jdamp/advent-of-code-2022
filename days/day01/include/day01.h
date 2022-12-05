#pragma once

#include <ranges>
#include <string>
#include <vector>

std::vector<int> getCaloriesPerElf(std::vector<std::string> const& input);

int getMaxCalories(std::vector<int> const& caloriesPerElf);

std::vector<int> getTopThreeCalories(std::vector<int> caloriesPerElf);

int getCaloriesSum(std::vector<int> const& caloriesPerElf);