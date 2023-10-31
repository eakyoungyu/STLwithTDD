#pragma once

class Heap {
public:
	Heap();
	void push(int num);
	int size();
	bool isEmpty();
	int top();
	void pop();
private:
	int const ROOT = 0;
	int _size;
	int buf[10001];
	void inHeap(int target);
	void delHeap();
	void swap(int& a, int& b);
	int leftChild(int parent);
	int rightChild(int parent);
	int getSwapCandidate(int left, int right);
};