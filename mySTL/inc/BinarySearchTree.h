#pragma once
#include <string>

class BinarySearchTree {
	class Node {
	public:
		Node(int num);
		int num;
		Node* left;
		Node* right;
	};
public:
	BinarySearchTree();
	void insert(int num);
	std::string traversal();
	bool search(int num);
	void remove(int num);
private:
	Node* root;
	std::string traversal(Node* cur);
	Node* insertByRecursive(Node* cur, int num);
	Node* searchNode(int num);
	Node* remove(Node* cur, int num);
	Node* findMinNodeInRightSubtree(Node* cur);
};