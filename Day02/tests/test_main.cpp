#include "../functions.h"
#include <gtest/gtest.h>

// ---------------------------------------------------------
// Part 1
// ---------------------------------------------------------

TEST(razcleniRangesTest, BasicParsing) {
    std::string line = "11-22,95-115,998-1012";

    auto ranges = razcleniRanges(line);

    ASSERT_EQ(ranges.size(), 3);

    EXPECT_EQ(ranges[0].first, 11);
    EXPECT_EQ(ranges[0].second, 22);

    EXPECT_EQ(ranges[1].first, 95);
    EXPECT_EQ(ranges[1].second, 115);

    EXPECT_EQ(ranges[2].first, 998);
    EXPECT_EQ(ranges[2].second, 1012);
}

TEST(IsRepeatedPatternTest, SimpleRepeats) {
    EXPECT_TRUE(isRepeatedPattern(11));
    EXPECT_TRUE(isRepeatedPattern(22));
    EXPECT_TRUE(isRepeatedPattern(55));
    EXPECT_TRUE(isRepeatedPattern(6464));
    EXPECT_TRUE(isRepeatedPattern(123123));
}

TEST(FullExampleTest, FromPuzzleDescription) {
    std::string line =
        "11-22,95-115,998-1012,1188511880-1188511890,222220-222224,"
        "1698522-1698528,446443-446449,38593856-38593862,565653-565659,"
        "824824821-824824827,2121212118-2121212124";

    auto ranges = razcleniRanges(line);
    auto invalid = findAllInvalidIDs(ranges);

    EXPECT_EQ(sumIDs(invalid), 1227775554);
}

TEST(SumIDsTest, Basic) {
    std::vector<long long> ids = {1, 2, 3, 10};
    EXPECT_EQ(sumIDs(ids), 16);
}

// ---------------------------------------------------------
// Part 2
// ---------------------------------------------------------

TEST(RepeatedSubstringPart2, SimpleRepeats) {
    EXPECT_TRUE(isRepeatedSubstringAtLeastTwice("11"));       
    EXPECT_TRUE(isRepeatedSubstringAtLeastTwice("222222"));
    EXPECT_TRUE(isRepeatedSubstringAtLeastTwice("123123"));
    EXPECT_TRUE(isRepeatedSubstringAtLeastTwice("121212"));
}

TEST(RepeatedSubstringPart2, LongerRepeats) {
    EXPECT_TRUE(isRepeatedSubstringAtLeastTwice("12341234"));
    EXPECT_TRUE(isRepeatedSubstringAtLeastTwice("1111111"));
}

TEST(RepeatedSubstringPart2, NotRepeats) {
    EXPECT_FALSE(isRepeatedSubstringAtLeastTwice("12345"));
    EXPECT_FALSE(isRepeatedSubstringAtLeastTwice("12131"));
    EXPECT_FALSE(isRepeatedSubstringAtLeastTwice("101"));
    EXPECT_FALSE(isRepeatedSubstringAtLeastTwice("123124"));
}

TEST(SumInvalidIDsPart2, FullExampleFromPuzzle) {
    std::vector<std::pair<long long,long long>> ranges = {
        {11,22},
        {95,115},
        {998,1012},
        {1188511880,1188511890},
        {222220,222224},
        {1698522,1698528},
        {446443,446449},
        {38593856,38593862},
        {565653,565659},
        {824824821,824824827},
        {2121212118,2121212124}
    };

    long long result = sumInvalidIDsPart2(ranges);

    EXPECT_EQ(result, 4174379265);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
