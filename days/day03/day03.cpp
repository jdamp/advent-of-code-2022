#include "day03.hpp"
#include "tools.h"

#include <algorithm>
#include <iostream>
#include <numeric>

int getPriority(char item) {
    if (item >= 'a' and item <= 'z') {
        return static_cast<int>(item - 'a' + 1);
    }
    else if (item >= 'A' and item <= 'Z') {
        return static_cast<int>(item - 'A' + 1 + 26);
    }
    return 0;
}

Compartment::Compartment(std::string_view raw) : contents(raw) {};

std::set<char> Compartment::getAsSet() const{
    return std::set<char>(this->contents.begin(), this->contents.end());
}

Rucksack::Rucksack(std::string_view line) :
    firstCompartment(line.substr(0, line.size()/2)),
    secondCompartment(line.substr(line.size()/2)),
    items(line) 
    {}
        

std::vector<Rucksack> Rucksack::fromFile(std::string_view file) {
    std::vector<Rucksack> rucksacks;
    auto input = AOCTools::parseFile("../../data/day03/input.txt");
    for (std::string_view line: input) {
        rucksacks.emplace_back(Rucksack(line));
    }
    return rucksacks;
}

Compartment Rucksack::getFirstCompartment() const{
    return firstCompartment;
};
Compartment Rucksack::getSecondCompartment() const{
    return secondCompartment;
}

std::set<char> Rucksack::getAsSet() const {
    auto firstHalf = getFirstCompartment().getAsSet();
    firstHalf.merge(getSecondCompartment().getAsSet());
    return firstHalf;
}

int Rucksack::calculateScore() const{
    auto compartmentUnion = AOCTools::setUnion(getFirstCompartment().getAsSet(), getSecondCompartment().getAsSet());
    int score = 0;
    for (auto item: compartmentUnion) {
        score += getPriority(item);
    }
    return score;
}

int solveDay03Part1(std::vector<Rucksack> rucksacks) {
    int score = 0;
    for (auto const& rucksack: rucksacks) {
        score += rucksack.calculateScore();
    }
    return score;
}

int solveDay03Part2(std::vector<Rucksack> rucksacks) {
    int score = 0;
    for (int iTriple = 0; iTriple < rucksacks.size()/3; iTriple++) {
        std::vector<Rucksack> triplet(rucksacks.begin() + 3*iTriple, rucksacks.begin() + 3*(iTriple+1));
        std::vector<std::set<char>> sets(triplet.size());
        std::transform(triplet.begin(), triplet.end(), sets.begin(), [] (Rucksack r) {return r.getAsSet();});
        auto setUnion = std::reduce(sets.begin(), sets.end(), *sets.begin(), 
                                    [](auto s1, auto s2) {return AOCTools::setUnion(s1, s2);});
        score += getPriority(*setUnion.begin());
    }
    return score;
}