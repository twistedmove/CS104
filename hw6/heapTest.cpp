#include "gtest/gtest.h"
#include "heap.h"
#include <functional>

class intHeapTest : public testing::Test
{
protected:
  intHeapTest() : 
  binaryMinIntHeap(2, std::less<int>()), 
  binaryMaxIntHeap(2, std::greater<int>()), 
  trinaryMinIntHeap(3, std::less<int>()), 
  trinaryMaxIntHeap(3, std::greater<int>())
  {}

  Heap<int, std::less<int> > binaryMinIntHeap;
  Heap<int, std::greater<int> > binaryMaxIntHeap;
  Heap<int, std::less<int> > trinaryMinIntHeap;
  Heap<int, std::greater<int> > trinaryMaxIntHeap;
};

TEST_F(intHeapTest, emptyAndTopTest)
{
  EXPECT_TRUE(binaryMinIntHeap.empty());
  EXPECT_TRUE(binaryMaxIntHeap.empty());
  EXPECT_TRUE(trinaryMinIntHeap.empty());
  EXPECT_TRUE(trinaryMaxIntHeap.empty());

  EXPECT_ANY_THROW(binaryMinIntHeap.top());
  EXPECT_ANY_THROW(binaryMaxIntHeap.top());
  EXPECT_ANY_THROW(trinaryMinIntHeap.top());
  EXPECT_ANY_THROW(trinaryMaxIntHeap.top());

  binaryMinIntHeap.push(1);
  binaryMaxIntHeap.push(20);
  trinaryMinIntHeap.push(-6);
  trinaryMaxIntHeap.push(1000);

  EXPECT_FALSE(binaryMinIntHeap.empty());
  EXPECT_FALSE(binaryMaxIntHeap.empty());
  EXPECT_FALSE(trinaryMinIntHeap.empty());
  EXPECT_FALSE(trinaryMaxIntHeap.empty());

  EXPECT_EQ(binaryMinIntHeap.top(), 1);
  EXPECT_EQ(binaryMaxIntHeap.top(), 20);
  EXPECT_EQ(trinaryMinIntHeap.top(), -6);
  EXPECT_EQ(trinaryMaxIntHeap.top(), 1000);
}

