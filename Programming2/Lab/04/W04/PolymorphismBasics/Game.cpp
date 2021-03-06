#include "pch.h"
#include <iostream>
#include "Game.h"
#include "Weapon.h"
#include "Enemy.h"
#include "PickUp.h"

Game::Game()
{

}
Game::~Game()
{
	for (GameObject* ptr : m_pGameObjects)
	{
		delete ptr;
	}

	m_pGameObjects.clear();  // Remove all elements from the vector
}

void Game::AddEnemy()
{
	m_pGameObjects.push_back(new Enemy());
}

void Game::AddPickUp()
{
	m_pGameObjects.push_back(new PickUp());
}

void Game::AddWeapon()
{
	m_pGameObjects.push_back(new Weapon());
}

void Game::ReportAll() const
{
	int seqNr{ 0 };

	std::cout << "--> All Game objects\n";
	for(GameObject* ptr : m_pGameObjects)
	{
		++seqNr;
		std::cout << seqNr << ": " << ptr->ToString() << "\n";
	}
}

void Game::ReportEnemies() const
{
	
	std::cout << "--> Enemies\n";
	for (GameObject* ptr : m_pGameObjects)
	{
		Enemy* pEnemy{ dynamic_cast<Enemy*>(ptr)};  // Dynamic cast (Downcast) 

		// Check if succesfull typecast
		if (pEnemy)
		{
			std::cout << ptr->ToString() << "\n";
		}
	}
}