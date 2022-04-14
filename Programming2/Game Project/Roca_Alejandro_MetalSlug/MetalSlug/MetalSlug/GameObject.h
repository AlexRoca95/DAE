#pragma once
// Abstract class from which all objects from the game will inherit
#include "Sprite.h"
#include <vector>
#include "Vector2f.h"

class Level;
class GameObject
{
public:

	enum class Type {

		avatar,
		bullet,
		bomb,
		enemyHelicopter,
		enemySoldier,
		boss,
		prisioner
	};

	GameObject( GameObject::Type id, float speed );
	virtual ~GameObject() = default;
	GameObject(const GameObject& gameObject) = delete;
	GameObject(GameObject&& gameObject) = delete;
	GameObject& operator=(const GameObject& gameObject) = delete;
	GameObject& operator=(GameObject&& gameObject) = delete;

	virtual void Draw() const = 0;
	virtual void Hit() = 0;

	// Getters
	virtual bool GetIsActive();
	virtual Rectf GetTopShape() const;
	virtual Rectf GetBotShape() const;

	// Setters
	virtual void SetIsActive(bool active);



protected:
	const Type m_Id;
				
	bool m_IsActive;			// GameObject activated or not
	bool m_IsDeath;				// GameObject is dead or not (for death animation)

	// Sprites needed for the game objects
	Sprite* m_pTopSprite;
	Sprite* m_pBottomSprite;

	const float m_Scale;

	Vector2f m_Velocity;
	const float m_Speed;
};

