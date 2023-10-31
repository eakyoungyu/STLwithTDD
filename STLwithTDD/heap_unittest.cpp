#include "../mySTL/inc/Heap.h"
#include "gtest/gtest.h"

class HeapTests : public ::testing::Test {
protected:
	Heap heap;
};

TEST_F(HeapTests, canPushOneElement) {
	heap.push(1);
	int size = heap.size();
	ASSERT_EQ(1, size);
}
TEST_F(HeapTests, canPushMultipleElements) {
	heap.push(1);
	heap.push(2);
	int size = heap.size();
	ASSERT_EQ(2, size);
}
TEST_F(HeapTests, canGetEmptyStatus) {
	ASSERT_TRUE(heap.isEmpty());
	heap.push(1);
	ASSERT_FALSE(heap.isEmpty());
}
TEST_F(HeapTests, canGetTopWithAsendingInput) {
	heap.push(1);
	heap.push(3);
	int top = heap.top();
	ASSERT_EQ(1, top);
}
TEST_F(HeapTests, canGetTopWithDesendingInput) {
	heap.push(3);
	heap.push(1);
	int top = heap.top();
	ASSERT_EQ(1, top);
}
TEST_F(HeapTests, canGetTopWithRandomInput) {
	heap.push(3);
	heap.push(2);
	heap.push(1);
	heap.push(7);
	heap.push(9);
	int top = heap.top();
	ASSERT_EQ(1, top);
}
TEST_F(HeapTests, canPop) {
	heap.push(3);
	heap.push(2);
	heap.push(1);
	heap.push(7);
	heap.push(9);
	heap.pop();
	int top = heap.top();
	ASSERT_EQ(2, top);
}
TEST_F(HeapTests, canPopAll) {
	heap.push(3);
	heap.push(2);
	heap.push(1);
	heap.push(9);
	ASSERT_EQ(1, heap.top());
	heap.pop();
	ASSERT_EQ(2, heap.top());
	heap.pop();
	ASSERT_EQ(3, heap.top());
	heap.pop();
	ASSERT_EQ(9, heap.top());
	heap.pop();
	ASSERT_TRUE(heap.isEmpty());
}