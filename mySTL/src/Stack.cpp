#include "../inc/Stack.h"

Stack::Stack(int size) : _top(0) {
	_size = size;
	buf = new int[_size];
}

void Stack::push(int num) {
	buf[_top++] = num;
}

int Stack::top() {
	return buf[_top - 1];
}

void Stack::pop() {
	_top--;
}

int Stack::size() {
	return _top;
}

bool Stack::is_empty() {
	return _top == 0;
}