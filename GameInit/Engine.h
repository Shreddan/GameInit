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

private:

	std::deque<Action> Actions;
	std::string GameName;
};

