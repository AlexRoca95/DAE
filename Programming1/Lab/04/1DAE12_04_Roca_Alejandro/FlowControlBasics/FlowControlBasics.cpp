// FlowControlBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "structs.h"
#include <iostream>


void PrintTruthTable();
void CompareTwoNumbers();
void CalculatePrice();
void ConvertDayNumber();
void CheckLeapYear();
void ConvertSeconds();
void UseActorState();
void UsePoint2f();

int main()
{
	PrintTruthTable();
	//CompareTwoNumbers();
	//CalculatePrice();
	//ConvertDayNumber();
	//CheckLeapYear();
	//ConvertSeconds();
	UseActorState();
	UsePoint2f();


}


void PrintTruthTable()
{
	bool one{ true }, two{ true };
	bool result{ false };

	std::cout << std::boolalpha;		// True and False will be printed instead of 0 and 1
	std::cout << "-- Print Truth Table --" << std::endl;
	std::cout << "Logical binary AND-operator (&&)" << std::endl;
	result = one && two;
	std::cout << one << " && " << two << " is " << result << std::endl;
	two = false;
	result = one && two;
	std::cout << one << " && " << two << " is " << result << std::endl;
	one = false;
	two = true;
	result = one && two;
	std::cout << one << " && " << two << " is " << result << std::endl;
	two = false;
	result = one && two;
	std::cout << one << " && " << two << " is " << result << std::endl;

	std::cout << "Logical binary OR-operator (||)" << std::endl;
	one = true;
	two = true;
	result = one || two;
	std::cout << one << " || " << two << " is " << result << std::endl;
	two = false;
	result = one || two;
	std::cout << one << " || " << two << " is " << result << std::endl;
	one = false;
	two = true;
	result = one || two;
	std::cout << one << " || " << two << " is " << result << std::endl;
	two = false;
	result = one || two;
	std::cout << one << " || " << two << " is " << result << std::endl;
	std::cout << std::endl;


}

void CompareTwoNumbers()
{	
	std::srand(int(time(nullptr)));

	int rand1{ 0 }, rand2{ 0 };
	rand1 = rand() % (10 - 1 + 1) + 1;  // (Till - From + 1) + From
	rand2 = rand() % (10 - 1 + 1) + 1;

	std::cout << "First number is " << rand1 << std::endl;
	std::cout << "Second number is " << rand2 << std::endl;


	if (rand1 > rand2)
	{
		std::cout << "First number is larger than second number " << std::endl;
	}
	else
	{
		std::cout << "Second number is larger than first number " << std::endl;
	}
	std::cout << std::endl;
}

void CalculatePrice()
{
	int ballons{ 0 }, result{ 0 };
	float price{ 0.00f };

	std::cout << "-- Calculate price --" << std::endl;
	std::cout << "Nr of ballpoints? ";
	std::cin >> ballons;
	

	if (ballons <= 19)
	{
		price = 4.00f;
	}
	else
	{
		if (ballons >= 20 && ballons <= 49)
		{
			price = 3.50f;
		}
		else
		{
			if (ballons >= 50 && ballons <= 100)
			{
				price = 3.25f;
			}
			else
			{
				price = 3.10f;
			}
		}
	}


	result = int(ballons * price);

	std::cout << "Total price is " << result << std::endl;
	


}

void ConvertDayNumber()
{
	int day{ 0 };

	std::cout << "Day number [1, 7]? ";
	std::cin >> day;

	switch (day)
	{
	case 1:
		std::cout << "No weekend " << std::endl;
		break;
	case 2:
	case 3: 
	case 4: 
		std::cout << "Middle of the week " << std::endl;
		break;
	case 5:
		std::cout << "Nearly weekend " << std::endl;
		break;
	case 6:
	case 7:
		std::cout << "Weekend" << std::endl;
		break;
	default:
		std::cout << "Wrong day number" << std::endl;
		break;
	}


}

void CheckLeapYear()
{
	int year{ 0 };

	std::cout << "-- Check leap year -- " << std::endl;
	std::cout << "Year? ";
	std::cin >> year;

	if (year / 4 == 0)
	{
		if (year / 100 == 0)
		{
			if (year / 400 ==0)
			{
				std::cout << "February has 28 days" << std::endl;
			}
			else
			{
				std::cout << "February has 29 days" << std::endl;
			}
		}
		else
		{
			std::cout << "February has 29 days" << std::endl;
		}
	}
	else
	{
		std::cout << "February has 28 days" << std::endl;
	}


	




}

void ConvertSeconds()
{
	int value{ 0 }, days{ 0 }, hours{ 0 }, minutes{ 0 }, seconds{ 0 };
	

	std::cout << "-- Convert seconds -- " << std::endl;
	std::cout << " Number of seconds ";
	std::cin >> value;

	days = value / 86400;		// Days
	std::cout << days << std::endl;
	hours = value % 86400;		// Hours
	hours = hours / 3600;
	std::cout << hours << std::endl;
	minutes = value / 60;		// Minutes
	minutes = minutes % 60;
	std::cout << minutes << std::endl;
	seconds = value % 60;		// Seconds
	std::cout << seconds << std::endl;

}

void UseActorState()
{
	enum class ActorState{ running, flying, falling };

	std::srand(int(time(nullptr)));

	int rand1 = rand() % (int(ActorState::falling) - int(ActorState::running) + 1) + int(ActorState::running);

	ActorState actor = ActorState(rand1);
	std::cout << "-- Define and use ActorState --" << std::endl;
	switch (actor)
	{
	case ActorState::running:
		std::cout << "Running" << std::endl;
		break;
	case ActorState::flying:
		std::cout << "flying" << std::endl;
		break;
	case ActorState::falling:
		std::cout << "falling" << std::endl;
		break;
	}


}

void UsePoint2f()
{
	//Point2f p1;
	Point2f p2{};
	Point2f p3{ 26, 27 };

	std::cout << p2.x << std::endl;
	std::cout << p3.y << std::endl;

}
