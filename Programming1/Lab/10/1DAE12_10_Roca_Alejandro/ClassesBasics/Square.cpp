#include "pch.h"
#include "Square.h"
#include <iostream>

Square::Square(float size)
	:m_Size(size), m_Bottom(size), m_Left(size)
{

}

// Constructor of the class
Square::Square(float size, float bottom, float left)
	:m_Size(size), m_Bottom(bottom), m_Left(left)
{

}

// Destructor
Square::~Square()
{
	
	std::cout << "Square Destructor: Deleting all resources" << std::endl;

}

// Print information about the Square object
void Square::Print()
{
	std::cout << "Left: " << m_Left << ", " << "Bottom: " << m_Bottom << std::endl;
	std::cout << "Size: " << m_Size << std::endl;
	std::cout << "Perimeter: " << GetPerimeter() << std::endl;
	std::cout << "Area: " << GetArea() << std::endl;
	std::cout << std::endl;
}

// Translate the square to a new position
void Square::Translate(float deltaLeft, float deltaBottom)
{
	m_Left += deltaLeft;
	m_Bottom += deltaBottom;
}

// Change the size of the square
void Square::SetSize(float newSize)
{
	m_Size = newSize;
}

// Calculate the area of the square and return it
float Square::GetArea()
{
	return m_Size * m_Size;
}

// Calculate the perimeter of the square and return it
float Square::GetPerimeter()
{
	return m_Size * 4;
}