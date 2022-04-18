// Base Class for all enemies
#include "GameObject.h"

#pragma once
class Avatar;
class Level;
class Enemy : public GameObject
{

public:
	// Actions that the enemy can do
	enum class ActionState {

		state1,
		state2,
		state3,
		state4,
		state5

	};

	Enemy(const GameObject::Type& id, const Point2f& startPos, int health, const Point2f& speed, 
		 bool comingFromRight, const Point2f& acceleration);
	virtual ~Enemy() = default;
	Enemy(const Enemy & enemy) = delete;
	Enemy(Enemy && enemy) = delete;
	Enemy& operator=(const Enemy & enemy) = delete;
	Enemy& operator=(Enemy && enemy) = delete;


	virtual void Draw() const = 0;
	virtual void CheckGameState() = 0;
	virtual void Update(float elapsedSec, Avatar* avatar, const Level* level) = 0;

protected:

	ActionState m_ActionState;
	ActionState m_PreviousAction;
	int m_Health;


	

};

