// Roca, Alejandro - 1DAE12
//


#include "pch.h"
#include <iostream>
#include <bitset>

void GetSizes();
void ShowDiffNumSyst();
void RangeOfValues();
void BinaryBitwise();

int main()
{
    
    GetSizes();
    ShowDiffNumSyst();
    RangeOfValues();
    BinaryBitwise();

}


// Get sizes of variables with sizeof
void GetSizes()
{
    int var1{ 10 };
    bool bool1{ true };
    float var2{ 2.5f };
    double var3{ 3.4 };


    std::cout << "Int size is " << sizeof(var1) << " bytes" << std::endl;
    std::cout << "Bool size is " << sizeof(bool1) << " bytes" << std::endl;
    std::cout << "Float size is " << sizeof(var2) << " bytes" << std::endl;
    std::cout << "Double size is " << sizeof(var3) << " bytes" << std::endl;

}

// Show the same value in different Numeral System (Decimal, hexadecimal, binary..)
void ShowDiffNumSyst()
{
    int value{ 12 };                    // Decimal

    std::cout << value << std::endl;

    value = 0x0C;                       // Hexadecimal

    std::cout << value << std::endl;

    value = 0b1100;                     // Binary

    std::cout << value << std::endl;


}

void RangeOfValues()
{
    int maxS{ 2147483647 }, minS{ -2147483648 };
    unsigned int maxU{ 4294967295 }, minU{ 0 };

    maxS += 1;
    minS -= 1;

    maxU += 1;
    minU -= 1;

    std::cout << maxS << std::endl;
    std::cout << minS << std::endl;

    std::cout << maxU << std::endl;
    std::cout << minU << std::endl;
    std::cout << std::endl;

}

void BinaryBitwise()
{
    // BITWISE NOT (~) --> All bits are flipped. If it is 0 then flips to 1 and viceversa
    // BITWISE AND (&) --> Evaluates to true(1) if both bits in the colum are 1, and 0 otherwise
    // BITWISE OR (|) --> It applies to each bit, and evaluates to true (1) if one of the
    //                     bits are true(1), and 0 otherwise.

    unsigned int val1{ 3 }, val2{ 5 }, result{};

    result = val1 & val2;       // AND operation

    std::cout <<"Result of & operation between " << val1 << " and " << val2 << ": " << result << std::endl;

    result = val1 | val2;       // OR operation

    std::cout << "Result of & operation between " << val1 << " and " << val2 << ": " << result << std::endl;


    // Check if bit is 0 or 1 with & operator
   /* std::bitset<4> value3{};
    unsigned int bit1{};

    std::cout << "Number to check with bits are set? ";
    std::cin >> value3;

    bit1 = value3[0];
    */

    // Set a bit in a number with |
    std::bitset<4> value4{};
    int value{};

    std::cout << "Number to set 3rd bit in? ";
    std::cin >> value4;

    value4[3] = 1;

    std::cout << "This number with 3rd bit set " << value4 << std::endl;


    // RIGHT SHIFT
    unsigned int right{ 2048 };

    std::cout << "Before right shift " << right << std::endl;


    std::cout << "After  right shift " << (right>>1) << std::endl;  // Divide number by 2

    // LEFT SHIFT
    unsigned int left{ 2048 };

    std::cout << "Before left shift " << right << std::endl;


    std::cout << "After left shift " << (left << 1) << std::endl;  // Multiply number by 2


    // Last Exercise
    unsigned int final{ 0 };

    final = 1 << 22 | 1 << 20 | 1 << 18 | 1 << 17 | 1 << 15 | 1 << 14 | 1 << 12 | 1 << 10 | 1 << 9 | 1 << 8
        | 1 << 6 | 1 << 5 | 1 << 4 | 1 << 3 | 1 << 2 | 1 << 1 | 1 << 0;
 

    std::cout << "Number is " << final << std::endl;


}