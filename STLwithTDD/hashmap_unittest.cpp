#include "gtest/gtest.h"
#include "../mySTL/inc/HashMap.h"

class HashMapTests :public::testing::Test {
protected:
	HashMap hmap;
};

TEST_F(HashMapTests, canAddKeys) {
	hmap.insert("abc", 3);
	hmap.insert("bca", 2);
}
TEST_F(HashMapTests, canFindKey) {
	hmap.insert("abc", 3);
	hmap.insert("bca", 2);
	Node* target = hmap.find("abc");
	ASSERT_TRUE(target != NULL);
	ASSERT_TRUE(3, target->value);
	ASSERT_TRUE(hmap.find("abcd") == NULL);
}

TEST_F(HashMapTests, canFindKeys) {
	hmap.insert("abc", 3);
	hmap.insert("bca", 2);
	hmap.insert("PPPPP", 2);

	Node* target = hmap.find("PPPPP");
	ASSERT_TRUE(target != NULL);
	ASSERT_TRUE(2, target->value);

	target = hmap.find("bca");
	ASSERT_TRUE(target != NULL);
	ASSERT_TRUE(2, target->value);
}
TEST_F(HashMapTests, canUpdateValue) {
	hmap.insert("abc", 3);
	hmap.insert("abc", 5);
	Node* target = hmap.find("abc");
	ASSERT_TRUE(target != NULL);
	ASSERT_TRUE(5, target->value);
}