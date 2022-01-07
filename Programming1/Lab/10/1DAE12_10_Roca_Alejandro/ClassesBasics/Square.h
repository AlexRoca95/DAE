#pragma once


class Square {

private:
	float m_Left;
	float m_Bottom;
	float m_Size;

	float GetArea();
	float GetPerimeter();

public:

	Square(float);
	Square(float, float, float);
	~Square();

	void Print();
	void Translate(float, float);
	void SetSize(float);


};