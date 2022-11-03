#pragma once

#include <iostream>	
#include <iomanip>
#include <deque>

#include "Action.h"
#include "Player.h"

class Engine
{
public:
	Engine();
	~Engine();

	//Main Engine Funcs
	void Login();
	bool Update();

	//Player Funcs
	Player* CreateChar();
	Player* LoadChar();
	void DeleteChar();

	void DisplayChar();

private:

	bool Playing;
	std::deque<Action> Actions;
	std::string GameName;
	Player* CurrentPlayer = nullptr;
};

