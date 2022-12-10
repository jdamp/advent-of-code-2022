#include "day04.hpp"

int main () {
    auto lines  = AOCTools::parseFile("../../data/day04/input.txt");
    std::cout << "Day04 Part1 solution: " << solveDay04Part1(lines) << "\n";
    std::cout << "Day04 Part2 solution: " << solveDay04Part2(lines) << "\n";
}