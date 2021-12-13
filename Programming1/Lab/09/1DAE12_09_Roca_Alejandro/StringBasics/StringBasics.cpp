// 1DAE12 - Roca, Alejandro

#include "pch.h"
#include <iostream>


int main()
{
    std::cout << "-- Exploring the string class -- " << std::endl;
    std::string text{"50 years of eBooks 1971-2021. The first eBook for reading enjoyment and unlimited free redistribution was created on July 4, 1971 by founder Michael S. Hart. Read more about this lasting innovation. Project Gutenberg is grateful to all volunteers who helped to reach this milestone anniversary. Project Gutenberg offers a vibrant and growing collection of the world’s great literature. Read, enjoy, and share!"};
    std::cout << text << std::endl;
    std::cout << std::endl;

    std::cout << "Length: " << text.length() << std::endl;
    std::cout << "Size: " << text.size() << std::endl;

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
