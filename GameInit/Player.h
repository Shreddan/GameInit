#pragma once
#include <string>
#include <vector>

#include "Weapon.h"
#include "Armour.h"

class Player
{
public:

	//Player();
	Player(std::string n, int l, int exp, int hm, int mm, int str, int end, int wis, int intel, int loc);
	~Player();

//TODO : Make private and add Getters/Setters | Player.h
	//Base vars
	std::string Name;
	int Level;
	int CurrentExp;
	int TNL;
	int HealthMax;
	int Health;
	int ManaMax;
	int Mana;
	int Location;

	// Player Stats
	int Strength;
	int Endurance;
	int Wisdom;
	int Intelligence;

	//Hidden vars 
	int BaseDamage;
	int BaseDefence;

	std::vector<Item> Inventory;
	std::vector<Item> Equipped;
	//TODO : Add a Quest System 
	//std::vector<Quest> Questlog;


};

