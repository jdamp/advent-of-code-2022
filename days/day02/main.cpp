#include "tools.h"
#include "day02.hpp"
#include <iostream>

int main() {
    auto lines = AOCTools::parseFile("../../data/day02/input.txt");
    auto gamesPart1 = buildGames(lines, translationsPart1);
    auto gamesPart2 = buildGames(lines, translationsPart2);
    std::cout << "Day02 Part01 solution: total score = " << solveDay02(gamesPart1) << "\n";
    std::cout << "Day02 Part02 solution: total score = " << solveDay02(gamesPart2) << "\n";
}