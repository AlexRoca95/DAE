// Functions2TheoryDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

// Prototype of the function
void AddChar(std::string&);         // Pass by Reference. No copy of the original value.
int& GetSmallest(int&, int&);     // Return reference
int CalcSum(int);                   // Recursive function

int main()
{
    

    std::string name{ "SpaceX" };
    AddChar(name);

    std::cout << name << std::endl;
    
    int a{ 10 }, b{ 42 };

    int& result = GetSmallest(a, b);
    result *= 2;

    std::cout << a << ' ' << b << '\n';
    
    int sum{ CalcSum(10) };

    std::cout << sum << '\n';
}

void AddChar(std::string& text)
{
    // We modify the original variable
    text += 'o'; 

}



int& GetSmallest(int& a, int& b)
{
    if (a > b)
        return b;
    return a;

}


int CalcSum(int number)
{
    if (number == 1) // Base Case
        return 1;
    return number + CalcSum(number - 1);  // Recursive Case

}


