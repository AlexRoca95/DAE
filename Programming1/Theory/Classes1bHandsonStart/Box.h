#pragma once

class BouncingCircle;		// Forward Class Declaration
class Box
{
private:
	const Rectf m_BoundingBox;
	static const int m_NumberOfCircles{ 5 };  // Static --> It is a global variable shared with all the instances of box variables
	BouncingCircle* m_pManyCircles[ m_NumberOfCircles ];

public:
	Box(const Rectf& boundingBox);
	~Box();
	void Draw();
	void Update(float elapsedSec);
};

