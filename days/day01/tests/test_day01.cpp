#include "day01.h"
#include <gtest/gtest.h>

TEST(day01, testSolution1) {
    std::vector<std::string> test_input {
        "1000", "2000", "3000", "",
        "4000", "",
        "5000", "6000", "",
        "7000", "8000", "9000", "",
        "10000", ""};

    std::vector<int> expected {6000, 4000, 11000, 24000, 10000};
    int maxCalories = 24000;
    std::vector<int> expectedTopThree{24000, 11000, 10000};

    EXPECT_EQ(getCaloriesPerElf(test_input), expected);
    EXPECT_EQ(getMaxCalories(expected), maxCalories);
    EXPECT_EQ(getTopThreeCalories(expected), expectedTopThree);
    EXPECT_EQ(getCaloriesSum(expectedTopThree), 45000);
}