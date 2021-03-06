#pragma once
#include <iostream>

class Float2 final
{
public:
	Float2(float x=0, float y=0);
	Float2& operator+=(const Float2& rhs);
	friend std::ostream operator<<(std::ostream& out, const Float2& f);
private:
	float m_x, m_y;

};

Float2 operator+(const Float2& lhs, const Float2& rhs);