#pragma once
#include "iostream"

class LinkedList {
public:
	LinkedList();
	void insert(int num);
	bool search(int num);
	int front();
	int rear();
	bool remove(int num);
private:
	class Node {
	public:
		Node():next(NULL){}
		Node(int data):next(NULL), data(data){}
		int data;
		Node* next;
	};
	Node* head;
	Node* tail;
};