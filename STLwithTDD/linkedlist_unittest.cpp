#include "../mySTL/inc/LinkedList.h"
#include "gtest/gtest.h"

class LinkedListTests :public ::testing::Test {
protected:
	LinkedList llist = LinkedList();
};

TEST_F(LinkedListTests, canInsertOneNode) {
	llist.insert(1);
}

TEST_F(LinkedListTests, calGetFrontandRear) {
	llist.insert(1);
	llist.insert(2);
	ASSERT_EQ(1, llist.front());
	ASSERT_EQ(2, llist.rear());
}
TEST_F(LinkedListTests, canSearchNumber) {
	llist.insert(1);
	llist.insert(2);
	ASSERT_TRUE(llist.search(2));
	ASSERT_FALSE(llist.search(4));
}
TEST_F(LinkedListTests, canRemoveFront) {
	llist.insert(1);
	llist.insert(2);
	ASSERT_TRUE(llist.remove(1));
	ASSERT_EQ(2, llist.front());
	ASSERT_EQ(2, llist.rear());
	ASSERT_FALSE(llist.search(1));
	
}

TEST_F(LinkedListTests, canRemoveMiddle) {
	llist.insert(1);
	llist.insert(2);
	llist.insert(3);
	ASSERT_TRUE(llist.remove(2));
	ASSERT_EQ(1, llist.front());
	ASSERT_EQ(3, llist.rear());
	ASSERT_FALSE(llist.search(2));

}
TEST_F(LinkedListTests, canRemoveRear) {
	llist.insert(1);
	llist.insert(2);
	ASSERT_TRUE(llist.remove(2));
	ASSERT_EQ(1, llist.front());
	ASSERT_EQ(1, llist.rear());
	ASSERT_FALSE(llist.search(2));

}