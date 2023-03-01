#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	Weapon(int wt, int dt, int bd, int ef1, int ef2, int ef3 = 0);
	~Weapon();

	std::string GetName();
	int GetType();
	int GetDamageType();
	int GetBaseDamage();
	int GetFirstEffect();
	int GetSecondEffect();
	int GetLastEffect();

	void from_json(const nlohmann::json& j, Weapon& w);

private:

	std::string Name;
	int Type;
	int Wtype;
	int DamageType;
	int BaseDamage;
	int Effect1;
	int Effect2;
	int Effect3;
	bool isWeapon;
};