TEST_F(intHeapTest, pushTest)
{
  binaryMinIntHeap.push(5);
  EXPECT_EQ(binaryMinIntHeap.top(), 5);
  binaryMinIntHeap.push(10);
  EXPECT_EQ(binaryMinIntHeap.top(), 5);
  binaryMinIntHeap.push(1);
  EXPECT_EQ(binaryMinIntHeap.top(), 1);
  binaryMinIntHeap.push(-7);
  EXPECT_EQ(binaryMinIntHeap.top(), -7);
  binaryMinIntHeap.push(42);
  EXPECT_EQ(binaryMinIntHeap.top(), -7);
  binaryMinIntHeap.push(6);
  EXPECT_EQ(binaryMinIntHeap.top(), -7);
  binaryMinIntHeap.push(-11);
  EXPECT_EQ(binaryMinIntHeap.top(), -11);
  binaryMinIntHeap.push(5);
  EXPECT_EQ(binaryMinIntHeap.top(), -11);

  binaryMaxIntHeap.push(0);
  EXPECT_EQ(binaryMaxIntHeap.top(), 0);
  binaryMaxIntHeap.push(-5);
  EXPECT_EQ(binaryMaxIntHeap.top(), 0);
  binaryMaxIntHeap.push(13);
  EXPECT_EQ(binaryMaxIntHeap.top(), 13);
  binaryMaxIntHeap.push(4);
  EXPECT_EQ(binaryMaxIntHeap.top(), 13);
  binaryMaxIntHeap.push(-20);
  EXPECT_EQ(binaryMaxIntHeap.top(), 13);
  binaryMaxIntHeap.push(47);
  EXPECT_EQ(binaryMaxIntHeap.top(), 47);
  binaryMaxIntHeap.push(84);
  EXPECT_EQ(binaryMaxIntHeap.top(), 84);
  binaryMaxIntHeap.push(0);
  EXPECT_EQ(binaryMaxIntHeap.top(), 84);

  trinaryMinIntHeap.push(9);
  EXPECT_EQ(trinaryMinIntHeap.top(), 9);
  trinaryMinIntHeap.push(15);
  EXPECT_EQ(trinaryMinIntHeap.top(), 9);
  trinaryMinIntHeap.push(11);
  EXPECT_EQ(trinaryMinIntHeap.top(), 9);
  trinaryMinIntHeap.push(6);
  EXPECT_EQ(trinaryMinIntHeap.top(), 6);
  trinaryMinIntHeap.push(0);
  EXPECT_EQ(trinaryMinIntHeap.top(), 0);
  trinaryMinIntHeap.push(33);
  EXPECT_EQ(trinaryMinIntHeap.top(), 0);
  trinaryMinIntHeap.push(-8);
  EXPECT_EQ(trinaryMinIntHeap.top(), -8);
  trinaryMinIntHeap.push(9);
  EXPECT_EQ(trinaryMinIntHeap.top(), -8);

  trinaryMaxIntHeap.push(100);
  EXPECT_EQ(trinaryMaxIntHeap.top(), 100);
  trinaryMaxIntHeap.push(50);
  EXPECT_EQ(trinaryMaxIntHeap.top(), 100);
  trinaryMaxIntHeap.push(75);
  EXPECT_EQ(trinaryMaxIntHeap.top(), 100);
  trinaryMaxIntHeap.push(200);
  EXPECT_EQ(trinaryMaxIntHeap.top(), 200);
  trinaryMaxIntHeap.push(300);
  EXPECT_EQ(trinaryMaxIntHeap.top(), 300);
  trinaryMaxIntHeap.push(-15);
  EXPECT_EQ(trinaryMaxIntHeap.top(), 300);
  trinaryMaxIntHeap.push(777);
  EXPECT_EQ(trinaryMaxIntHeap.top(), 777);
  trinaryMaxIntHeap.push(100);
  EXPECT_EQ(trinaryMaxIntHeap.top(), 777);
}

