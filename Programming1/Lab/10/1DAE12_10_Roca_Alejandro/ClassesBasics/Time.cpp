#include "pch.h"
#include "Time.h"
#include <iostream>


Time::Time(float seconds)
	:m_Seconds(seconds)
{

}

Time::Time(float seconds, float minutes)
	: m_Seconds((minutes * 60) + seconds)
{
	
}

Time::Time(float seconds, float minutes, float hours)
	: m_Seconds((hours * 3600) + (minutes * 60) + seconds)
{

}


void Time::Print()
{
	int hours{};
	int minutes{};
	int seconds{};

	hours = m_Seconds / 3600;
	minutes = int(m_Seconds) / 60;
	seconds = int(m_Seconds) % 60;

	std::cout << "Time: " << hours << ":" << minutes << ":" << seconds << std::endl;

}