#include "../inc/LinkedList.h"

LinkedList::LinkedList() {
	head = new Node();
	tail = head;
}

void LinkedList::insert(int num) {
	Node* nnode = new Node(num);
	tail->next = nnode;
	tail = nnode;
}
int LinkedList::front() {
	return head->next->data;
}
int LinkedList::rear() {
	return tail->data;
}

bool LinkedList::search(int num) {
	Node* cur = head->next;
	while (cur) {
		if (cur->data == num) {
			return true;
		}
		cur = cur->next;
	}
	return false;
}

bool LinkedList::remove(int num) {
	Node* prev = head;
	while (prev->next) {
		if (prev->next->data == num) {
			Node* dnode = prev->next;
			prev->next = dnode->next;
			if (dnode == tail) {
				tail = prev;
			}
			delete dnode;
			return true;
		}
		prev = prev->next;
	}
	return false;
}