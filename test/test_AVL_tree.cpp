#include "AVL_tree.h"
#include <gtest.h>


class AVL_tree_test : public ::testing::Test {
protected:
	void SetUp() {
		tree = new AVL_tree;

		tree->insert(23);
		tree->insert(12);
		tree->insert(45);
		tree->insert(5);
	}

	void TearDown() {
		delete tree;
	}

	AVL_tree* tree;
};


TEST_F(AVL_tree_test, create_AVL_tree) {
	ASSERT_NO_THROW(this->SetUp());
};

TEST_F(AVL_tree_test, throw_AVL_tree_insert_new_key) {
	this->SetUp();

	ASSERT_NO_THROW(this->tree->insert(6));
};
TEST_F(AVL_tree_test, throw_AVL_tree_erase_key) {
	this->SetUp();

	ASSERT_NO_THROW(this->tree->erase(5));
};

TEST_F(AVL_tree_test, throw_AVL_tree_insert_double_key) {
	this->SetUp();

	ASSERT_ANY_THROW(this->tree->insert(12));
}
TEST_F(AVL_tree_test, throw_AVL_tree_erase_not_key) {
	this->SetUp();

	ASSERT_ANY_THROW(this->tree->erase(32));
}
TEST_F(AVL_tree_test, find_AVL_tree_correct) {
	this->SetUp();

	EXPECT_EQ((this->tree->find(23))->key, 23);
}
TEST_F(AVL_tree_test, find_AVL_tree_ancorrect) {
	this->SetUp();

	EXPECT_EQ((this->tree->find(2)), nullptr);
}
TEST_F(AVL_tree_test, correct_height_AVL_tree) {
	this->SetUp();

	EXPECT_EQ((this->tree->find(5)->height), 1);
}
TEST_F(AVL_tree_test, correct_height_AVL_tree_after_balance) {
	this->SetUp();

	this->tree->insert(3);
	EXPECT_EQ((this->tree->find(5)->height), 2);
}
TEST_F(AVL_tree_test, save_height_AVL_tree) {
	this->SetUp();

	this->tree->insert(25);
	EXPECT_EQ((this->tree->find(23)->height), 3);
}


