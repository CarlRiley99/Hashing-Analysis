#include "HashTable.h"
#include "HashTableWithList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

	int maxSize = 500;
	int key = 0;
	std::vector<float> loadFactor;
	std::vector<int> numOfCollisions;
	loadFactor.resize(maxSize);
	numOfCollisions.resize(maxSize);

	//HashTableWithList table(maxSize);		/* PICK HASH TABLE (WITH LIST IS COLLISION RESOLUTION BY CHAINING, THE OTHER ONE */
	HashTable table(maxSize);				/* IS COLLISION RESOLUTION BY OPEN ADDRESSING) */
	std::fstream dataFile;
	std::string fileName;

	std::cout << "Enter File Name (do not include .txt extension): ";

	std::cin >> fileName;
	fileName += ".txt";

	//dataFile.open(fileName, std::ios_base::app | std::ios_base::in);
	if (dataFile.is_open()) {
		dataFile << "Format:\n(LoadFactor) (Number of Collisions)\nData (Table Size = " << maxSize << "):\n";
	}
	else {
		std::cout << "FILE FAILED TO OPEN" << std::endl;
	}

	for (int i = 0; i < maxSize; i++) {
		key = rand() % (maxSize * 3) + 1;	//Generates a key that's 0 to 3 times the Hash Table size.
		std::cout << "Key: " << key << std::endl;
		table.Add(key);
		printf("Load Factor: %f\nNumber of Collisions: %d\n", table.GetLoadFactor(), table.GetNumOfCollisions());
		//table.PrintTable();
		std::cout << std::endl;

		//Write to the File
		if (dataFile.is_open()) {
			dataFile << table.GetLoadFactor() << "         " << table.GetNumOfCollisions() << std::endl;
			loadFactor[i] = table.GetLoadFactor();
			numOfCollisions[i] = table.GetNumOfCollisions();
		}
	}
	dataFile << "Load Factors: " << std::endl;
	for (int i = 0; i < maxSize; i++) {
		dataFile << loadFactor[i] << std::endl;
	}
	dataFile << "Num of Collisions: " << std::endl;
	for (int i = 0; i < maxSize; i++) {
		dataFile << numOfCollisions[i] << std::endl;
	}
	dataFile.close();

	system("pause");
	return 0;
}