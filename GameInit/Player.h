#pragma once
#include <string>

class Player
{
public:

	Player();
	Player(int l, int hm, int mm);
	~Player();

	std::string Name;
	int Level;
	int HealthMax;
	int Health;
	int ManaMax;
	int Mana;


};

