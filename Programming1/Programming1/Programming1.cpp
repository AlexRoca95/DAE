// Programming1.cpp : 1º week theory class of prog 1


#include "pch.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <string>       


void DoRandomPart();                    // Forward declaration of the function

int g_Global{};                         // Global variable

int main()
{
    std::cout << "Hello World!\n";
       
    float fpi(float(M_PI));             // Type cast int to float

    float result{};
    result = sinf(1.2f);                 // sinf because normal sin is double

    DoRandomPart();
    DoRandomPart();

    int number{};
    std::cin >> number;
    std::cin.ignore();                  // Take out last character from cin that was in the buffer (in our case last enter we used)
    std::cin.get();                     // Wait user to press enter

    std::string text;
    text = "Hello DAE";
    text += " again! ";                  // Adds to the string
    text += std::to_string(number);
    std::cout << text << "\n";
}

// Functions always with Mayusculas the first letter
void DoRandomPart()
{
    std::cout << "Do Random part!\n";
    int r{};
    r = rand() % 10 + 5;                    // Random less than 14 ( between 0 & 9 + 5)
    
    std::cout << r << "\n";
}
