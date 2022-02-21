// Alejandro Roca Vande Sype - GD12

#include "pch.h"
#include "Square.h"
#include "Time.h"
#include <iostream>


void TestSquares();
void CompareTimes(const Time* t1, const Time* t2);
void PrintInstancesCntr(const std::string& message);

int main()
{
	TestSquares();

	PrintInstancesCntr("Before calling TestArrays");
	const int nrTimes{ 4 };
	Time* times[nrTimes]{};

	PrintInstancesCntr("After defining the Array of 4 pointers");

	for (int i{}; i < nrTimes; i++)
	{
		times[i] = new Time(i, i+1);
	}
	PrintInstancesCntr("After creating the 4 objects");

	for (int i{}; i < nrTimes; i++)
	{
		delete times[i];
		times[i] = nullptr;
	}
	PrintInstancesCntr("After deleting the 4 objects");

	

	Time* t1 = new Time(30, 10, 2);
	Time* t2 = new Time(30, 10, 2);
	CompareTimes(t1, t2);

	Time* t3 = new Time(30, 10, 2);
	Time* t4 = new Time(20, 10, 2);
	CompareTimes(t3, t4);

}

void TestSquares()
{
	Square* sq1 = new Square(10.f);

	std::cout << "Squares with constructor delegation" << std::endl;

	sq1->Print();

	std::cout << std::endl;

}

void CompareTimes(const Time* t1, const Time* t2)
{
	t1->Print();
	t2->Print();

	if (t1->GetSeconds() == t2->GetSeconds() &&
		t1->GetMinutes() == t2->GetMinutes() &&
		t1->GetHours() == t2->GetHours())
	{
		std::cout << "They are equal" << std::endl;
	}
	else
	{
		std::cout << "They are not equal" << std::endl;
	}

	std::cout << std::endl;
}

void PrintInstancesCntr(const std::string& message)
{

	std::cout << message << " -> Nr of Time objects: " << Time::GetNrInstances() << std::endl;
	
}