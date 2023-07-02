#pragma once

#include <iostream>	
#include <iomanip>
#include <thread>
#include <fstream>
#include <windows.h>


#define WIN32_LEAN_AND_MEAN

#include "Action.h"
#include "Player.h"
#include "World.h"
#include "Npc.h"


class Engine
{
public:
	Engine();
	~Engine();

	//Setup
	void LoadAll();
	void LoadWeapons();
	void LoadArmour();
	

	//Main Engine Funcs
	void Login();
	bool Update();
	void Choice(int choice);

	void Prompt();
	void Input(int c);
	void Output(std::string s, bool newline = true);

	//Player Funcs
	Player* CreateChar();
	Player* LoadChar();

	void SaveChar();
	void DeleteChar();

	void Move();

	//Display Funcs
	void DisplayRoom();
	void DisplayChar();
	void DisplayInv();

	Room* GetCurrentRoom();
	

private:

	int State;
	bool Playing;
	std::string GameName;
	Player* CurrentPlayer = nullptr;
	World* CurrentWorld = nullptr;
	Room* CurrentRoom = nullptr;

	std::vector<Npc> Npcs; 

	std::string Breakup = "|| ><============================================>< ||";
};

