#include "HashTable.h"

int HashTable::hash(string c) {
	return c[0] % size;
}

HashTable::HashTable() {
	this->size = 10;
	map = new list<string>[this->size];
}

HashTable::HashTable(int size) {
	this->size = size;
	map = new list<string>[this->size];
}

HashTable::~HashTable() { 
	delete[] map; 
}

void HashTable::insert(vector<string> str) {
	for (int i = 0; i < str.size(); i++) {
		int bucket = hash(str.at(i));
		map[bucket].push_front(str.at(i));
	}
}

bool HashTable::search(string str)
{
	int bucket = hash(str);
	auto it = find(map[bucket].begin(), map[bucket].end(), str);
	if (it == map[bucket].end()) {
		return false;
	}
	return true  ;
}
