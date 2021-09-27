// Roca, Alejandro - 1DAE12

#include "pch.h"
#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>
#include <string>

void CheckOddOrEven();
void RandomNumbers();
void Typecasting();
void UsingStrings();

int main()
{
    CheckOddOrEven();
    RandomNumbers();
    Typecasting();
    UsingStrings();

    return 0;

}

// Ask user for a value and print 1 or 0 depending if it is odd or even
void CheckOddOrEven()
{
    int value1{}, result{};
    std::cout << "Introduce a number: ";
    std::cin >> value1;

    result = value1 % 2;

    std::cout << result << std::endl;

}

// Print random number values
void RandomNumbers()
{

    std::srand(int (time(nullptr))); // Initialize random number generator

    int randomValue{};

    randomValue = rand() % 51;
    std::cout << "Random value between [0, 50]: " << randomValue << std::endl;

    randomValue = rand() % 80 + 10;
    std::cout << "Random value between [10, 80]: " << randomValue << std::endl;

    randomValue = rand() % 20;
    std::cout << "Random value between [-20, 20]: " << randomValue << std::endl;
    

}

// Typecasting practising
void Typecasting()
{
    char letter;

    std::cout << "Letter? ";
    std::cin >> letter;

    // Typecast a char into an int
    std::cout << "Letter " << letter << " ASCII value " << int(letter) << std::endl;

    // Random letter from [a, z]
    std::srand(int(time(nullptr)));
    char randomChar{};
    int randomInt{};

    randomInt = rand() % 26;        // 26 letters
    randomChar = 'a' + randomInt;   // Add randomNumber to letter so we get randomLetter 
   
    std::cout << "Random letter " << randomChar << ", ASCII value " << int(randomChar) << std::endl;


    // Round values
    float value1{ 5.44 }, value2{ 5.45 }, value3{ 5.51 };
    int value4{}, value5{}, value6{}, rounded1{}, rounded2{}, rounded3{};

    value4 = int(value1);
    value5 = int(value2);
    value6 = int(value3);

    rounded1 = round(value1);
    rounded2 = round(value2);
    rounded3 = round(value3);
    
    std::cout << value1 << ", rounded " << rounded1 << ", int cast: " << value4 << std::endl;
    std::cout << value2 << ", rounded " << rounded2 << ", int cast: " << value5 << std::endl;
    std::cout << value3 << ", rounded " << rounded3 << ", int cast: " << value6 << std::endl;

    // Calculating aspect ratio
    value1 = 1920;
    value2 = 1080;
    double result{};

    result = double(value1) / double(value2);  // Typecast from int to double

    std::cout << "The aspect ratio of full HD(" << value1 << ", " << value2 << ") is :" << result << std::endl;


}


void UsingStrings()
{
    std::string emptyString;
    std::cout << emptyString << std::endl;

    std::string otherString{ "I am a string literal" };
    std::cout << otherString << std::endl;

    otherString = "Im another string literal";
    std::cout << otherString << std::endl;

    std::string userString{};
    std::cout << "Please, enter a text without spaces: ";
    std::cin >> userString;

    std::cout << userString << std::endl;


    //Concatenation of strings


}
