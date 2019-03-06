#include "HashTable.h"

HashTable::HashTable(int size) {
	maxSize = size;
	table.resize(maxSize);	//Resize function is from the vector class and it sets the size of the vector.
	numOfEntries = 0;
	numOfCollisions = 0;
	loadFactor = 0;
}

HashTable::HashTable() {
}

void HashTable::PrintTable() {
	for (int i = 0; i < maxSize; i++) {
		std::cout << table[i] << ", ";
	}
}

void HashTable::Add(int key) {
	numOfEntries++;
	//int index = KeyModSize(key);		/* PICK HASH FUNCTION */
	int index = MidSquare(key);
	while (true) {
		if (table[index] != 0) {		//When there is an initial collision
			numOfCollisions++;
			OpenAddressing(key, index);		/* PICK COLLISION RESOLUTION FUNCTION */
			break;
		}
		else {		//When there is no initial collision
			table[index] = key;
			break;
		}
	}
}

int HashTable::KeyModSize(int key) {
	return key % maxSize;
}

int HashTable::MidSquare(int key) {
	int hashedKey = key * key;
	int divisor = log2(maxSize);
	hashedKey /= divisor;
	hashedKey %= maxSize;
	printf("hashed key: %d  divisor: %d\n", hashedKey, divisor);
	return hashedKey;
}

void HashTable::OpenAddressing(int key, int index) {
	int numOfMovements = 0;
	while (numOfMovements != maxSize) {
		if (index >= maxSize - 1) {
			index = 0;
		}
		else {
			index++;
		}
		numOfMovements++;

		if (table[index] != 0) {
			numOfCollisions++;
			continue;
		}
		else {
			table[index] = key;
			return;
		}
	}
}

float HashTable::GetLoadFactor() {
	loadFactor = numOfEntries / maxSize;
	return loadFactor;
}

int HashTable::GetNumOfCollisions() {
	return numOfCollisions;
}