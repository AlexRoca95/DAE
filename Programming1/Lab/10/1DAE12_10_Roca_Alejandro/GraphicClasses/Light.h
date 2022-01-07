#pragma once

class Light
{
private:
	Rectf m_Rect;
	bool m_IsOn;
	Color4f m_Color;
	

public:
	Light(const Rectf& rect, const Color4f& color);
	void Draw();
	bool IsHit(const Point2f& pos);
	bool IsOn();
	

};

