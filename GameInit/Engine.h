#pragma once

#include <iostream>	
#include <iomanip>
#include <thread>
#include <windows.h>

#define WIN32_LEAN_AND_MEAN

#include "Action.h"
#include "Player.h"
#include "World.h"


class Engine
{
public:
	Engine();
	~Engine();

	//Main Engine Funcs
	void Login();
	bool Update();
	void Choice(int choice);

	void Prompt();
	void Input(int c);

	//Player Funcs
	Player* CreateChar();
	Player* LoadChar();
	void DeleteChar();

	void Move();

	//Display Funcs
	void DisplayRoom();
	void DisplayChar();

	

	Room* GetCurrentRoom();
	

private:

	int State;
	bool Playing;
	std::string GameName;
	Player* CurrentPlayer = nullptr;
	World* CurrentWorld = nullptr;
	Room* CurrentRoom = nullptr;
};

