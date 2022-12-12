#include "day05.hpp"

#include <iostream>
#include <ranges>

Instruction::Instruction(std::smatch const& regex_match) {
    numCrates = std::stoi(regex_match[1]);
    sourceCrate = std::stoi(regex_match[2]);
    destCrate = std::stoi(regex_match[3]);
}

Instruction::Instruction(int num, int from, int to) :
    numCrates(num),
    sourceCrate(from),
    destCrate(to) {}

Instruction parseLine(std::string const& line) {
    std::regex reg("move ([0-9]+) from ([0-9]+) to ([0-9]+)");
    std::smatch match;
    std::regex_match(line, match, reg);
    return Instruction(match);
}


std::vector<Instruction> parseLines(std::vector<std::string> const& lines){
    std::vector<Instruction> allInstructions;
    for (auto const& line: lines) {
        allInstructions.push_back(parseLine(line));
    }
    return allInstructions;
}


SupplyStacks::SupplyStacks(std::vector<std::string> input) {
    auto stackLine = input.back();
    input.pop_back();
    for (size_t pos = 1; pos < stackLine.size(); pos += 4) {
        stacks.emplace_back();        
    }

    for(auto const& line: std::views::reverse(input)) {
        for (size_t stackNum = 0; stackNum < stacks.size(); stackNum++) {
            size_t cratePos = 1 + 4*stackNum;   
            if (std::isalnum(line.at(cratePos))) {               
                stacks.at(stackNum).push(line.at((cratePos)));
            }
        }
    }
}

SupplyStacks::SupplyStacks(std::vector<std::stack<char>> initStacks) :
    stacks(initStacks) {}

void SupplyStacks::moveCrates(Instruction const& inst) {
    for (int i = 0; i < inst.numCrates; i++) {
        auto toMove = stacks.at(inst.sourceCrate - 1).top();
        stacks.at(inst.sourceCrate - 1).pop();
        stacks.at(inst.destCrate - 1).push(toMove);
    }
}

void SupplyStacks::moveCrates(std::vector<Instruction> const& insts) {
    for (auto inst: insts) {
        this->moveCrates(inst);
    }
}

std::stack<char> SupplyStacks::getStack(int stackNum) {
    return stacks.at(stackNum-1);
}


std::string SupplyStacks::getTopOfStacks() {
    std::stringstream topStack;
    for (auto const& stack: stacks) {
        topStack << stack.top();
    }
    return topStack.str();
}


std::string solveDay05Part1(std::vector<std::string> const& setupLines, 
                            std::vector<std::string> const& instructionLines) {
   auto stack = SupplyStacks(setupLines);
   auto instructions = parseLines(instructionLines);
   stack.moveCrates(instructions);
   return stack.getTopOfStacks();
}