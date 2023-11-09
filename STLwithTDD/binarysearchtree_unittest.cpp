#include "../mySTL/inc/BinarySearchTree.h"
#include "gtest/gtest.h"

class BSTTests:public::testing::Test{
protected:
	BinarySearchTree bst;
};

// add number
// traversal
// search number
// remove number

TEST_F(BSTTests, canInsertNumber) {
	bst.insert(1);
	ASSERT_EQ("1", bst.traversal());
}

TEST_F(BSTTests, canInsertNumbers) {
	bst.insert(1);
	bst.insert(7);
	bst.insert(2);
	ASSERT_EQ("1 2 7", bst.traversal());
}

TEST_F(BSTTests, canSearchNumber) {
	bst.insert(1);
	bst.insert(7);
	bst.insert(8);
	bst.insert(10);
	bst.insert(2);
	ASSERT_TRUE(bst.search(8));
	ASSERT_FALSE(bst.search(1000));
}

TEST_F(BSTTests, canRemoveNodeWithOneChild) {
	bst.insert(1);
	bst.insert(7);
	bst.insert(8);
	bst.insert(10);
	bst.insert(2);
	bst.insert(6);
	bst.remove(2);
	ASSERT_EQ("1 6 7 8 10", bst.traversal());
	ASSERT_FALSE(bst.search(2));
}

TEST_F(BSTTests, canRemoveNodeWithTwoChildern) {
	bst.insert(1);
	bst.insert(7);
	bst.insert(8);
	bst.insert(10);
	bst.insert(2);
	bst.insert(6);
	bst.remove(7);
	ASSERT_EQ("1 2 6 8 10", bst.traversal());
	ASSERT_FALSE(bst.search(7));
	bst.remove(2);
	ASSERT_FALSE(bst.search(2));
}
TEST_F(BSTTests, canRemoveLeafNode) {
	bst.insert(1);
	bst.insert(7);
	bst.insert(8);
	bst.insert(10);
	bst.insert(2);
	bst.insert(6);
	bst.remove(10);
	ASSERT_EQ("1 2 6 7 8", bst.traversal());
	ASSERT_FALSE(bst.search(10));
}

TEST_F(BSTTests, canRemoveRootNode) {
	bst.insert(1);
	bst.insert(7);
	bst.insert(8);
	bst.insert(10);
	bst.insert(2);
	bst.insert(6);
	bst.remove(1);
	ASSERT_EQ("2 6 7 8 10", bst.traversal());
	ASSERT_FALSE(bst.search(1));
}

TEST_F(BSTTests, canSearchEmptyBST) {
	ASSERT_FALSE(bst.search(1));
}