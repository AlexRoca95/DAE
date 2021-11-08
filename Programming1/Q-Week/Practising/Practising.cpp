// Practising.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

int main()
{
    std::cout << "Hello World!\n";

    std::srand(int(time(nullptr))); // Initialize random number generator (only once!)

    int b{};

    b = 10 - 8 + 4 * 8;     // First the *. 4 * 8 = 32. Then operations from left to right. 10 -8 = 2. 2 + 32 = 34.

    std::cout << b << std::endl;

    unsigned char d{ 254 };         // Between 0 and 255
    std::cout << d << std::endl;

    unsigned int e{ 4294967295 };   // Maximum value 4,294,967,295

    int random{};

    for (int i = 0; i < 100; i++)
    {
        random = rand();            // Random value between 0 and RAND_MAX
       // std::cout << random << std::endl;
    }


    for (int i = 0; i < 100; i++)
    {
        random = rand() % 20;            // Random value between 0 and 19
        //std::cout << random << std::endl;
    }

    for (int i = 0; i < 100; i++)
    {
        random = (rand()%20) + 1;            // Random value between 1 and 20
       //std::cout << random << std::endl;
    }

    for (int i = 0; i < 100; i++)
    {
        random = (rand() % 440) + 10;            // Random value between 10 and 450
       //std::cout << random << std::endl;
    }

    for (int i = 0; i < 100; i++)
    {
        random = rand() % (450 - 10 + 1) + 10;            // Random value between 10 and 450
                                                           // rand() % (max_value - min_value + 1) + min_value
       //std::cout << random << std::endl;
    }
    for (int i = 0; i < 100; i++)
    {
        float(random) = (rand() % 100) / 100.f;            // Random value between 0.0f and 1.0f
      // std::cout << random << std::endl;
    }

    for (int i = 0; i < 100; i++)
    {
        random = (rand() % 11) -12;            // Random value between [-12, -2]
        //std::cout << random << std::endl;
    }

    for (int i = 0; i < 100; i++)
    {
        float(random) = (rand() % 11 + 2 ) / 1.f ;            // Random value between [-12, -2]
       // std::cout << random << std::endl;
    }


    for (int i = 0; i < 100; i++)
    {
        float(random) = (rand() % 101 + 20)  / 10.f;            // Random value between [2.0f, 12.0f]
        std::cout << random << std::endl;
    }


    std::string number{ "10" };

    int numbe{ };

    numbe = std::stoi(number);      // Convert string to a number

    std::cout << numbe << std::endl;
}

