#include "day03.hpp"

#include <gtest/gtest.h>

#include <vector>


TEST(RucksackTest, testSetup) {
    std::vector<std::string> testInput {
        "vJrwpWtwJgWrhcsFMMfFFhFp",
        "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
        "PmmdzqPrVvPwwTWBwg",
        "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
        "ttgJtRGJQctTZtZT",
        "CrZsJsPPZsGzwwsLwLmpwMDw"
    };
    std::vector<Rucksack> testRucksacks;
    for (auto const& line: testInput){
        testRucksacks.emplace_back(Rucksack(line));
    }
    ASSERT_EQ(testRucksacks[0].getFirstCompartment(), Compartment("vJrwpWtwJgWr"));
    ASSERT_EQ(testRucksacks[0].getSecondCompartment(), Compartment("hcsFMMfFFhFp"));
    std::set<char> items = {'v','J','r','w','p','W','t','g'};
    ASSERT_EQ(testRucksacks[0].getFirstCompartment().getAsSet(), items);

    ASSERT_EQ(testRucksacks[1].getFirstCompartment(), Compartment("jqHRNqRjqzjGDLGL"));
    ASSERT_EQ(testRucksacks[1].getSecondCompartment(), Compartment("rsFMfFZSrLrFZsSL"));

    ASSERT_EQ(testRucksacks[0].calculateScore(), 16);
    ASSERT_EQ(testRucksacks[1].calculateScore(), 38);
    ASSERT_EQ(testRucksacks[2].calculateScore(), 42);
    ASSERT_EQ(testRucksacks[3].calculateScore(), 22);
    ASSERT_EQ(testRucksacks[4].calculateScore(), 20);
    ASSERT_EQ(testRucksacks[5].calculateScore(), 19);


    ASSERT_EQ(solveDay03Part1(testRucksacks), 157);

    ASSERT_EQ(solveDay03Part2(testRucksacks), 70);

}

TEST(RucksackTest, testPriority) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int letterIndex = 0; letterIndex < alphabet.size(); letterIndex++) {
        char letter = alphabet[letterIndex];
        ASSERT_EQ(getPriority(letter), 1+letterIndex);
        ASSERT_EQ(getPriority(toupper(letter)), 26+1+letterIndex);
    }

}