#pragma once
#include <string>
class Player
{
public:
	Player(const std::string& name);
	~Player();
	void ShowMessage() const;
	void SetScore(int newScore);
	static int GetNumberOfPlayers();		// Static function to be able to acces the private static member var
private:
	std::string GenerateMessage() const;	// Const because it doesn't modify the object
	const std::string m_Name;
	int m_Score;
	static int m_NumberOfPlayers;			// This member variable will be shared with all the objects from the class
};
