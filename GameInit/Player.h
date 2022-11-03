#pragma once
#include <string>

class Player
{
public:

	Player();
	Player(int l, int hm, int mm, int str, int end, int wis, int intel);
	~Player();

	std::string Name;
	int Level;
	int HealthMax;
	int Health;
	int ManaMax;
	int Mana;

	int Strength;
	int Endurance;
	int Wisdom;
	int Intelligence;

};

