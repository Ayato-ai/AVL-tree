// UNN, IITMM, Course "Algorithms and Data Structures"
// 
// Noskov I.A.

#pragma once
#include<iostream>

struct Node {
	std::size_t key;
	int height;
	Node* left;
	Node* right;
	Node(std::size_t k) {
		key = k;
		left = right = nullptr;
		height = 1;
	}
};
class AVL_tree {
private:
	Node* root;

	int get_height(Node* node) const {
		if (node != nullptr)
			return node->height;
		else
			return 0;
	};
	int balance_factor(Node* node) const {
		return get_height(node->right) - get_height(node->left);
	};
	void fix_height(Node* node) {
		node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
	};

	Node* right_turn(Node* node) {
		Node* new_root = node->left;
		node->left = new_root->right;
		new_root->right = node;

		fix_height(node);
		fix_height(new_root);


		return new_root;
	};
	Node* left_turn(Node* node) {
		Node* new_root = node->right;
		node->right = new_root->left;
		new_root->left = node;

		fix_height(node);
		fix_height(new_root);


		return new_root;
	};

	Node* balance(Node* node) {
		fix_height(node);
		if (balance_factor(node) == 2) {
			if (balance_factor(node->right) < 0)
				node->right = right_turn(node->right);
			return left_turn(node);
		}
		if (balance_factor(node) == -2) {
			if (balance_factor(node->left) > 0)
				node->left = left_turn(node->left);
			return right_turn(node);
		}
		return node;
	};

	Node* insert(Node* node, std::size_t key) {
		if (node == nullptr)
			return new Node(key);

		if (node->key > key)
			node->left = insert(node->left, key);

		if (node->key < key)
			node->right = insert(node->right, key);

		if (node->key == key)
			throw std::logic_error("key_infallible");

		return balance(node);
	};

	Node* erase(Node* node, std::size_t key) {
		if (node == nullptr)
			throw std::logic_error("key_infallible");

		if (node->key > key)
			node->left = erase(node->left, key);

		if (node->key < key)
			node->right = erase(node->right, key);

		if (node->key == key) {
			Node* left_tree = node->left;
			Node* right_tree = node->right;
			delete node;

			/*left_tree->height--;
			right_tree->height--;*/

			if (right_tree == nullptr)
				return left_tree;

			Node* min = find_min(right_tree);
			min->right = remove_min(right_tree);
			min->left = left_tree;
			return balance(min);
		}
		return nullptr;
	};

	Node* remove_min(Node* node) {
		if (node->left == nullptr)
			return node->right;
		node->left = remove_min(node->left);
		return balance(node);
	}

	Node* find_min(Node* node) {
		while (node && node->left)
			node = node->left;
		return node;
	};

	Node* find(Node* node, std::size_t key) {
		if (node->key == key)
			return node;
		if (node->key > key)
			if (node->left)
				return find(node->left, key);
			else
				return nullptr;
		if (node->key < key)
			if (node->right)
				return find(node->right, key);
			else
				return nullptr;
		return nullptr;
	};

	void delete_AVL_tree(Node* node) {
		if (node) {
			delete_AVL_tree(node->left);
			delete_AVL_tree(node->right);
			delete node;
		}
	}

	void print_AVL_tree(Node* node) const {
		if (node)
			std::cout << node->key << std::endl;
		else
			return;
		print_AVL_tree(node->left);
		print_AVL_tree(node->right);
	}

public:
	AVL_tree(Node* node) {
		root = node;
	};
	AVL_tree() {
		root = nullptr;
	};

	void insert(std::size_t key) {
		//try {
			root = insert(root, key);
		//}
		//catch (const std::logic_error& e) {
		//	std::cout << e.what() << std::endl;
		//	//exit(-1);
		//	return;
		//}
	};
	void erase(std::size_t key) {
		//try {
			root = erase(root, key);
		//}
		//catch (const std::logic_error& e) {
		//	std::cout << e.what() << std::endl;
		//	//exit(-1);
		//	return;
		//}
	};

	Node* find(std::size_t key) {
		return find(root, key);
	};
	void print() const {
		print_AVL_tree(root);
	}


	~AVL_tree() {
		delete_AVL_tree(root);
	};
};
