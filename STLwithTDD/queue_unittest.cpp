#include "gtest/gtest.h"
#include "../mySTL/inc/Queue.h"

class QueueTests :public ::testing::Test {
protected:
	Queue q = Queue(10);
};
TEST_F(QueueTests, canPushOneElement) {
	q.push(1);
	int size = q.size();
	ASSERT_EQ(1, size);
}

TEST_F(QueueTests, canPushMultipleElements) {
	q.push(1);
	q.push(2);
	q.push(3);
	int size = q.size();
	ASSERT_EQ(3, size);
}

TEST_F(QueueTests, canGetFront) {
	q.push(1);
	ASSERT_EQ(1, q.front());
	q.push(2);
	ASSERT_EQ(1, q.front());
}

TEST_F(QueueTests, canPopAndGetFront) {
	q.push(1);
	ASSERT_EQ(1, q.front());
	q.push(2);
	ASSERT_EQ(1, q.front());
	q.pop();
	ASSERT_EQ(2, q.front());
}

TEST_F(QueueTests, canEmptyStatus) {
	ASSERT_TRUE(q.isEmpty());
	q.push(1);
	ASSERT_FALSE(q.isEmpty());
	q.pop();
	ASSERT_TRUE(q.isEmpty());
}