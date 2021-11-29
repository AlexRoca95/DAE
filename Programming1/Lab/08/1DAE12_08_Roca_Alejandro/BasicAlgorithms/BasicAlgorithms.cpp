// BasicAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


int Count(const int* pArray, const int size, const int search);
void TestCount();

int MinElement(const int* pArray, const int size);
int MaxElement(const int* pArray, const int size);
void TestMinMax();


void Swap(int* pArray,const int size, const int idx1, const int idx2);
void TestSwap();

void Shuffle(int* pArray, const int size, const int swaps);
int RandomNumber(const int size);
void TestShuffle();

int main()
{
	srand(unsigned int(time(nullptr)));

	//TestCount();
	//TestMinMax();
	//TestSwap();
	TestShuffle();

}

// Returns the number of elements in the array that are equal to search number
int Count(const int* pArray, const int size, const int search)
{
	int count{};

	for (int i{}; i < size; i++)
	{
		if (pArray[i] == search)	// Number found
			count++;
	}

	return count;
}

void TestCount()
{
	std::cout << "-- Test of Count function --" << std::endl;
	const int size{ 10 };
	int search{ 2 }, count{};
	int myArray[size]{ 7, -3, 9, -8, 3, 0, -7, 1, 9, 8 };

	count = Count(myArray, size, search);

	for (int i{}; i < size; i++)
	{
		std::cout << myArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << search << " occurs " << count << " times in this array" << std::endl;

	const int size2 = 14;
	int myArray2[size2]{ 7, -3, 9, -8, 3, 0, -7, 1, 9, 8, -3, 10, 3, 4 };
	search = 4;

	count = Count(myArray2, size2, search);

	for (int i{}; i < size2; i++)
	{
		std::cout << myArray2[i] << " ";
	}
	std::cout << std::endl;
	std::cout << search << " occurs " << count << " times in this array" << std::endl;

}

// Returns the smallest value of the array
int MinElement(const int* pArray, const int size)
{
	int minValue{};

	for (int i{}; i < size; i++)
	{
		if (i == 0)  // First element of array
		{
			minValue = pArray[i];
		}
		else
		{
			if (minValue > pArray[i])
				minValue = pArray[i];	// New min value found
		}
			
	}

	return minValue;
}

// Returns the largest value of the array
int MaxElement(const int* pArray, const int size)
{
	int maxValue{};

	for (int i{}; i < size; i++)
	{
		if (i == 0)  // First element of array
		{
			maxValue = pArray[i];
		}
		else
		{
			if (maxValue < pArray[i])
				maxValue = pArray[i];	// New max value found
		}

	}

	return maxValue;
}


void TestMinMax()
{
	std::cout << std::endl;
	std::cout << "-- Test of MinElement and MaxElement function -- " << std::endl;

	const int size{ 10 };
	int myArray[size]{ 7, -3, 9, -8, 3, 0, -7, 1, 9, 8 };
	int min{}, max{};

	min = MinElement(myArray, size);
	max = MaxElement(myArray, size);

	for (int i{}; i < size; i++)
	{
		std::cout << myArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << min << " is the smallest element in the array" << std::endl;
	std::cout << max << " is the greatest element in the array" << std::endl;

}

// Swap two elements from the array
void Swap(int* pArray, const int size, const int idx1, const int idx2)
{
	// Check if the indexs are inside the limits of the array
	if (idx1 < 0 || idx1 >= size)
	{
		std::cout << idx1 << " is out of the limits of the array." << std::endl;

		return;
	}
	
	if (idx2 < 0 || idx2 >= size)
	{
		std::cout << idx2 << " is out of the limits of the array." << std::endl;

		return;
	}
	
	int saveElement{};

	// Save the element from the array
	saveElement = pArray[idx1];
	pArray[idx1] = pArray[idx2];
	pArray[idx2] = saveElement;
}

void TestSwap()
{
	std::cout << std::endl;
	std::cout << "-- Test of Swap function -- " << std::endl;

	const int size{ 10 };
	int myArray[size]{ 7, -3, 9, -8, 3, 0, -7, 1, 9, 8 };
	int idx1{10}, idx2{7};

	std::cout << "Before swapping " << std::endl;
	for (int i{}; i < size; i++)
	{
		std::cout << myArray[i] << " ";
	}
	std::cout << std::endl;

	Swap(myArray, size, idx1, idx2);

	std::cout << "After swapping " << std::endl;
	for (int i{}; i < size; i++)
	{
		std::cout << myArray[i] << " ";
	}
	std::cout << std::endl;


}

// Shuffle the elements in the array by swapping a number of times two random elements
void Shuffle(int* pArray, const int size, const int swaps)
{
	int idx1{}, idx2{};

	// Swap values the number of times determined by swaps
	for (int i{}; i < swaps; i++)
	{
		do {

			idx1 = RandomNumber(size);
			idx2 = RandomNumber(size);
			//std::cout << "First random number " << idx1 << std::endl;
			//std::cout << "Second random number " << idx2 << std::endl;
			// Keep generating random numbers until we get two different ones
		} while (idx1 == idx2);			

		Swap(pArray, size, idx1, idx2);
	}

}

void TestShuffle()
{
	std::cout << std::endl;
	std::cout << "-- Test of Shuffle function -- " << std::endl;

	const int size{ 10 };
	int myArray[size]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int swaps{ 3 };

	std::cout << "Before swapping " << std::endl;
	for (int i{}; i < size; i++)
	{
		std::cout << myArray[i] << " ";
	}
	std::cout << std::endl;

	Shuffle(myArray, size, swaps);

	std::cout << "After shuffling " << swaps <<  std::endl;
	for (int i{}; i < size; i++)
	{
		std::cout << myArray[i] << " ";
	}
	std::cout << std::endl;
}

// Generate a random number within the limits of the array
int RandomNumber(const int size)
{
	int random{};

	random = rand() % size;  // Random between 0 and the size - 1
	
	return random;
}