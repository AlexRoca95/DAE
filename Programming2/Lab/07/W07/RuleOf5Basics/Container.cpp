#include "pch.h"
#include "Container.h"
#include <cassert>

Container::Container( int capacity ) 
	: m_Size{ 0 }
	, m_Capacity{ capacity }
	, m_pElement{ new int[capacity] }
{
}


Container::Container(const Container& c1)
	: m_Size{ c1.m_Size }
	, m_Capacity{ c1.m_Capacity }
	, m_pElement{ new int[c1.m_Capacity] }
{

	for (int i{}; i < m_Capacity; i++)
	{
		m_pElement[i] = c1.m_pElement[i];
	}

}

Container::Container(Container&& c1)
	: m_Size{c1.m_Size}
	, m_Capacity{c1.m_Capacity}
	, m_pElement{c1.m_pElement}
{
	c1.m_pElement = nullptr;
	c1.m_Size = 0;
	c1.m_Capacity = 0;
}

Container& Container::operator=(const Container& c1)
{
	if (&c1 != this)  // Check we are not copying the same object
	{
		m_Size = c1.m_Size;
		m_Capacity = c1.m_Capacity;
		delete[] m_pElement;  // Delete the old heap object
		
		m_pElement = new int[c1.m_Capacity];
		for (int i{}; i < c1.m_Capacity; i++)
		{
			m_pElement[i] = c1.m_pElement[i];
		}
	}

	return *this;
}

Container& Container::operator= (Container&& c1)
{
	if (&c1 != this)
	{
		delete[] m_pElement;
		m_Size = c1.m_Size;
		m_Capacity = c1.m_Capacity;
		m_pElement = c1.m_pElement;

		c1.m_pElement = nullptr;
		c1.m_Size = 0;
		c1.m_Capacity = 0;
	}

	return *this;
}

Container::~Container( ) 
{ 
	delete[] m_pElement; 
}

int Container::Size( ) const
{ 
	return m_Size; 
}

int Container::Capacity( ) const
{
	return m_Capacity;
}

int Container::Get( int index ) const
{
	assert( index >= 0 && index < m_Size );
	return m_pElement[index];
}

void Container::Set( int index, int value )
{
	assert( index >= 0 && index < m_Size );
	m_pElement[index] = value;
}

void Container::PushBack( int value )
{
	if ( !( m_Size < m_Capacity ) )
	{
		Reserve( m_Capacity * 2  + 1);
	}
	m_pElement[m_Size] = value;
	++m_Size;
}

//int Container::operator[](int index) const
int& Container::operator[](int index) 
{
	assert(index >= 0 && index < m_Size);
	return m_pElement[index];
}

int Container::operator[](int index) const
{
	assert(index >= 0 && index < m_Size);
	return m_pElement[index];
}

void Container::Reserve( int newCapacity )
{
	if ( newCapacity <= m_Capacity )
	{
		return;
	}

	// Dynamically allocate memory
	int * pNew = new int[newCapacity] {};
	// Copy the elements into this new memory
	for ( int i{ 0 }; i < m_Size; ++i )
	{
		pNew[i] = m_pElement[i];
	}
	// Free the old memory
	delete[] m_pElement;

	// Adapt the data members to this new situation
	m_pElement = pNew;
	m_Capacity = newCapacity;
}



