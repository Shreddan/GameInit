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

	bool Update();

private:

	

	std::deque<Action> Actions;
};

