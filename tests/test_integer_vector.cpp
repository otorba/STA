#include "gtest/gtest.h"
#include "integer_vector.hpp"

// Test the default constructor
TEST(IntegerVectorTest, DefaultConstructor)
{
	IntegerVector vec;
	EXPECT_EQ(vec.size(), 0);
	EXPECT_TRUE(vec.empty());
}

// Test the parameterized constructor
TEST(IntegerVectorTest, ParameterizedConstructor)
{
	IntegerVector vec(10);
	EXPECT_EQ(vec.size(), 0);
	EXPECT_TRUE(vec.empty());
}

// Test push_back and size
TEST(IntegerVectorTest, PushBackAndSize)
{
	IntegerVector vec;
	vec.push_back(1);
	vec.push_back(2);
	EXPECT_EQ(vec.size(), 2);
	EXPECT_FALSE(vec.empty());
}

// Test pop_back
TEST(IntegerVectorTest, PopBack)
{
	IntegerVector vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.pop_back();
	EXPECT_EQ(vec.size(), 1);
	EXPECT_EQ(vec.at(0), 1);
}

// Test at
TEST(IntegerVectorTest, At)
{
	IntegerVector vec;
	vec.push_back(1);
	vec.push_back(2);
	EXPECT_EQ(vec.at(0), 1);
	EXPECT_EQ(vec.at(1), 2);
}

// Test clear
TEST(IntegerVectorTest, Clear)
{
	IntegerVector vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.clear();
	EXPECT_EQ(vec.size(), 0);
	EXPECT_TRUE(vec.empty());
}