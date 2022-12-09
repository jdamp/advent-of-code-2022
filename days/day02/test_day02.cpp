#include "day02.hpp"
#include <gtest/gtest.h>


#include <utility>


class RockPaperScissorTest : public ::testing::Test {
    protected:
        void SetUp() override {
            lines.emplace_back("A Y");
            lines.emplace_back("B X");
            lines.emplace_back("C Z");
        };

    std::vector<std::string> lines;
};

TEST(ScoreTest, Day02) {
    ASSERT_EQ(getChoiceScore(Choice::Rock), 1);
    ASSERT_EQ(getChoiceScore(Choice::Paper), 2);
    ASSERT_EQ(getChoiceScore(Choice::Scissors), 3);

    // If we loose we get no points:
    ASSERT_EQ(getGameScore({Choice::Rock, Choice::Scissors}), 0);
    ASSERT_EQ(getGameScore({Choice::Paper, Choice::Rock}), 0);
    ASSERT_EQ(getGameScore({Choice::Scissors, Choice::Paper}), 0);
    // Draws should get 3 points:
    ASSERT_EQ(getGameScore({Choice::Rock, Choice::Rock}), 3);
    ASSERT_EQ(getGameScore({Choice::Paper, Choice::Paper}), 3);
    ASSERT_EQ(getGameScore({Choice::Scissors, Choice::Scissors}),3);
    //Wins should get us 6 points:
    ASSERT_EQ(getGameScore({Choice::Rock, Choice::Paper}), 6);
    ASSERT_EQ(getGameScore({Choice::Paper, Choice::Scissors}), 6);
    ASSERT_EQ(getGameScore({Choice::Scissors, Choice::Rock}), 6);

}

TEST_F(RockPaperScissorTest, Day02) {
    auto gamesPart1 = buildGames(lines, translationsPart1);
    auto gamesPart2 = buildGames(lines, translationsPart2);
    std::vector<std::pair<Choice, Choice>> expectedGamesPart1 = {
        {Choice::Rock, Choice::Paper},
        {Choice::Paper, Choice::Rock},
        {Choice::Scissors, Choice::Scissors}
    };

    std::vector<std::pair<Choice, Choice>> expectedGamesPart2 = {
        {Choice::Rock, Choice::Rock},
        {Choice::Paper, Choice::Rock},
        {Choice::Scissors, Choice::Rock}
    };
    ASSERT_EQ(gamesPart1, expectedGamesPart1);
    ASSERT_EQ(gamesPart2, expectedGamesPart2);

    ASSERT_EQ(solveDay02(gamesPart1), 15);
    ASSERT_EQ(solveDay02(gamesPart2), 12);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}