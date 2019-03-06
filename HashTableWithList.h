#include <iostream>
#include <vector>
#include <list>
#include <math.h>

#ifndef HASHTABLEWITHLIST_H
#define HASHTABLEWITHLIST_H

class HashTableWithList {
private:
	std::vector<std::list<int>> table;	//An array of linked lists

	int maxSize;
	int numOfCollisions;
	float loadFactor;
	float numOfEntries;

public:
	HashTableWithList();
	HashTableWithList(int size);

	void Add(int key);
	void PrintTable();

	void SeparateChaining(int key, int index);	//One method of solving collisions
	int KeyModSize(int key);		//One kind of hashing function
	int MidSquare(int key);		//One kind of hashing function
	float GetLoadFactor();
	int GetNumOfCollisions();

};


#endif
