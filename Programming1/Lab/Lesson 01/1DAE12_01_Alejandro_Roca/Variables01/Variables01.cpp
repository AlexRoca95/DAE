// Alejandro, Roca Vande Sype - 1DAE12


#include "pch.h"
#include <iostream>

int main()
{
    // 4.1.4
    int iNumber{};
    char letter{};
    bool bValue{};
    float fNumber{};
    double dNumber{};
    std::cout << "Values: ( " << iNumber << ", " << letter << ", " << bValue << ", "
        << fNumber << ", " << dNumber << " )" << std::endl;

    //4.1.5
    int iNumber2{ 23 };
    char letter2{ 'C' };
    bool bValue2{ true };
    float fNumber2{ 12.4f };
    double dNumber2{ 25.2f };
    std::cout << "Values: ( " << iNumber2 << ", " << letter2 << ", " << bValue2 << ", "
        << fNumber2 << ", " << dNumber2 << " )" << std::endl;


    // 4.1.6
    iNumber2 = 32;
    letter2 = 'H';
    bValue2 = false;
    fNumber2 = 10.5f;
    dNumber2 = 123.56f;
    std::cout << "Values: ( " << iNumber2 << ", " << letter2 << ", " << bValue2 << ", "
        << fNumber2 << ", " << dNumber2 << " )" << std::endl;

    // 4.1.7
    std::cout << "Please enter a value for each variable type: ";
    std::cin >> iNumber2 >> letter2 >> bValue2 >> fNumber2 >> dNumber2;
    std::cout << "Values: ( " << iNumber2 << ", " << letter2 << ", " << bValue2 << ", "
        << fNumber2 << ", " << dNumber2 << " )" << std::endl;

    // 4.2.1 and 4.2.2
    int result1 = iNumber2 + 12;
    float result2 = fNumber2 - 4.2f;
    char result3 = letter2 + 'D';
    int result4 = result1 + letter2;

    int result5 = result1 * 3;
    float result6 = result2 / 2;
    float result7 = result1 * result2;
    iNumber2 = iNumber2 / 3;

    std::cout << "Results: " << result1 << ", " << result2 << ", " << result3 << ", " << result4 
        << ", " << result5 << ", " << result6 << ", " << result7 << ", " << iNumber2 << std::endl;



}
