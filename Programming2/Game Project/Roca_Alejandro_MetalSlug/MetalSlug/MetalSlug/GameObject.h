#pragma once
// Abstract class from which all objects from the game will inherit
#include "Sprite.h"

class Level;
class GameObject
{
public:
	GameObject(const int id);
	virtual ~GameObject() = default;
	GameObject(const GameObject& gameObject) = delete;
	GameObject(GameObject&& gameObject) = delete;
	GameObject& operator=(const GameObject& gameObject) = delete;
	GameObject& operator=(GameObject&& gameObject) = delete;

	virtual void Draw() const = 0;
	virtual void Update(float elapsedSeconds, const Level* level) = 0;

protected:
	int m_Id;
	const float m_Scale;				// Scale for all the gameObjects

	// Sprites needed for the game objects
	Sprite* m_pTopSprite;
	Sprite* m_pBottomSprite;

	
};

