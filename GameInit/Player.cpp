#include "Player.h"

Player::Player()
{
}

Player::Player(int l, int hm, int mm)
{
	this->Level = l;
	this->HealthMax = hm;
	this->Health = this->HealthMax;
	this->ManaMax = mm;
	this->Mana = this->ManaMax;
}

Player::~Player()
{
}

