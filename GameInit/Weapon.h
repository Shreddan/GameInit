#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	Weapon(int t, int dt, int bd, int ef1, int ef2, int ef3 = 0);
	~Weapon();

	int GetType();
	int GetDamageType();
	int GetBaseDamage();
	int GetFirstEffect();
	int GetSecondEffect();
	int GetLastEffect();

	void from_json(const nlohmann::json& j, Weapon& w);

private:

	int Type;
	int Wtype;
	int DamageType;
	int BaseDamage;
	int Effect1;
	int Effect2;
	int Effect3;
	bool isWeapon;
};

