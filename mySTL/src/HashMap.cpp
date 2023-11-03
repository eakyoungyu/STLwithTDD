#include "../inc/HashMap.h"

Node::Node() :next(NULL){}

Node::Node(string key, int value, Node* next): key(key), value(value), next(next) {}

HashMap::HashMap() {
	for (int i = 0; i < BUCKET_SIZE; i++)
		bucket[i] = NULL;
}

bool HashMap::update(string key, int value) {
	int hash = hash_func(key);
	Node* target = bucket[hash];
	while (target) {
		if (target->key == key) {
			target->value = value;
			return true;
		}
		target = target->next;
	}
	return false;
}

void HashMap::insert(string key, int value) {
	if (update(key, value))
		return;

	int hash = hash_func(key);
	Node* newnode = new Node(key, value, bucket[hash]);
	bucket[hash] = newnode;
}

Node* HashMap::find(string key) {
	int hash = hash_func(key);
	Node* target = bucket[hash];
	while (target) {
		if (target->key == key)
			break;
		target = target->next;
	}
	return target;
}

int HashMap::hash_func(string key) {
	int hash = 31;
	for (auto c : key) {
		hash = ((hash << 5) + hash + c) % BUCKET_SIZE;
	}

	return hash;
}