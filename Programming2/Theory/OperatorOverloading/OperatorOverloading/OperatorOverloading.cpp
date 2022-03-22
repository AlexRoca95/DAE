// OperatorOverloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Float2.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

    Float2 f1{ 20, 20 }, f2{ 50, 60 }, f3{};

    f3 = f1 + f2;
}

