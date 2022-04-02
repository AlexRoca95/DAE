#pragma once
// Abstract class from which all objects from the game will inherit
#include "Sprite.h"

class Level;


class GameObject
{
public:
	GameObject(int id);
	virtual ~GameObject() = default;
	virtual void Draw() const = 0;
	virtual void Update(float elapsedSeconds, const Level& level) = 0;


protected:
	int m_Id;

	// Sprites needed for the game objects
	Sprite* m_pTopSprite;
	Sprite* m_pBottomSprite;

	
};

