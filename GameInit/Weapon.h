#pragma once
#include <string>

#include <single_include/nlohmann/json.hpp>

class Weapon
{
public:
	Weapon();
	Weapon(int wt, int dt, int bd, int ef1, int ef2, int ef3 = 0);
	~Weapon();

	/*std::string GetName();
	int GetType();
	int GetDamageType();
	int GetBaseDamage();
	int GetFirstEffect();
	int GetSecondEffect();
	int GetLastEffect();*/

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

void to_json(nlohmann::json& j, const Weapon& w);
void from_json(const nlohmann::json& j, Weapon& w);
