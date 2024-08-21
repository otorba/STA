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

// Test the copy constructor
TEST(IntegerVectorTest, CopyConstructor)
{
	IntegerVector vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	IntegerVector vec2(vec1);
	EXPECT_EQ(vec2.size(), 2);
	EXPECT_EQ(vec2.at(0), 1);
	EXPECT_EQ(vec2.at(1), 2);
}

// Test the assignment operator
TEST(IntegerVectorTest, AssignmentOperator)
{
	IntegerVector vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	IntegerVector vec2;
	vec2 = vec1;
	EXPECT_EQ(vec2.size(), 2);
	EXPECT_EQ(vec2.at(0), 1);
	EXPECT_EQ(vec2.at(1), 2);
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

// Test growing
TEST(IntegerVectorTest, Growing)
{
	IntegerVector vec;
	for (int i = 0; i < 100; i++)
	{
		vec.push_back(i);
	}
	EXPECT_EQ(vec.size(), 100);
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

// Test print
TEST(IntegerVectorTest, Print)
{
	IntegerVector vec;
	vec.push_back(1);
	vec.push_back(2);
	std::ostringstream oss;
	std::streambuf *p_cout_streambuf = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf());
	vec.print();
	std::cout.rdbuf(p_cout_streambuf);
	EXPECT_EQ(oss.str(), "1 2 \n");
}

// Test shrinking
TEST(IntegerVectorTest, Shrinking)
{
	IntegerVector vec;
	for (int i = 0; i < 100; i++)
	{
		vec.push_back(i);
	}
	for (int i = 0; i < 90; i++)
	{
		vec.pop_back();
	}
	EXPECT_EQ(vec.size(), 10);
	EXPECT_FALSE(vec.empty());
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