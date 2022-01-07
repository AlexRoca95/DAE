// 1DAE12 - Alejandro Roca Vande Sype
//

#include "pch.h"
#include "Time.h"
#include <iostream>

void TestArrays();

int main()
{
    srand(unsigned int(time(nullptr)));

    TestArrays();
}


void TestArrays()
{
    const int sizeArray{ 4 };
    float randSec{};
    Time* pArray[4]{};


    for (int i{}; i < sizeArray; i++)
    {
        randSec = float(std::rand() % 500);

        pArray[i] = new Time{ randSec };
    }




    for (int i{}; i < sizeArray; i++)
    {
        delete pArray[i];
        pArray[i] = nullptr;
    }

    



}