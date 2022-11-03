#pragma once
#include <string>

class Player
{
public:

	//Player();
	Player(std::string n, int l, int exp, int hm, int mm, int str, int end, int wis, int intel);
	~Player();

	//Base vars
	std::string Name;
	int Level;
	int CurrentExp;
	int TNL;
	int HealthMax;
	int Health;
	int ManaMax;
	int Mana;

	// Player Stats
	int Strength;
	int Endurance;
	int Wisdom;
	int Intelligence;

	//Hidden vars
	int BaseDamage;
	int BaseDefence;

};
