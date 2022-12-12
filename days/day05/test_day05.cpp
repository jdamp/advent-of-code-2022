#include "day05.hpp"

#include <gtest/gtest.h>

TEST(SupplyStackTest, testCrates) {
    std::stack<char> stack1({'Z', 'N'});
    std::stack<char> stack2({'M', 'C', 'D'});
    std::stack<char> stack3({'P'});
    std::vector<std::stack<char>> stacks {stack1, stack2, stack3};

    auto fromStack = SupplyStacks(stacks);
    std::vector<std::string> testInput{
        "    [D]    ",
        "[N] [C]    ",
        "[Z] [M] [P]",
        " 1   2   3 "};

    auto fromString = SupplyStacks(testInput);
    ASSERT_EQ(fromStack, fromString);
    fromString.moveCrates(Instruction(1, 2, 1));
    fromString.moveCrates(Instruction(3, 1, 3));
    fromString.moveCrates(Instruction(2, 2, 1));
    fromString.moveCrates(Instruction(1, 1, 2));

    ASSERT_EQ(fromString.getStack(3), std::stack<char>({'P', 'D', 'N', 'Z'}));

    std::vector<std::string> testInstructions {
        "move 1 from 2 to 1",
        "move 3 from 1 to 3",
        "move 2 from 2 to 1",
        "move 1 from 1 to 2"
    };

    auto fromString2 = SupplyStacks(testInput);
    auto instructions = parseLines(testInstructions);
    fromString2.moveCrates(instructions);

    ASSERT_EQ(fromString, fromString2);

    ASSERT_EQ(solveDay05Part1(testInput, testInstructions), "CMZ");
}