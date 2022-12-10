#include "day04.hpp"
#include <gtest/gtest.h>


TEST(ElfTest, testPart01) {
    std::vector<std::string> testInput {
        "2-4,6-8",
        "2-3,4-5",
        "5-7,7-9",
        "2-8,3-7",
        "6-6,4-6", 
        "2-6,4-8"
    };

    ElfPair pair1 {ElfRange(2, 4), ElfRange(6, 8)};
    ElfPair pair4 {ElfRange(2, 8), ElfRange(3, 7)};
    ASSERT_EQ(parseLine(testInput[0]), pair1);

    ASSERT_FALSE(checkRangeOverlap(pair1));
    ASSERT_TRUE(checkRangeOverlap(pair4));

    ASSERT_EQ(solveDay04Part1(testInput), 2);
    ASSERT_EQ(solveDay04Part2(testInput), 4);
    std::vector<std::string> testInput2 {
        "51-88,52-87", // yes
        "41-55,22-56",
        "6-74,74-86",
        "51-98,52-86", // yes
        "8-77,3-94", // yes
        "76-76,77-97", // yes
        "29-42,29-35", // yes
        "59-97,60-60", // yes
        "9-86,27-86" // yes
    };

    ASSERT_EQ(solveDay04Part1(testInput2), 7);
}
