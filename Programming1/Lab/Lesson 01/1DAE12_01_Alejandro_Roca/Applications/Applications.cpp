// Applications.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{   
    // KM
    float km{};
    int meters{}, cm{};
    std::cout << "Distance in km? ";
    std::cin >> km;

    meters = km * 1000;
    cm = meters * 100;

    std::cout << meters << " meters" << ", " << cm << "cm" << std::endl;
    

    // Angle in Radians
    float radians{}, degrees{};
    
    std::cout << "Angle in radians? ";
    std::cin >> radians;

    degrees = radians * 57.2958;
    std::cout << degrees << " degrees" << std::endl;


    // Angle in Degrees
    std::cout << "Angle in degrees? ";
    std::cin >> degrees;

    radians = degrees * 0.0174533;

    std::cout << radians << " radians" << std::endl;

    // Seconds for complete one round
    int seconds{};
    int angle = 360;

    std::cout << "Seconds of one rotation? ";
    std::cin >> seconds;

    degrees = angle / seconds;

    std::cout << degrees << " degrees/second" << std::endl;

    // Speed (km/h)
    double speed{}, minutes{}, km2{};

    std::cout << "Speed (km/h)? ";
    std::cin >> speed;
    std::cout << "Elapsed time (minutes)? ";
    std::cin >> minutes;

    km2 = (minutes * speed) / 60;
    meters = km2 * 1000;

    std::cout << meters << " meters" << std::endl;


    // Free fall accelariting
    double seconds2{}, vel{};
    std::cout << "Seconds? ";
    std::cin >> seconds2;

    vel = seconds2 * 9.8;

    std::cout << "Velocity " << vel << " meters/second" << std::endl;


    // radius of circle





    














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
