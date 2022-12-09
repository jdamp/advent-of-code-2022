#include <gtest/gtest.h>
#include "tools.h"

TEST(AOCToolsTest, split) {
    std::string testStr1 = "I am space delimited";
    std::vector<std::string> strParts1{"I", "am", "space", "delimited"};
    ASSERT_EQ(AOCTools::splitString(testStr1, " "), strParts1);

    std::string testStr2 = "xxx+yyy+zzz";
    std::vector<std::string> strParts2{"xxx", "yyy", "zzz"};
    ASSERT_EQ(AOCTools::splitString(testStr2, "+"), strParts2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}