#include <iostream>
#include <vector>
#include <list>
#include <math.h>

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {
private:
	//std::vector<std::list<int>> table;	//An array of linked lists
	std::vector<int> table;

	int maxSize;
	int numOfCollisions;
	float loadFactor;
	float numOfEntries;

public:
	HashTable();
	HashTable(int size);

	void Add(int key);
	void PrintTable();

	void OpenAddressing(int key, int index);	//One method of solving collisions
	//void SeparateChaining(int key, int index);	//One method of solving collisions
	int KeyModSize(int key);		//One kind of hashing function
	int MidSquare(int key);		//One kind of hashing function
	float GetLoadFactor();
	int GetNumOfCollisions();
	
};


#endif
