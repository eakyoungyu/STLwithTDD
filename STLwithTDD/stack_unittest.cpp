#include "gtest/gtest.h"
#include "../mySTL/inc/Stack.h"

class StackTests : public ::testing::Test {
protected:
	Stack stack = Stack(100);
};

TEST_F(StackTests, canPushAndPopOneElement) {
	stack.push(1);
	int ret = stack.top();
	stack.pop();
	ASSERT_EQ(1, ret);
}
TEST_F(StackTests, canPushAndPopMultipleElementsInLIFO) {
	stack.push(1);
	stack.push(2);
	int ret = stack.top();
	stack.pop();
	ASSERT_EQ(2, ret);
	ret = stack.top();
	stack.pop();
	ASSERT_EQ(1, ret);
}
TEST_F(StackTests, canGetSize) {
	stack.push(1);
	stack.push(2);
	int size = stack.size();
	ASSERT_EQ(2, size);
}

TEST_F(StackTests, canGetEmptyStatus) {
	ASSERT_TRUE(stack.is_empty());
	stack.push(1);
	ASSERT_FALSE(stack.is_empty());
	stack.pop();
	ASSERT_TRUE(stack.is_empty());
}