#pragma once
#include <string>
#define BUCKET_SIZE 100007
using namespace std;
class Node {
public:
	Node();
	Node(string key, int value, Node* next);
	string key;
	int value;
	Node* next;
};

class HashMap {
public:
	HashMap();
	void insert(string key, int value);
	Node* find(string key);
private:
	Node* bucket[BUCKET_SIZE];
	int hash_func(string key);
	bool update(string key, int value);
};