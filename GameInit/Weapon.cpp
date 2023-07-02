#include "Weapon.h"
#include "Item.h"

Weapon::Weapon()
{
	this->Type = Item::Types::Wep;
}

Weapon::Weapon(int wt, int dt, int bd, int ef1, int ef2, int ef3)
{
	this->Type = Item::Types::Wep;
}

Weapon::~Weapon()
{
}

std::string Weapon::GetName()
{
	return this->Name;
}

int Weapon::GetType()
{
	return this->Type;
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
