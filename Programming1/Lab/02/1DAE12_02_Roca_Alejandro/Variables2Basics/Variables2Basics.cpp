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
    //CheckOddOrEven();
    RandomNumbers();
    //Typecasting();
    //UsingStrings();

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

    std::srand(int (time(nullptr))); // Initialize random number generator (only once)

    int randomValue{};

    // RANDOM --> (Till - From + 1) + From
  /* randomValue = rand() % 51;
   std::cout << "Random value between [0, 50]: " << randomValue << std::endl;
   
   randomValue = rand() % (80 - 10 + 1) + 10;  // (Till - From + 1) + From
   std::cout << "Random value between [10, 80]: " << randomValue << std::endl;
  
  
  randomValue = rand() % (20 + 20 + 1) -20;
  std::cout << "Random value between [-20, 20]: " << randomValue << std::endl;
  
 
  randomValue = rand() % (2 + 2 + 1) - 2;
  std::cout << "Random value between [-2, 2]: " << randomValue << std::endl;

  float randomFloat{};
 
  randomFloat = (float)rand() / (RAND_MAX)+1 + (rand() % 9);
  std::cout << "Random value between [5.00, 10.00]: " << randomFloat << std::endl;
  */

    

    for (int i = 0; i < 100; i++)
    {
        randomValue = rand() % 50;      // [0, 50]
        //std::cout << "Random value between [0, 50]: " << randomValue << std::endl;
    }
    

    for (int i = 0; i < 100; i++)
    {
        randomValue = (rand() % 70) + 10;      // [10, 80]
       // std::cout << "Random value between [10, 80]: " << randomValue << std::endl;
    }
    for (int i = 0; i < 100; i++)
    {   
        // [-20, 20]
        randomValue = (rand() % 21) - 20;      
        randomValue += (rand() % 20) + 1;
       //std::cout << "Random value between [-20, 20]: " << randomValue << std::endl;
    }

    for (int i = 0; i < 100; i++)
    {
        // [-2, 2]
        randomValue = (rand() % 3) - 2;         //[-2, 0]
        randomValue += (rand() % 2) + 1;        // [-2, 0] + [1, 2] = [-2, 2]
       // std::cout << "Random value between [-2, 2]: " << randomValue << std::endl;
    }

    for (int i = 0; i < 100; i++)
    {
        // [5.00, 10.00]
        float(randomValue) =(rand() % 51 + 50) / 10.f;         //[5.00, 10.00]

       
        
        std::cout << "Random value between [5.00, 10.00]: " << randomValue << std::endl;
    }

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

    randomInt = rand() % 26;        // 26 letters for the alphabet
    randomChar = 'a' + randomInt;   // Add randomNumber to letter so we get randomLetter 
   
    std::cout << "Random letter " << randomChar << ", ASCII value " << int(randomChar) << std::endl;


    // Round values
    float value1{ 5.44f }, value2{ 5.45f }, value3{ 5.51f };
    int value4{}, value5{}, value6{}, rounded1{}, rounded2{}, rounded3{};

    value4 = int(value1);
    value5 = int(value2);
    value6 = int(value3);

    rounded1 = round(value1);
    rounded2 = round(value2);
    rounded3 = round(value3);
    
    // Differences is that with int you truncate the number and with rounded you round it
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
    std::string first{}, second{}, both{};

    std::cout << "First Word? ";
    std::cin >> first;
    std::cout << "Second Word? ";
    std::cin >> second;

    both = first + second;

    std::cout << both << std::endl;


    // Converting strings to numbers
    std::string string1{ 3 }, string2{  };
    int number1{};
    float number2{};
    

    std::cout << "One string contains " << std::to_string(number1) << std::endl;
    std::cout << "Other string contains " << std::to_string(number2) << std::endl;

}
