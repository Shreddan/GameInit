#pragma once

#include <iostream>	
#include <iomanip>
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
	void Choice(int choice);

	void Prompt();
	void Input();

	//Player Funcs
	Player* CreateChar();
	Player* LoadChar();
	void DeleteChar();

	void DisplayChar();

private:

	int State;
	bool Playing;
	std::string GameName;
	Player* CurrentPlayer = nullptr;
};

