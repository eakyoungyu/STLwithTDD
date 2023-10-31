#include "../inc/Heap.h"

Heap::Heap() {
	_size = 0;
}

void Heap::push(int num) {
	buf[_size] = num;
	inHeap(_size++);
}

int Heap::size() {
	return _size;
}

bool Heap::isEmpty() {
	return _size == 0;
}

int Heap::top() {
	return buf[ROOT];
}

void Heap::swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void Heap::inHeap(int target) {
	while (target) {
		int parent = target / 2;
		if (buf[parent] < buf[target])
			break;
		swap(buf[target], buf[parent]);
		target = parent;
	}
}

void Heap::pop() {
	buf[ROOT] = buf[--_size];
	delHeap();
}

int Heap::leftChild(int parent) {
	return parent * 2 + 1;
}

int Heap::rightChild(int parent) {
	return parent * 2 + 2;
}

int Heap::getSwapCandidate(int left, int right) {
	int candidate = left;
	if (right < _size) {
		candidate = (buf[left] < buf[right]) ? left : right;
	}

	return candidate;
}

void Heap::delHeap() {
	int target = ROOT;

	while (leftChild(target) < _size) {
		int candidate = getSwapCandidate(leftChild(target), rightChild(target));
		if (buf[target] < buf[candidate]) {
			break;
		}

		swap(buf[target], buf[candidate]);
		target = candidate;
	}
}