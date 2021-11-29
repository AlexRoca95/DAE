// ArrayBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

const int g_Size{ 5 };

void DefiningArrays();
void MemoryArrays();
void PrintElements(int* pArray, int size);
void PrintElements(int* pArray, int startIdx, int endIdx);
void Defining2dArray();
int  GetIndex(int rowIdx, int colIdx, int nrCols);

int main()
{

    DefiningArrays();
    MemoryArrays();
    Defining2dArray();

}


void DefiningArrays()
{
    int myArray[g_Size]{};  // Default initialization

    for (int i = 0; i < g_Size; i++)
    {
        std::cout << myArray[i] << " ";
    }

    std::cout << std::endl;

    int myArray2[]{10, 20, 30, 15, 34};  // Without specifying the g_Size

    for (int i = 0; i < g_Size; i++)
    {
        std::cout << myArray2[i] << " ";
    }

    std::cout << std::endl;

    int myArray3[g_Size]{ 10, 20, };  // Only some values are specified

    for (int i = 0; i < g_Size; i++)
    {
        std::cout << myArray3[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "-- Size of arrays --" << std::endl;
    std::cout << "2nd array" << std::endl;

    std::cout << "nr of bytes: " << sizeof(myArray2) <<std::endl;
    std::cout << "size of one element: " << sizeof(myArray2[0]) << std::endl;
    
    // We get the nr of elements of the array with sizeof
    int numberElements{ sizeof(myArray2) / sizeof(myArray2[0]) };
    std::cout << "nr of elements: " << numberElements << std::endl;

    std::cout << "-- Passing an array to a function -- " << std::endl;
    PrintElements(myArray, g_Size);
    PrintElements(myArray2, g_Size);
    PrintElements(myArray3, g_Size);

    std::cout << "-- Print a rand of elements -- " << std::endl;
    PrintElements(myArray2, 2, 4);
}

void MemoryArrays()
{
    int intArray[]{ 10, 20, 30, 15, 34 };
    std::cout << "-- Array of int types --" << std::endl;
    for (int i{ 0 }; i < g_Size; i++)
    {
        // We can see that every address is 4 bytes different
        std::cout << "Addres of the element " << i << ": " << &intArray[i] << std::endl;
    }
}

// Passing and array to a function
void PrintElements(int* pArray, int size)
{

    for (int i{}; i < size; i++)
    {
        std::cout << pArray[i] << " ";

    }

    std::cout << std::endl;
}

// Print a range of elements from the array
void PrintElements(int* pArray, int startIdx, int endIdx)
{


    for (startIdx; startIdx <= endIdx; startIdx++)
    {
        std::cout << pArray[startIdx] << " ";
    }
}


void Defining2dArray()
{
    //int my2DArray[nrRows][nrCols]{};  // We wont use 2D arrays because we cant pass it to a function

    std::cout << "-- 2D arrays --" << std::endl;
    const int size{ 20 };
    const int nrCols{ 5 }, nrRows{ 4 };

    int rowIdx{ }, idx{}, colIdx{};
    int my2DArray[size]{};
   

    
    for (rowIdx; rowIdx < nrRows; rowIdx++)  // Rows loop
    {
        for (colIdx = 0; colIdx < nrCols; colIdx++) // Collums loop
        {
            idx = GetIndex(rowIdx, colIdx, nrCols);

            // Dont need this calculation because you already have the indexs in the loop
            //rowIdx = idx / nrCols;
            //colIdx = idx % nrCols;

            my2DArray[idx] = ((rowIdx + 1) * 10) + (colIdx + 1);

           std::cout << my2DArray[idx] << " ";

           if (colIdx == nrCols - 1) // Last element of the row
               std::cout << std::endl;
        }
    }

}

// Get the index of the 2D array
int GetIndex(int rowIdx, int colIdx, int nrCols)
{
    int idx{};

    idx = rowIdx * nrCols + colIdx;

    return idx;
}