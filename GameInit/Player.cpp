#include "Player.h"

//Player::Player()
//{
//}

Player::Player(std::string n, int l, int hm, int mm, int str, int end, int wis, int intel)
{
	this->Name = n;
	this->Level = l;
	this->HealthMax = hm;
	this->Health = this->HealthMax;
	this->ManaMax = mm;
	this->Mana = this->ManaMax;

	this->Strength = str;
	this->Endurance = end;
	this->Wisdom = wis;
	this->Intelligence = intel;
}

Player::~Player()
{
}

