// FunctionsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <chrono>



struct Point2f
{
    float x;
    float y;
};

// Forward declaration of the function
int Sum(int, int);
int Multiply(int, int);
void TestMultiply();
int Modulo(int, int);
void PrintIntegers(int, int);
void CalcElapsedTime(int, int);
int GetRandInt(int, int);
void TestRandInt();
float GetDistance(float, float, float, float);
float GetDistance(Point2f, Point2f);
void TestGetDistance();


int main()
{
    
    int a{ 30 }, b{ 50 }, res{ };
   // res = Sum(a, b);
    
    //std::cout << "The Sum of " << a << " and " << b << "is: " << res << std::endl;


    //TestMultiply();

   // a = 21;
    //b = 6;
    //res = Modulo(a, b);
    //std::cout << "The modulo " << b << " of " << a << " is: " << res << std::endl;

   // PrintIntegers(a, b);

    //CalcElapsedTime(a, b);
    //a = 0;
    //b = 400;

    //CalcElapsedTime(a, b);


    //TestRandInt();

    TestGetDistance();
}

// Add two numbers
int Sum(int a, int b)
{

    int result{  };

    result = a + b;

    return result;

}

int Multiply(int a, int b)
{
    return a * b;
}

void TestMultiply()
{
    int n1{ }, n2{}, n3{}, n4{}, result{};

    std::cout << "-- Function that calculates the product of 2 integers -- " << std::endl;

    std::cout << "2 numbers to multiply? " << std::endl;
    std::cin >> n1 >>  n2;

    result = Multiply(n1, n2);

    std::cout << n1 << " * " << n2 << " = " << result << std::endl;


    std::cout << "4 numbers to multiply? " << std::endl;
    std::cin >> n1 >> n2 >> n3 >> n4;

    result = Multiply(n1, n2);
    result = Multiply(result, n3);
    result = Multiply(result, n4);

    std::cout << n1 << " * " << n2 << " * " << n3 << " * " << n4 << " = " << result << std::endl;

}

// Modulo without using % operator
int Modulo(int a, int b)
{
    int result{};

    result = a / b;

    result = a - (result * b);  // We get the remainder

    return result;


}

// Print integers in the given interval
void PrintIntegers(int a, int b)
{   
    std::cout << "Interval [ " << a << ", " << b << ']' << std::endl;
    for (a; a <= b; a++)
    {
        std::cout << a << " ";
    }

    std::cout << std::endl;


}

void CalcElapsedTime(int a, int b)
{
    // Get the current time
    std::chrono::steady_clock::time_point startTime{ std::chrono::steady_clock::now() };


    PrintIntegers(a, b);

    // Get the current time again after calling the function
    std::chrono::steady_clock::time_point endTime{ std::chrono::steady_clock::now() };

    // Get the elapsed time
    std::chrono::duration<float, std::milli> elapsedTime{ endTime - startTime };
    
     // Convert the type to float. This ways std::cout can print it
    std::cout << "This print task took " << elapsedTime.count() << " miliseconds." << std::endl;
   

}


int GetRandInt(int a, int b)
{
    int result{};

    b = b - 1;

    result = rand() % b + a;

    return result;
}

void TestRandInt()
{   
    int n1{}, n2{}, result{};
    std::cout << "-- Function that generates a random number in a given interval -- " << std::endl;
    std::cin >> n1 >> n2;
    result = GetRandInt(n1, n2);

    std::cout << "In [ " << n1 << ", " << n2 << " ]" << result << std::endl;

    std::cin >> n1 >> n2;
    result = GetRandInt(n1, n2);

    std::cout << "In [ " << n1 << ", " << n2 << " ]" << result << std::endl;

    std::cin >> n1 >> n2;
    result = GetRandInt(n1, n2);

    std::cout << "In [ " << n1 << ", " << n2 << " ]" << result << std::endl;

}

float GetDistance(float x1, float y1, float x2, float y2)
{
    // Apply pithagoream theorem
    float resultX{}, resultY{}, result{};

    // X value
    resultX = x2 - x1;
    resultX *= resultX;
    // Y value
    resultY = y2 - y1;
    resultY *= resultY;

    // Square root of the adittion of the results
    result = sqrt(resultX + resultY);


    return result;

}


float GetDistance(Point2f pos1, Point2f pos2)
{
    float resultX{}, resultY{}, result{};

    // X value
    resultX = pos2.x - pos1.x;
    resultX *= resultX;
    // Y value
    resultY = pos2.y - pos1.y;
    resultY *= resultY;

    // Square root of the adittion of the results
    result = sqrt(resultX + resultY);

    return result;
}



void TestGetDistance()
{
    float n1X{ 0.41f }, n1Y{ 184.7f }, n2X{ 63.34f }, n2Y{ 265.00f };

    Point2f point1{};
    point1.x = n1X;
    point1.y = n1Y;

    Point2f point2{};
    point2.x = n2X;
    point2.y = n2Y;

    float result1{}, result2{};
    std::cout << "-- Function that calculates the distance between 2 points -- " << std::endl;
    

    std::cout << "Distance between [ " << n1X << ", " << n1Y << "]" << "and [ " << n2X << ", " << n2Y << " ]" << std::endl;

    result1 = GetDistance(n1X, n1Y, n2X, n2Y);
    result2 = GetDistance(point1, point2);
    std::cout << "Calling one version: " << result1 << std::endl;
    std::cout << "Calling second version: " << result2 << std::endl;



}

