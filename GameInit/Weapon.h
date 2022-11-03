#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	Weapon();
	~Weapon();

	int GetType();

private:

	int Type;
	int DamageType;
	int BaseDamage;
	int Effect1;
	int Effect2;
	int Effect3;
};

