#pragma once

#include "tools.h"

#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <vector>

enum class Choice {
    Rock,
    Paper,
    Scissors,
};

enum class Result {
    Win,
    Loss,
    Tie
};

using ChoicePair = std::pair<Choice, Choice>;

std::map<ChoicePair, Result> gameTable = {
    {{Choice::Rock, Choice::Paper}, Result::Win},
    {{Choice::Rock, Choice::Scissors}, Result::Loss},
    {{Choice::Rock, Choice::Rock}, Result::Tie},
    {{Choice::Paper, Choice::Paper}, Result::Tie},
    {{Choice::Paper, Choice::Scissors}, Result::Win},
    {{Choice::Paper, Choice::Rock}, Result::Loss},
    {{Choice::Scissors, Choice::Paper}, Result::Loss},
    {{Choice::Scissors, Choice::Scissors}, Result::Tie},
    {{Choice::Scissors, Choice::Rock}, Result::Win}
};


std::map<std::string, ChoicePair> const translationsPart1 = {
    {"A X", {Choice::Rock, Choice::Rock}},
    {"B X", {Choice::Paper, Choice::Rock}},
    {"C X", {Choice::Scissors, Choice::Rock}},
    {"A Y", {Choice::Rock, Choice::Paper}},
    {"B Y", {Choice::Paper, Choice::Paper}}, 
    {"C Y", {Choice::Scissors, Choice::Paper}},
    {"A Z", {Choice::Rock, Choice::Scissors}},
    {"B Z", {Choice::Paper, Choice::Scissors}},
    {"C Z", {Choice::Scissors, Choice::Scissors}}
};

std::map<std::string, ChoicePair> const translationsPart2 = {
    {"A X", {Choice::Rock, Choice::Scissors}},
    {"B X", {Choice::Paper, Choice::Rock}},
    {"C X", {Choice::Scissors, Choice::Paper}},
    {"A Y", {Choice::Rock, Choice::Rock}},
    {"B Y", {Choice::Paper, Choice::Paper}}, 
    {"C Y", {Choice::Scissors, Choice::Scissors}},
    {"A Z", {Choice::Rock, Choice::Paper}},
    {"B Z", {Choice::Paper, Choice::Scissors}},
    {"C Z", {Choice::Scissors, Choice::Rock}}
};


std::vector<ChoicePair> buildGames(std::vector<std::string> const& input,
                                   std::map<std::string, ChoicePair> const& translations) {
    std::vector<ChoicePair> games;
    for (auto const& line: input) {
        games.emplace_back(translations.at(line));
    }
    return games;
}

Result playGame(ChoicePair game) {
    return gameTable.at(game);
}

uint64_t getChoiceScore(Choice myChoice) {
    if (myChoice == Choice::Rock) {
        return 1;
    }
    else if (myChoice == Choice::Paper) {
        return 2;
    }
    else {
        return 3;
    }
}

uint64_t getGameScore(ChoicePair game) {
    Result gameResult = playGame(game);
    if (gameResult == Result::Loss) {
        return 0;
    }
    else if (gameResult == Result::Tie) {
        return 3;
    }
    else {
        return 6;
    }
}

uint64_t getTotalScore(ChoicePair game) {
    Choice myChoice = game.second;
    return getChoiceScore(myChoice) + getGameScore(game);
}

uint64_t solveDay02(std::vector<ChoicePair> const& games) {
    std::vector<int> scores(games.size());
    std::transform(games.begin(), games.end(), scores.begin(),
        getTotalScore);
    return std::accumulate(scores.begin(), scores.end(), 0);
}