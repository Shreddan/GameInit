#include "Player.h"

//Player::Player()
//{
//}

Player::Player(std::string n, int l, int exp, int hm, int mm, int str, int end, int wis, int intel)
{
	this->Name = n;
	this->Level = l;
	this->CurrentExp = exp;
	this->TNL = Level * 1.3f + 4;
	this->HealthMax = hm;
	this->Health = this->HealthMax;
	this->ManaMax = mm;
	this->Mana = this->ManaMax;
	this->Encumbrance = ;

	this->Strength = str;
	this->Endurance = end;
	this->Wisdom = wis;
	this->Intelligence = intel;

	this->BaseDamage = Strength * 7 / 5;
	this->BaseDefence = Endurance * 8 / 4;
}

Player::~Player()
{
}

