// 07Classes1HandsonTheory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Player.h"
#include <vector>

void Function(Player* pPlayer); 

int main()
{
    std::cout << "Hello World!\n";

	std::cout << "The number of instance is " << Player::GetNumberOfPlayers() << '\n';
	// object is on the heap, the pointer is on the stack!!
	Player* pHeapPlayer{ new Player{ "Mr Heap" } };
	pHeapPlayer->SetScore(20);
	
	std::cout << "The number of instance is " << Player::GetNumberOfPlayers() << '\n';

	pHeapPlayer->ShowMessage();

	Function(pHeapPlayer);

	/*
	delete pHeapPlayer;
	Function(pHeapPlayer);		// Using a dangling pointer if we dont point it to nullptr
	*/


	std::vector<Player*> playerPtrs;

	for (int i{}; i < 100; ++i)
	{
		playerPtrs.push_back(new Player(std::string{ "Player " } + std::to_string(i + 1)));
		std::cout << "Vector capacity is " << playerPtrs.capacity() <<
			" and the number of elements in it is " << playerPtrs.size() << '\n';
	}


	delete pHeapPlayer;
	pHeapPlayer = nullptr;

	Function(pHeapPlayer);

	// We need to delete the elements of the vector
	for (Player* pPlayer : playerPtrs)
	{
		std::cout << pPlayer << '\n';
		// pPlayer is a copy of the element in the vector
		delete pPlayer;
		
		 std::cout << "The number of elements in it is " << playerPtrs.size() << '\n';
	}

}

void Function(Player* pPlayer)
{
	// Always check if pointer to a class is nullptr or not
	// Or use a reference because it can never be null
	if (pPlayer)
	{
		pPlayer->SetScore(42);
		pPlayer->ShowMessage();
	}
	
}

