// 1DAE12 Alejandro Roca Vande Sype

#include "pch.h"
#include <iomanip>      // std::setw
#include <math.h>
#include <iostream>


float g_PI{ 3.141592f };

int Sum(int, int b=120);
int Multiply(int, int b=2);
void TestMultiply();
void CalcCosSin(float, float&, float&);
void TestCalcCosSin();
float GetRandAngle(float);

int main()
{
    srand(unsigned int(time(nullptr)));

    int a{ 10 }, b{ 30 }, result{};

    result = Sum(a);    // Calling the function using default value

    std::cout << result << std::endl;

   // TestMultiply();

    TestCalcCosSin();



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
    std::cin >> n1 >> n2;

    result = Multiply(n1);      // Using the default value

    std::cout << n1 << " * " << n2 << " = " << result << std::endl;


    std::cout << "4 numbers to multiply? " << std::endl;
    std::cin >> n1 >> n2 >> n3 >> n4;

    result = Multiply(n1, n2);
    result = Multiply(result, n3);
    result = Multiply(result, n4);

    std::cout << n1 << " * " << n2 << " * " << n3 << " * " << n4 << " = " << result << std::endl;

}

void CalcCosSin(float angle, float& sin, float& cos)
{
    // Calculate cos and sin of a radian angle
    cos = cosf(angle);
    sin = sinf(angle);  // No need to return them because we passed by reference
}

void TestCalcCosSin()
{
    float angle{}, sin{}, cos{};
    std::cout << "-- Function that calculates cosine and sine --" << std::endl;
    std::cout << std::setw(10);
    std::cout << "Radians";
    std::cout << std::setw(10);
    std::cout << "Cos";
    std::cout << std::setw(10);
    std::cout << "Sin";
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
    {
       angle = GetRandAngle(angle);
       CalcCosSin(angle, sin, cos);
       std::cout << std::setw(10);                  // Table form for displaying the results
       std::cout << std::setprecision(2) << angle;  // 2 decimals only
       std::cout << std::setw(10);
       std::cout << std::setprecision(2) << cos;
       std::cout << std::setw(10);
       std::cout << std::setprecision(2) << sin;

       std::cout << std::endl;
    }



}

// Get a random angle in radians between 0 and 2*PI
float GetRandAngle(float angle)
{
    angle = float(std::rand() % 360);  // Random angle between 0 and 360

    angle *= g_PI / 180;        // Calculate the angle in radians

    return angle;
}