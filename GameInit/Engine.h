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

	void Login();
	bool Update();

	Player* CreateChar();
	Player* LoadChar();
	void DeleteChar();

private:

	bool Playing;
	std::deque<Action> Actions;
	std::string GameName;
	Player* CurrentPlayer = nullptr;
};

