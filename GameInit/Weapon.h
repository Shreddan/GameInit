#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	Weapon(int t, int dt, int bd, int ef1, int ef2, int ef3 = 0);
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

