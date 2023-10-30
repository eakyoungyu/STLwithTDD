#pragma once
class Stack
{
private:
	int* buf;
	int _top;
	int _size;

public:
	Stack(int size);
	void push(int num);
	void pop();
	int top();
	int size();
	bool is_empty();
};

