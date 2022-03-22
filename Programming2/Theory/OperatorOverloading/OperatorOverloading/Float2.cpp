#include "pch.h"
#include "Float2.h"

Float2::Float2(float x, float y)
	:m_x(x), m_y(y)
{

}

Float2& Float2::operator+=(const Float2& rhs)
{
	m_x += rhs.m_x;
	this->m_y += rhs.m_y;
	return *this;
}

Float2 operator+(const Float2& lhs, const Float2& rhs)
{
	Float2 f{lhs};  // We are using copy constructor

	f += rhs;

	return f;
}

std::ostream& operator<< (std::ostream& out, const Float2 & f)
{
	out << "(" << f.m_x << ", " << f.m_y << ")";
	return out;
}

