#include "pch.h"
#include "Container.h"



Container::Container(int capacity)
	:m_Capacity(capacity),
	m_Size(0),
	m_pElement(new int[capacity])  // Allocates memory for a number of ints indicated by capacity
{
}

Container::~Container()
{
	delete[] m_pElement;
	m_pElement = nullptr;
	m_Size = 0;

}


void Container::PushBack(int element)
{
	if (m_Size == m_Capacity)
	{
		// Full capacity. Add more space
		Reserve(2 * m_Capacity + 1);
	}

	// Add at the end of the container
	m_pElement[m_Size] = element;
	m_Size++;

}

int Container::Size() const
{
	return m_Size;
}

int Container::Capacity() const
{
	return m_Capacity;
}

int Container::Get(int index) const
{
	return m_pElement[index];
}

void Container::Set(int index, int newValue)
{

	m_pElement[index] = newValue;

}

void Container::Reserve(int newCapacity)
{
	int* m_pElementCopy{ new int[newCapacity] };

	// Copy the current elements to the new memory
	for (int i{ 0 }; i < m_Size; i++)
	{
		m_pElementCopy[i] = m_pElement[i];
	}

	// Deallocate the old memory
	delete[] m_pElement;
	
	// Resize and point to the first element
	m_pElement = &m_pElementCopy[0];
	m_Capacity = newCapacity;


}