#include "gtest/gtest.h"
#include "integer_linked_list.hpp"
#include <sstream>

// Helper function to check the console output of Print method
void CheckPrintOutput(const IntegerLinkedList &list, const std::string &expected_output)
{
  std::ostringstream oss;
  std::streambuf *p_cout_streambuf = std::cout.rdbuf();
  std::cout.rdbuf(oss.rdbuf());
  list.Print();
  std::cout.rdbuf(p_cout_streambuf);
  EXPECT_EQ(oss.str(), expected_output);
}

// Test the default constructor
TEST(IntegerLinkedListTest, DefaultConstructor)
{
  IntegerLinkedList list;
  EXPECT_EQ(list.Size(), 0);
  EXPECT_TRUE(list.Empty());
}

// Test PushBack and Size
TEST(IntegerLinkedListTest, PushBackAndSize)
{
  IntegerLinkedList list;
  list.PushBack(1);
  list.PushBack(2);
  EXPECT_EQ(list.Size(), 2);
  EXPECT_FALSE(list.Empty());
  CheckPrintOutput(list, "1 2 ");
}

// Test PushFront and Size
TEST(IntegerLinkedListTest, PushFrontAndSize)
{
  IntegerLinkedList list;
  list.PushFront(1);
  list.PushFront(2);
  EXPECT_EQ(list.Size(), 2);
  EXPECT_FALSE(list.Empty());
  CheckPrintOutput(list, "2 1 ");
}

// Test InsertBefore
TEST(IntegerLinkedListTest, InsertBefore)
{
  IntegerLinkedList list;
  list.PushBack(1);
  list.PushBack(3);
  list.InsertBefore(1, 2);
  EXPECT_EQ(list.Size(), 3);
  CheckPrintOutput(list, "1 2 3 ");
}

// Test InsertAfter
TEST(IntegerLinkedListTest, InsertAfter)
{
  IntegerLinkedList list;
  list.PushBack(1);
  list.PushBack(3);
  list.InsertAfter(0, 2);
  EXPECT_EQ(list.Size(), 3);
  CheckPrintOutput(list, "1 2 3 ");
}

// Test PopBack
TEST(IntegerLinkedListTest, PopBack)
{
  IntegerLinkedList list;
  list.PushBack(1);
  list.PushBack(2);
  list.PopBack();
  EXPECT_EQ(list.Size(), 1);
  CheckPrintOutput(list, "1 ");
}

// Test DeleteAfter
TEST(IntegerLinkedListTest, DeleteAfter)
{
  IntegerLinkedList list;
  list.PushBack(1);
  list.PushBack(2);
  list.PushBack(3);
  list.DeleteAfter(0);
  EXPECT_EQ(list.Size(), 2);
  CheckPrintOutput(list, "1 3 ");
}

// Test DeleteBefore
TEST(IntegerLinkedListTest, DeleteBefore)
{
  IntegerLinkedList list;
  list.PushBack(1);
  list.PushBack(2);
  list.PushBack(3);
  list.DeleteBefore(1);
  EXPECT_EQ(list.Size(), 2);
  CheckPrintOutput(list, "2 3 ");
}

// Test Clear
TEST(IntegerLinkedListTest, Clear)
{
  IntegerLinkedList list;
  list.PushBack(1);
  list.PushBack(2);
  list.Clear();
  EXPECT_EQ(list.Size(), 0);
  EXPECT_TRUE(list.Empty());
  CheckPrintOutput(list, "");
}

// Test Print
TEST(IntegerLinkedListTest, Print)
{
  IntegerLinkedList list;
  list.PushBack(1);
  list.PushBack(2);
  CheckPrintOutput(list, "1 2 ");
}