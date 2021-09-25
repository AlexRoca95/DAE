// Alejandro, Roca Vande Sype - 1DAE12

#include "pch.h"
#include <iostream>


double pi = 3.141592;

int main()
{   
    // RGBA Colors
    double r{}, g{}, b{}, a{};
    std::cout << "RGBA in [0, 255]? ";
    std::cin >> r >> g >> b >> a;

    r = r/ 255.f;
    g = g / 255.f;
    b = b / 255.f;
    a = a / 255.f;

    std::cout << "RGBA in [0.0f, 1.0f]:" << std::endl;
    
    std::cout << r << std::endl;
    std::cout << g << std::endl;
    std::cout << b << std::endl;
    std::cout << a << std::endl;
    std::cout << std::endl;

    // KM
    float km{};
    int meters{}, cm{};
    std::cout << "Distance in km? ";
    std::cin >> km;

    meters = km * 1000;
    cm = meters * 100;

    std::cout << meters << " meters" << ", " << cm << "cm" << std::endl;
    std::cout << std::endl;
    

    // Angle in Radians
    double radians{}, degrees{};
    
    std::cout << "Angle in radians? ";
    std::cin >> radians;

    degrees = radians * 57.2958;
    std::cout << degrees << " degrees" << std::endl;
    std::cout << std::endl;

    // Angle in Degrees
    std::cout << "Angle in degrees? ";
    std::cin >> degrees;

    radians = degrees * 0.0174533;

    std::cout << radians << " radians" << std::endl;
    std::cout << std::endl;

    // Seconds for complete one round
    int seconds{};
    int angle = 360;

    std::cout << "Seconds of one rotation? ";
    std::cin >> seconds;

    degrees = angle / seconds;

    std::cout << degrees << " degrees/second" << std::endl;
    std::cout << std::endl;

    // Speed (km/h)
    double speed{}, minutes{}, km2{};

    std::cout << "Speed (km/h)? ";
    std::cin >> speed;
    std::cout << "Elapsed time (minutes)? ";
    std::cin >> minutes;

    km2 = (minutes * speed) / 60;
    meters = km2 * 1000;

    std::cout << meters << " meters" << std::endl;
    std::cout << std::endl;

    // Free fall accelariting
    double seconds2{}, vel{};
    std::cout << "Seconds? ";
    std::cin >> seconds2;

    vel = seconds2 * 9.8;

    std::cout << "Velocity " << vel << " meters/second" << std::endl;
    std::cout << std::endl;

    // radius of circle
    double radius{}, circumference{}, area{};
    
    std::cout << "Radius of the circle? ";
    std::cin >> radius;

    area = pi * radius * radius;
    circumference = 2 * pi * radius;

    std::cout << "Circumference: " <<  circumference << std::endl;
    std::cout << "Area: " << area << std::endl;
    std::cout << std::endl;

    //Width and height of rectangle
    double width{}, height{};
    
    std::cout << "Width and height? ";
    std::cin >> width >> height;

    area = width * height;
    circumference = 2 * (width + height);

    std::cout << "Circumference: " << circumference << std::endl;
    std::cout << "Area: " << area << std::endl;
    std::cout << std::endl;

   // Base and height of triangle
    double base{};

    std::cout << "Base and height? ";
    std::cin >> base >> height;

    area = (base * height);
    area = area / 2;

    std::cout << "Area: " << area << std::endl;
    std::cout << std::endl;




}

