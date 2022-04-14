#pragma once
// Abstract class from which all objects from the game will inherit
#include "Sprite.h"
#include <vector>
#include "Vector2f.h"

class Level;
class GameObject
{
public:
	
	
	// Stages of the game
	enum class GameStage {
		moving,
		firstHeliFight,
		secondHeliFight,
		boss,
		end
	};
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
	virtual void CheckGameState() = 0;

	// Getters
	bool GetIsActive();
	Rectf GetTopShape() const;
	Rectf GetBotShape() const;
	GameStage& GetGameStage() const;
	Type GetType() const;

	// Setters
	void SetIsActive(bool active);




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
	
	static GameStage m_GameState;
	static bool m_IsFirstHeliFightStart;
	static bool m_IsSecondHeliFightStart;
	static bool m_IsBossFightStart;
};


