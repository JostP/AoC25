#include "../functions.h"
#include <gtest/gtest.h>

// ---------------------------------------------------------
// Part 1
// ---------------------------------------------------------

TEST(AoC2025Day1_Part1, ExampleInput) {
    std::vector<std::string> lines = {
        "L68",
        "L30",
        "R48",
        "L5",
        "R60",
        "L55",
        "L1",
        "L99",
        "R14",
        "L82"
    };

    EXPECT_EQ(countZeroVisits(lines), 3);
}

// Test: noben premik ne zadene nule
TEST(AoC2025Day1_Part1, NoZeroHits) {
    std::vector<std::string> lines = {
        "R1",
        "R2",
        "R3"
    };

    EXPECT_EQ(countZeroVisits(lines), 0);
}

// Test: vedno zadane nulo
TEST(AoC2025Day1_Part1, MultipleZeroHits) {
    std::vector<std::string> lines = {
        "L50",   // 50 -> 0
        "R100",  // 0 -> 0
        "L100"   // 0 -> 0
    };

    EXPECT_EQ(countZeroVisits(lines), 3);
}

// Test: preverjanje negativnega prehoda
TEST(AoC2025Day1_Part1, NegativeWrap) {
    std::vector<std::string> lines = {
        "L60",    // 50 - 60 = -10 → 90
        "R10"    // 90 + 10 = 0
    };

    EXPECT_EQ(countZeroVisits(lines), 1);
}

// Test: veliki preskoki
TEST(AoC2025Day1_Part1, LargeValues) {
    std::vector<std::string> lines = {
        "R300",  // 50 + 300 = 350 → 50
        "L250"   // 50 - 250 = -200 →  -200 + 300 = 100 → 0 (mod 100)
    };

    EXPECT_EQ(countZeroVisits(lines), 1);
}

// ---------------------------------------------------------
// Part 2
// ---------------------------------------------------------

TEST(AoC2025Day1_Part2, ExampleInput) {
    std::vector<std::string> lines = {
        "L68",
        "L30",
        "R48",
        "L5",
        "R60",
        "L55",
        "L1",
        "L99",
        "R14",
        "L82"
    };

    EXPECT_EQ(countZeroClicks(lines), 6);
}

// med potjo gre 10-krat mimo 0
TEST(AoC2025Day1_Part2, LargeMovement) {
    std::vector<std::string> lines = {
        "R1000"
    };

    EXPECT_EQ(countZeroClicks(lines), 10);
}

// negativen prehod, med potjo prečka 0 enkrat
TEST(AoC2025Day1_Part2, NegativeWrap) {
    std::vector<std::string> lines = {
        "L60"
    };

    EXPECT_EQ(countZeroClicks(lines), 1);
}

// mešano
TEST(AoC2025Day1_Part2, MixedMovements) {
    std::vector<std::string> lines = {
        "R50",
        "L150",
        "R99"
    };

    EXPECT_EQ(countZeroClicks(lines), 3);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
