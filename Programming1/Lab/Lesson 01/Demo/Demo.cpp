// Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

    int intVar{ 12 };  // Declaration + Initialization
    int a;             // Declaration
    float floatVar{ 12.3f };
    char charVar{ 'a' };
    bool boolVar{ true };

    intVar = 52;

    a = 2;
    floatVar = 85.f;
    boolVar = false;


    std::cout << '(' << intVar << ')' << '(' << floatVar << ')' << std::endl;
    std::cout << '(' << charVar << ')' << std::endl;
    std::cout << '(' << boolVar << ')' << std::endl;



    std::cin.get();         // Wait until you press enter key
    
    int result{};      // Default value
    result = intVar;
    result += result;
    result = result + 1000;
    result *= 2;

    std::cout << "Enter an integer number please: ";
    std::cin >> intVar;
    std::cout << '(' << intVar << ')' << std::endl;

    std::cout << "Enter three numbers separated by a space: ";
    int r{}, g{}, b{};
    std::cin >> r >> g >> b;
    ++result;
    std::cout << result << '\n';
    result++;
    std::cout << result << '\n';



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
