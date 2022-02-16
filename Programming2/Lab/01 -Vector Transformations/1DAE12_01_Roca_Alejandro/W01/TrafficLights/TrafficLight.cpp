#include "pch.h"
#include "TrafficLight.h"
#include "utils.h"



TrafficLight::TrafficLight(const Point2f& pos)
	:m_State(State::off),
	m_AccumulatedSec(0.f)
{

}


void TrafficLight::DoHitTest(const Point2f& point)
{


}
void TrafficLight::Update(float elapsedSec)
{

}
void TrafficLight::Draw()
{
	//m_Armature.left

	//utils::DrawRect()
}
/*
float TrafficLight::getWidth()
{
	
}
float TrafficLight::getHeight()
{

}
*/