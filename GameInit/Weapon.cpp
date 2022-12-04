#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::Weapon(int t, int dt, int bd, int ef1, int ef2, int ef3)
{
}

Weapon::~Weapon()
{
}

int Weapon::GetType()
{
	return 0;
}

int Weapon::GetDamageType()
{
	return this->DamageType;
}

int Weapon::GetBaseDamage()
{
	return this->BaseDamage;
}

int Weapon::GetFirstEffect()
{
	return this->Effect1;
}

int Weapon::GetSecondEffect()
{
	return this->Effect2;
}

int Weapon::GetLastEffect()
{
	return this->Effect3;
}


void Weapon::from_json(const nlohmann::json& j, Weapon& w)
{
	j.at("Type").get_to(w.Type);
	j.at("DamageType").get_to(w.DamageType);
	j.at("BaseDamage").get_to(w.BaseDamage);
	j.at("Effect1").get_to(w.Effect1);
	j.at("Effect2").get_to(w.Effect2);
	j.at("Effect3").get_to(w.Effect3);
}
