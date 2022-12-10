#pragma once

#include <set>
#include <string>
#include <string_view>
#include <vector>


int getPriority(char item);


class Compartment {
    public:
        explicit Compartment(std::string_view raw);
        friend bool operator==(Compartment const&, Compartment const&) = default;
        std::set<char> getAsSet() const;
    private:
        std::string contents;
        //std::set<char> items;
};

class Rucksack {
    public:
        static std::vector<Rucksack> fromFile(std::string_view file);
        explicit Rucksack(std::string_view line);
        
        int calculateScore() const;
        std::set<char> getAsSet() const;

        Compartment getFirstCompartment() const;
        Compartment getSecondCompartment() const;
    private:
        std::string items;
        Compartment firstCompartment;
        Compartment secondCompartment;
};

int commonItems(std::vector<Rucksack> rucksacks);

int solveDay03Part1(std::vector<Rucksack> rucksacks);
int solveDay03Part2(std::vector<Rucksack> rucksacks);