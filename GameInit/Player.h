#pragma once
#include "Weapon.h"
#include "Armour.h"
#include "Quest.h"

class Player
{
public:

	//Player();
	Player(std::string n, int l, int exp, int hm, int mm, int str, int end, int wis, int intel, int loc);
	~Player();

	void AddQuest(Quest q);
	void CompleteQuest();

	void DisplayQuests();

	void to_json(nlohmann::json& j, const Player& p);
	void from_json(const nlohmann::json& j, Player& p);

//TODO: Make private 
// Add Getters/Setters

	//Base vars
	std::string Name;
	int Level;
	int CurrentExp;
	int TNL;
	int HealthMax;
	int Health;
	int ManaMax;
	int Mana;
	int Aloc;
	int Loc;

	// Player Stats
	int Strength;
	int Endurance;
	int Wisdom;
	int Intelligence;

	// Hidden vars 
	int BaseDamage;
	int BaseDefence;

	std::vector<Item*> Inventory;
	std::vector<Item*> Equipped;
	//TODO: Quest System

	std::vector<Quest> ActiveQuests;
	std::vector<Quest> CompletedQuests;

};

