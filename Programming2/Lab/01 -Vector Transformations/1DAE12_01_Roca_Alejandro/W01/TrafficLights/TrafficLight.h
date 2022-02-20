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
	void Draw() const;
	float getWidth() const;
	float getHeight() const;
	
	

private:
	State m_State;
	const float m_Width;
	const float m_Height;
	const float m_RadiusCircle;
	float m_AccumulatedSec;
	Color4f m_ColorLight;			// Active color light
	const Point2f m_Position;
	static const int m_NrLights{ 3 };
	Circlef m_Lights[m_NrLights]{};



};

