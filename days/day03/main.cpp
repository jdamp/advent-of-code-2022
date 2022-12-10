#include "day03.hpp"

#include <iostream>

int main() {
    auto rucksacks = Rucksack::fromFile("../../data/day03/input.txt");
    std::cout << "Day03 Part1 solution: " << solveDay03Part1(rucksacks) << "\n";
    std::cout << "Day03 Part2 solution: " << solveDay03Part2(rucksacks) << "\n";
}