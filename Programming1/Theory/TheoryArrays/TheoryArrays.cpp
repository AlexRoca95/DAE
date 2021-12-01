// TheoryArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


void DoubleTheArrayValues(int*,int);       // Parameter is an array 
void ChangeVariable(int*);

int main()
{
    int number1{ 11 };
    const int size{ 6 };             // Size of the array (needs to be const or literal in order to be know in compile time)

    int numbers[size]{};                // Array of 6 elements with uniform initializacion
    int numbers2[6]{ 1,2,3,4,5,6 };  // 2º way to initialize
    int numbers3[6]{ 1,2 };          // The rest of elements will be initialized to 0
    int numbers4[]{ 1,2,3 };         // The array size will be equal to the number of elements

    std::cout << numbers[0] << std::endl;       // First index of array is 0

    sizeof(numbers);                 // Returns the size in Bytes (24 bytes = 6 elem * 4 bytes)
    for (int i{ 0 }; i < size; i++)
    {
        std::cout << numbers[i] << std::endl;
    }


    std::cout << "The address of number1 is " << &numbers[0] << std::endl;

    ChangeVariable(&number1); // We pass the memory address of the variable
    std::cout << "The number is " << number1 << std::endl;
    DoubleTheArrayValues(numbers2, size);


}

// Change value of a variable using pointers
void ChangeVariable(int * pNumber)
{
    *pNumber = (*pNumber) * 2;          // We access the element in the address and we change it

}

// We change the values of the array and we pass the size of the array
void DoubleTheArrayValues(int* pNumbers, int size)  // Memory address of the array
{

    std::cout << pNumbers << std::endl;  // Address of the first element of the array

    for(int i{}; i < size; i++)
    {
        *pNumbers = (*pNumbers) * 2;

        std::cout << *pNumbers << std::endl;

        ++pNumbers;  // Next memory location (Integer --> +4 bytes)
    }

}

