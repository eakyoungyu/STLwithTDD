#include "../inc/BinarySearchTree.h"

BinarySearchTree::Node::Node(int num):num(num),left(NULL),right(NULL){}

BinarySearchTree::BinarySearchTree():root(NULL){}

BinarySearchTree::Node* BinarySearchTree::insertByRecursive(Node* cur, int num) {
	if (!cur)
		return new BinarySearchTree::Node(num);
	if (cur->num > num)
		cur->left = insertByRecursive(cur->left, num);
	else
		cur->right = insertByRecursive(cur->right, num);

	return cur;
}

void BinarySearchTree::insert(int num) {
	BinarySearchTree::Node* nnode = new BinarySearchTree::Node(num);
	if (!root) {
		root = nnode;
		return;
	}

	BinarySearchTree::Node* target = root;
	while (target) {
		if (target->num > num) {
			if (!target->left) {
				target->left = nnode;
				break;
			}
			target = target->left;
		}
		else {
			if (!target->right) {
				target->right = nnode;
				break;
			}
			target = target->right;
		}
	}
}

std::string BinarySearchTree::traversal(Node* cur) {
	std::string result = "";
	if (!cur)
		return result;

	result += traversal(cur->left);
	result += std::to_string(cur->num) + " ";
	result += traversal(cur->right);
}

std::string BinarySearchTree::traversal() {
	BinarySearchTree::Node* cur = root;
	std::string result = traversal(root);

	if (!result.empty())
		result.pop_back();
	
	return result;
}

BinarySearchTree::Node* BinarySearchTree::searchNode(int num) {
	BinarySearchTree::Node* target = root;

	while (target) {
		if (target->num == num)
			return target;
		target = (target->num > num) ? target->left : target->right;
	}

	return NULL;
}

bool BinarySearchTree::search(int num) {
	return searchNode(num) != NULL;
}

BinarySearchTree::Node* BinarySearchTree::remove(Node* cur, int num) {
	if (cur == NULL)
		return cur;
	if (cur->num == num) {
		BinarySearchTree::Node* dnode = cur;
		BinarySearchTree::Node* subnode;
		if (dnode->left && dnode->right) {
			// Find min in right subtree
			BinarySearchTree::Node *prev = NULL;
			subnode = dnode->right;
			while (subnode->left) {
				prev = subnode;
				subnode = subnode->left;
			}

			if (prev)
				prev->left = subnode->right;

			subnode->left = dnode->left;
		}
		else if (dnode->left || dnode->right) {
			subnode = (dnode->left) ? dnode->left : dnode->right;
		}
		else {
			subnode = NULL;
		}
		delete dnode;
		return subnode;
	}
	if (cur->num > num) {
		cur->left = remove(cur->left, num);
	}
	else {
		cur->right = remove(cur->right, num);
	}

	return cur;
}

void BinarySearchTree::remove(int num) {
	root = remove(root, num);
}

BinarySearchTree::Node* BinarySearchTree::findMinNodeInRightSubtree(Node* cur) {
	BinarySearchTree::Node* minNode = cur->right;
	
	if (!minNode->left) {
		cur->right = minNode->right;
		return minNode;
	}

	while (minNode->left && minNode->left->left) {
		minNode = minNode->left;
	}
	minNode->right = minNode->left->right;
	minNode = minNode->left;

	return minNode;
}