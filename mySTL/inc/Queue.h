#pragma once

class Queue {
public:
	Queue(int max_size);
	int size();
	void push(int num);
	void pop();
	int front();
	bool isEmpty();
private:
	int _size;
	int* buf;
	int _front, _rear;
};