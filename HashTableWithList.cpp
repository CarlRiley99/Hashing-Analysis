#include "HashTableWithList.h"

HashTableWithList::HashTableWithList(int size) {
	maxSize = size;
	table.resize(maxSize);	//Resize function is from the vector class and it sets the size of the vector.
	numOfEntries = 0;
	numOfCollisions = 0;
	loadFactor = 0;
}

HashTableWithList::HashTableWithList() {
}

void HashTableWithList::PrintTable() {
	for (int i = 0; i < maxSize; i++) {
		for (int num : table[i]) {
			std::cout << num << ", ";
		}
	}
	std::cout << std::endl;
}

void HashTableWithList::Add(int key) {
	numOfEntries++;
	//int index = KeyModSize(key);		/* PICK HASH FUNCTION */
	int index = MidSquare(key);
	while (true) {
		if (!table[index].empty()) {		//When there is an initial collision
			numOfCollisions++;
			SeparateChaining(key, index);
			break;
		}
		else {		//When there is no initial collision
			table[index].push_front(key);
			break;
		}
	}
}

int HashTableWithList::KeyModSize(int key) {
	return key % maxSize;
}

int HashTableWithList::MidSquare(int key) {
	int hashedKey = key * key;
	int divisor = log2(maxSize);
	hashedKey /= divisor;
	hashedKey %= maxSize;
	printf("hashed key: %d  divisor: %d\n", hashedKey, divisor);
	return hashedKey;
}

void HashTableWithList::SeparateChaining(int key, int index) {
	/*std::list<int>::const_iterator iterator;
	for (iterator = table[index].begin(); iterator != table[index].end(); iterator++) {
		numOfCollisions++;
	}*/
	for (int num : table[index]) {
		numOfCollisions++;
	}
	table[index].push_front(key);
}

float HashTableWithList::GetLoadFactor() {
	loadFactor = numOfEntries / maxSize;
	return loadFactor;
}

int HashTableWithList::GetNumOfCollisions() {
	return numOfCollisions;
}