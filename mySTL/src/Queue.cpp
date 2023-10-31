#include "../inc/Queue.h"

Queue::Queue(int max_size): _size(max_size), _front(0), _rear(0) {
	buf = new int[_size];
}
int Queue::size() {
	return _rear - _front;
}
void Queue::push(int num) {
	buf[_rear++] = num;
}

void Queue::pop() {
	_front++;
}

int Queue::front() {
	return buf[_front];
}

bool Queue::isEmpty() {
	return _front == _rear;
}