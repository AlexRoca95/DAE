// Roca, Alejandro - 1DAE12

#include "pch.h"
#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>


void TestOneParFunctions();
void TestTwoParFunctions();

int main( )
{
	// 1. Show my data
	std::cout << "My name is Roca, Alejandro" << std::endl;
	std::cout << "I am in group 1DAE12" << std::endl << std::endl;

	// 2. Show my student history
	std::cout << "Name of my high school: Torrevieja " << std::endl;
	std::cout << "In the last year I had 0 hours math a week" << std::endl << std::endl;

	TestOneParFunctions();			// Call function
	TestTwoParFunctions();

	// Wait
	std::cout << "Push ENTER to quit\n";
	std::cin.get( );

	return 0;
}




void TestOneParFunctions()
{
	std::cout << "Use existing functions with 1 parameter \n";

	// With literal value
	double value = cos(0);

	std::cout << "Angle: 0" << std::endl;
	std::cout << "Cos: " << value << std::endl;

	// With variable
	double angle{ 0 };
	value = cos(angle);

	std::cout << "Angle: " << angle << std::endl;
	std::cout << "Cos: " << value << std::endl;

	// More angle values with PI
	double pi = 3.1415926535;

	angle = pi / 4;
	value = cos(angle);

	std::cout << "Angle: " << angle << std::endl;
	std::cout << "Cos: " << value << std::endl;

	angle += pi / 4;
	value = cos(angle);

	std::cout << "Angle: " << angle << std::endl;
	std::cout << "Cos: " << value << std::endl;

	angle += pi / 4;
	value = cos(angle);

	std::cout << "Angle: " << angle << std::endl;
	std::cout << "Cos: " << value << std::endl;

	angle = pi;
	value = cos(angle);

	std::cout << "Angle: " << angle << std::endl;
	std::cout << "Cos: " << value << std::endl;

	// Using as a parameter the result of an expression
	value = cos(angle * 2);

	std::cout << "Angle: " << angle * 2 << std::endl;
	std::cout << "Cos: " << value << std::endl;





}


// Using existing functions with 2 parameters
void TestTwoParFunctions()
{	
	std::cout << std::endl;
	std::cout << "Use existing functions with more parameters \n";

	// POW function
	int value1{ 2 }, value2{ 8 };
	
	double result = pow(value1, value2);

	std::cout << "POW of " << value1 << ", " << value2 << ": " << result << std::endl;
	std::cout << std::endl;

	// Pithagoras Theorem
	int sideA{ 3 }, sideB{ 4 };
	double sumAB{}, powA{}, powB{};

	// a*a + b*b = c*c
	powA = pow(sideA, 2);
	powB = pow(sideB, 2);

	sumAB = powA + powB;

	result = sqrt(sumAB);

	std::cout << "Hypotenuse of a triangle with short sides " << sideA << ", " << sideB <<
		" is " << result << std::endl;

}

