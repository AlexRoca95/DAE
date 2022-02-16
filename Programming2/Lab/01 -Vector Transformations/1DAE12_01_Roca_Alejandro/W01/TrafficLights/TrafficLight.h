#pragma once
class TrafficLight
{
public:

	enum class State {
		green,
		orange,
		red,
		off
	};

	TrafficLight(const Point2f& pos);
	void DoHitTest(const Point2f& point);
	void Update(float elapsedSec);
	void Draw();
	//float getWidth();
	//float getHeight();

private:
	State m_State;
	Point2f m_Position;
	float m_AccumulatedSec;
	Rectf m_Armature;
	


};

