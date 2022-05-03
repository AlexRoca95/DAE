#pragma once
// Abstract class from which all objects from the game will inherit
#include "Sprite.h"
#include "Vector2f.h"
#include <vector>


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

	// Type of GameObject
	enum class Type {

		avatar,
		bullet,
		bomb,
		grenade,
		helicopter,
		soldier,
		soldierShield,
		boss,
		prisoner,
		item,
		shield
	};


	GameObject( const GameObject::Type& id, const Point2f& startPos, const Point2f& speed, bool comingFromRight ,
		const Point2f& acceleration = Point2f{0.f, g_Gravity} );
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
	bool GetIsDying() const;
	bool GetIsComingFromRight() const;
	bool GetGameStageChanged() const;
	Rectf GetTopShape() const;
	Rectf GetBotShape() const;
	GameStage& GetGameStage() const;
	Type GetType() const;
	

	// Setters
	void SetIsActive(bool active);
	void SetGameStageChanged(bool stageChanged);




protected:
	// Init data of the game object
	virtual void Initialize() = 0;

	// Gravity
	void Falling(float elapsedSec, const Level* level);

	// General
	const Type m_Id;
	Point2f m_StartPosition;
				
	bool m_IsActive;								// GameObject activated or not
	bool m_IsDead;									// GameObject is dead or not (for death animation)
	bool m_IsDying;
	bool m_IsComingFromRight;						// GameObject appears from right of the window of not

	// Sprite related
	Sprite* m_pTopSprite;
	Sprite* m_pBottomSprite;
	bool m_TopSpriteChanged;						// Indicates if Top sprite was changed from the previous one
	bool m_BotSpriteChanged;

	// Physics
	Vector2f m_Velocity;
	Vector2f m_Acceleration;
	const Point2f m_Speed;
	
	// GameStages
	static GameStage m_GameState;					// Current stage of the game
	// To know if a stage has started or not
	static bool m_IsFirstHeliFightStart;
	static bool m_IsSecondHeliFightStart;
	static bool m_IsBossFightStart;

	// To know if we have change from moving to another stage
	static bool m_IsStageChanged;					

};