TEST_F(intHeapTest, popTest)
{
  EXPECT_ANY_THROW(binaryMinIntHeap.pop());
  EXPECT_ANY_THROW(binaryMaxIntHeap.pop());
  EXPECT_ANY_THROW(trinaryMinIntHeap.pop());
  EXPECT_ANY_THROW(trinaryMaxIntHeap.pop());

  binaryMinIntHeap.push(5);
  binaryMinIntHeap.push(10);
  binaryMinIntHeap.push(1);
  binaryMinIntHeap.push(-7);
  binaryMinIntHeap.push(42);
  binaryMinIntHeap.push(6);
  binaryMinIntHeap.push(-11);
  binaryMinIntHeap.push(5);

  binaryMinIntHeap.pop();
  EXPECT_EQ(binaryMinIntHeap.top(), -7);
  binaryMinIntHeap.pop();
  EXPECT_EQ(binaryMinIntHeap.top(), 1);
  binaryMinIntHeap.pop();
  EXPECT_EQ(binaryMinIntHeap.top(), 5);
  binaryMinIntHeap.pop();
  EXPECT_EQ(binaryMinIntHeap.top(), 5);
  binaryMinIntHeap.pop();
  EXPECT_EQ(binaryMinIntHeap.top(), 6);
  binaryMinIntHeap.pop();
  EXPECT_EQ(binaryMinIntHeap.top(), 10);
  binaryMinIntHeap.pop();
  EXPECT_EQ(binaryMinIntHeap.top(), 42);
  binaryMinIntHeap.pop();
  EXPECT_TRUE(binaryMinIntHeap.empty());

  binaryMaxIntHeap.push(0);
  binaryMaxIntHeap.push(-5);
  binaryMaxIntHeap.push(13);
  binaryMaxIntHeap.push(4);
  binaryMaxIntHeap.push(-20);
  binaryMaxIntHeap.push(47);
  binaryMaxIntHeap.push(84);
  binaryMaxIntHeap.push(0);

  binaryMaxIntHeap.pop();
  EXPECT_EQ(binaryMaxIntHeap.top(), 47);
  binaryMaxIntHeap.pop();
  EXPECT_EQ(binaryMaxIntHeap.top(), 13);
  binaryMaxIntHeap.pop();
  EXPECT_EQ(binaryMaxIntHeap.top(), 4);
  binaryMaxIntHeap.pop();
  EXPECT_EQ(binaryMaxIntHeap.top(), 0);
  binaryMaxIntHeap.pop();
  EXPECT_EQ(binaryMaxIntHeap.top(), 0);
  binaryMaxIntHeap.pop();
  EXPECT_EQ(binaryMaxIntHeap.top(), -5);
  binaryMaxIntHeap.pop();
  EXPECT_EQ(binaryMaxIntHeap.top(), -20);
  binaryMaxIntHeap.pop();
  EXPECT_TRUE(binaryMaxIntHeap.empty());

  trinaryMinIntHeap.push(9);
  trinaryMinIntHeap.push(15);
  trinaryMinIntHeap.push(11);
  trinaryMinIntHeap.push(6);
  trinaryMinIntHeap.push(0);
  trinaryMinIntHeap.push(33);
  trinaryMinIntHeap.push(-8);
  trinaryMinIntHeap.push(9);

  trinaryMinIntHeap.pop();
  EXPECT_EQ(trinaryMinIntHeap.top(), 0);
  trinaryMinIntHeap.pop();
  EXPECT_EQ(trinaryMinIntHeap.top(), 6);
  trinaryMinIntHeap.pop();
  EXPECT_EQ(trinaryMinIntHeap.top(), 9);
  trinaryMinIntHeap.pop();
  EXPECT_EQ(trinaryMinIntHeap.top(), 9);
  trinaryMinIntHeap.pop();
  EXPECT_EQ(trinaryMinIntHeap.top(), 11);
  trinaryMinIntHeap.pop();
  EXPECT_EQ(trinaryMinIntHeap.top(), 15);
  trinaryMinIntHeap.pop();
  EXPECT_EQ(trinaryMinIntHeap.top(), 33);
  trinaryMinIntHeap.pop();
  EXPECT_TRUE(trinaryMinIntHeap.empty());

  trinaryMaxIntHeap.push(100);
  trinaryMaxIntHeap.push(50);
  trinaryMaxIntHeap.push(75);
  trinaryMaxIntHeap.push(200);
  trinaryMaxIntHeap.push(300);
  trinaryMaxIntHeap.push(-15);
  trinaryMaxIntHeap.push(777);
  trinaryMaxIntHeap.push(100);

  trinaryMaxIntHeap.pop();
  EXPECT_EQ(trinaryMaxIntHeap.top(), 300);
  trinaryMaxIntHeap.pop();
  EXPECT_EQ(trinaryMaxIntHeap.top(), 200);
  trinaryMaxIntHeap.pop();
  EXPECT_EQ(trinaryMaxIntHeap.top(), 100);
  trinaryMaxIntHeap.pop();
  EXPECT_EQ(trinaryMaxIntHeap.top(), 100);
  trinaryMaxIntHeap.pop();
  EXPECT_EQ(trinaryMaxIntHeap.top(), 75);
  trinaryMaxIntHeap.pop();
  EXPECT_EQ(trinaryMaxIntHeap.top(), 50);
  trinaryMaxIntHeap.pop();
  EXPECT_EQ(trinaryMaxIntHeap.top(), -15);
  trinaryMaxIntHeap.pop();
  EXPECT_TRUE(trinaryMaxIntHeap.empty());
}