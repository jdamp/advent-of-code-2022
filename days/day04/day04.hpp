#pragma once

#include "tools.h"

#include <string_view>
#include <utility>
#include <vector>

struct ElfRange{
    int lower;
    int upper;
    bool operator<=>(const ElfRange&) const = default;
};

using ElfPair = std::pair<ElfRange, ElfRange>;

ElfRange buildRange(std::string const& input) {
    auto range = AOCTools::splitString(input, "-");
    return {std::stoi(range[0]), std::stoi(range[1])};
}

ElfPair parseLine(std::string const& line) {
    auto parts = AOCTools::splitString(line, ",");
    auto elf1 = buildRange(parts[0]);
    auto elf2 = buildRange(parts[1]);
    return {elf1, elf2};
}

bool checkRangeContains(ElfPair elves) {
    auto elf1 = elves.first;
    auto elf2 = elves.second;

    if ((elf1.lower >= elf2.lower and elf1.upper <= elf2.upper) or
        (elf2.lower >= elf1.lower and elf2.upper <= elf1.upper)) {
            return true;
        }
    return false;
}

bool checkRangeOverlap(ElfPair elves) {
    auto elf1 = elves.first;
    auto elf2 = elves.second;
    if ((elf1.lower <= elf2.lower and elf1.upper >= elf2.lower) or
        (elf2.lower <= elf1.lower and elf2.upper >= elf1.lower)) {
            return true;
        }
    return false;
}


int solveDay04Part1(std::vector<std::string> const& lines) {
    int count = 0;
    for (auto const& line: lines) {
        auto pair = parseLine(line);
        if (checkRangeContains(pair)) {
            count += 1;
        }
    }
    return count;
}

int solveDay04Part2(std::vector<std::string> const& lines) {
    int count = 0;
    for (auto const& line: lines) {
        auto pair = parseLine(line);
        if (checkRangeOverlap(pair)) {
            count += 1;
        }
    }
    return count;
}