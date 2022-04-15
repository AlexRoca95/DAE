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
		helicopter,
		soldier,
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
	bool GetIsActive() const;
	bool GetIsDead() const;
	Rectf GetTopShape() const;
	Rectf GetBotShape() const;
	GameStage& GetGameStage() const;
	bool GetGameStageChanged() const;
	Type GetType() const;

	// Setters
	void SetIsActive(bool active);
	void SetGameStageChanged(bool stageChanged);




protected:
	const Type m_Id;
				
	bool m_IsActive;			// GameObject activated or not
	bool m_IsDead;				// GameObject is dead or not (for death animation)
	bool m_IsDying;


	// Sprite related
	Sprite* m_pTopSprite;
	Sprite* m_pBottomSprite;
	bool m_TopSpriteChanged;		// Indicates if Top sprite was changed from the previous one
	bool m_BotSpriteChanged;

	Vector2f m_Velocity;
	Vector2f m_Acceleration;
	const float m_Speed;
	

	// GameStages
	static GameStage m_GameState;					// Current stage of the game

	// To know if a stage has started or not
	static bool m_IsFirstHeliFightStart;
	static bool m_IsSecondHeliFightStart;
	static bool m_IsBossFightStart;

	static bool m_IsStageChanged;					// To know if we have change from moving to another stage

};


