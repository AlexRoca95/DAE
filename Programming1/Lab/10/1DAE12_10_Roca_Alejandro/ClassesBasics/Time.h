#pragma once


class Time {

private:
	
	float m_Seconds;


public:

	Time(float seconds);
	Time(float seconds, float minutes);
	Time(float seconds, float minutes, float hours);
	~Time();


	void Print();


};