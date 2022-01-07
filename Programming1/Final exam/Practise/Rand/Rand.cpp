// Rand function practise

#include "pch.h"
#include <iostream>

// The rand() function generates a random number between 0 and RAND MAX

int main()
{
	// We have to initialize the random seed (only once)
	srand(unsigned int(time(nullptr)));

	int basicRand = rand();			// [0, RAND_MAX]
	std::cout << basicRand << std::endl;

	
	int rand2 = rand() % 50; // Rand [0, 49]
	std::cout << rand2 << std::endl;


	// Always value 1 more that the one you need
	int rand3 = rand() % 51; // Rand [0, 50]
	std::cout << rand3 << std::endl;
	

	// The + indicates from which number starts the random 
	// and you add that to value left to get the final random value
	int rand4 = rand() % 71 + 10; // Rand [10, 80]
	std::cout << rand4 << std::endl;

	// 2º way to do it
	// randomValue = rand() % (80 - 10 + 1) + 10;  // (Till - From + 1) + From
	
	// [-20, 20]
	// In order to calculate a random between negative and postive numbers
	// You need to calculate to rands and then add them
	int rand5 = (rand() % 20) - 20; // Rand [-20, -1]
	rand5 += (rand() % 20) + 1; // Rand [0, 20]
	std::cout << rand5 << std::endl;
	

	
	// [-2, 2]
	// In order to calculate a random between negative and postive numbers
	// You need to calculate to rands and then add them
	int rand6 = (rand() % 2) - 2; // Rand [-2, 0]
	rand6 += (rand() % 4); // Rand [0, 2]
	std::cout << rand6 << std::endl;


	
}

