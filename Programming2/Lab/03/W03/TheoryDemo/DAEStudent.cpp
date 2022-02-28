#include "pch.h"
#include "DAEStudent.h"
#include <iostream>

DAEStudent::DAEStudent(const std::string& firstName, const std::string& lastName, Major major)
	:Person{firstName, lastName},
	m_Major(major)
{
	std::cout << "Derived Constructor" << std::endl;
}

DAEStudent::~DAEStudent()
{
	std::cout << "Derived Destructor" << std::endl;
}


void DAEStudent::Identify() const
{
	std::cout << "I am a derived class DAEStudent object. My name is: " << GetName() << "\n";
}

std::string DAEStudent::GetName() const
{

	std::string name{ Person::GetName() };
	name += ", and my Major is: ";
	switch (m_Major)
	{
	case DAEStudent::Major::GD:
		name += "Game Development";
		break;
	case DAEStudent::Major::SD:
		name += "Sound Design";
		break;
	default:
		name += "Other Major";
		break;
	}

	return name;

}