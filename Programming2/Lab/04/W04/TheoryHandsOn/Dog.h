#pragma once
#include "Animal.h"

class Dog final : public Animal
{
public:
	Dog();
	virtual ~Dog();			// We add the virtual for readibility
	virtual void MakeSound()const override;
	void SetSurveillanceMode(bool value);
private:
	bool m_SurveillanceMode;
};

 
