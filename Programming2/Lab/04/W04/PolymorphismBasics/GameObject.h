#pragma once
#include <string>

class GameObject
{
public:
	GameObject(int id );
	virtual ~GameObject( );
	// Implicitly defined copy/move constructors and operator= are ok
	virtual std::string ToString() const = 0;  // Cant instantiate anymore and class becomes abstract
protected:
	int m_Id;

private: 
};



