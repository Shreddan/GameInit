#include "Armour.h"

Armour::Armour(int t, int d, int w)
{
    this->Type = t;
    this->Defence = d;
    this->Weight = w;
}

Armour::~Armour()
{
}

int Armour::GetType()
{
    return this->Type;
}

int Armour::GetDefenceValue()
{
    return this->Defence;
}

int Armour::GetWeightValue()
{
    return this->Weight;
}

void Armour::from_json(const nlohmann::json& j, Armour& a)
{
    j.at("Type").get_to(a.Type);
    j.at("Defence").get_to(a.Defence);
    j.at("Weight").get_to(a.Weight);
}
