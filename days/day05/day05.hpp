#pragma once

#include <regex>
#include <stack>
#include <string>
#include <vector>


struct Instruction {
    explicit Instruction(std::smatch const& regex_match);
    Instruction(int num, int from, int to);
    int numCrates;
    int sourceCrate;
    int destCrate;
};

Instruction parseLine(std::string const& line);
std::vector<Instruction> parseLines(std::vector<std::string> const& lines);

class SupplyStacks{
    public:
        SupplyStacks(std::vector<std::string> input);
        SupplyStacks(std::vector<std::stack<char>> initStacks);
        
        void moveCrates(Instruction const& inst);
        void moveCrates(std::vector<Instruction> const& insts);
        std::stack<char> getStack(int stackNum);
        void printStack(int stackNum);
        std::string getTopOfStacks();

        friend bool operator==(SupplyStacks const& stacks1, SupplyStacks const& stacks2) = default;
    private:
        std::vector<std::stack<char>> stacks;
};

std::string solveDay05Part1(std::vector<std::string> const& setupLines,
                            std::vector<std::string> const& instructionLines);