#pragma once
#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class HashTable
{
	private:
		list<string>* map;
		int size;
		int hash(string c);
	public:
		HashTable();
		HashTable(int size);
		~HashTable();
		void insert(vector<string> str);
		bool search(string str);
};

