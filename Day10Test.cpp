#include <gtest/gtest.h>
#include "Day10.hpp"
#include <utility>

// Parse a noop
TEST(Day10Test, ParseNoop) {
	Day10 day;
	std::pair<int, int> noop{ 1,0 };
	ASSERT_EQ(noop, day.ParseOperation("noop"));
}

// Parse an operation
TEST(Day10Test, ParseAddx) {
	Day10 day;
	std::pair<int, int> expected{ 2,10 };
	ASSERT_EQ(expected, day.ParseOperation("addx 10"));
}

// Run an add operation
TEST(Day10Test, RunOperationAdd) {
	Day10 day;
	std::pair<int, int> initialCount{ 2, 102 };
	std::pair<int, int> expected{ 4,112 };
	ASSERT_EQ(expected, day.RunOperation("addx 10", initialCount));
}

// Run a noop operation
TEST(Day10Test, RunOperationNoop) {
	Day10 day;
	std::pair<int, int> initialCount{ 2, 102 };
	std::pair<int, int> expected{ 3,102 };
	ASSERT_EQ(expected, day.RunOperation("noop", initialCount));
}

// Run a series of noop operations
TEST(Day10Test, RunOperationNoopSeries) {
	Day10 day;
	std::vector<std::string> series(10, "noop");
	std::pair<int, int> initial{ 8, 10 };
	std::pair<int, int> expected{ 18, 10 };
	ASSERT_EQ(expected, day.RunOperationSeries(series, initial));
}

// Run a series of add operations
TEST(Day10Test, RunOperationAddSeries) {
	Day10 day;
	const int n(7);
	std::vector<std::string> series(n, "addx 8");
	std::pair<int, int> initial{ 8, 10 };
	std::pair<int, int> expected{ initial.first + n * 2, initial.second + n * 8 };
	ASSERT_EQ(expected, day.RunOperationSeries(series, initial));
}

class Day10TestDataTest : public ::testing::Test {
protected:
	void SetUp() override {
		day.ReadFile("C:/r_mills/tinkering/AoC/2022/day10/test.txt");
	}

	Day10 day;
};


// Run a series of add operations
TEST_F(Day10TestDataTest, RunToLimit20) {
	ASSERT_EQ(420, day.RunOperationSeriesToValue(20));
}

// Run a test on given data
TEST_F(Day10TestDataTest, RunToLimit60) {
	ASSERT_EQ(1140, day.RunOperationSeriesToValue(60));
}

// Run a test on given data
TEST_F(Day10TestDataTest, RunToLimit100) {
	ASSERT_EQ(1800, day.RunOperationSeriesToValue(100));
}

// Run a test on given data
TEST_F(Day10TestDataTest, RunToLimit140) {
	ASSERT_EQ(2940, day.RunOperationSeriesToValue(140));
}

// Run a test on given data
TEST_F(Day10TestDataTest, RunToLimit180) {
	ASSERT_EQ(2880, day.RunOperationSeriesToValue(180));
}

// Run a test on given data
TEST_F(Day10TestDataTest, RunToLimit220) {
	ASSERT_EQ(3960, day.RunOperationSeriesToValue(220));
}