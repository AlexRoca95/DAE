#include "pch.h"
#include "Health.h"

Health::Health( int value) 
	: m_Value{value}
{
}
int Health::GetValue( ) const
{
	return m_Value;
}

Health& Health::operator+=(const int value)
{
	this->m_Value += value;

	return *this;
}

Health& Health::operator-=(const int value)
{
	this->m_Value -= value;

	return *this;
}

Health operator+(const int value, const Health& health)
{
	Health h{ health };
	
	h += value;

	return h;
}

Health operator+(const Health& health, const int value)
{
	Health h{ health };

	h += value;

	return h;
}

Health operator-(const int value, const Health& health)
{
	Health h{ health };

	h = value - health.GetValue();

	return h;
}

Health operator-(const Health& health, const int value)
{
	Health h{ health };

	h -= value;

	return h;
}