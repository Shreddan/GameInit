#pragma once
#include "Item.h"
class Armour : public Item
{
public:
	Armour(int at, int d, int w);
	~Armour();

	int GetType();
	int GetDefenceValue();
	int GetWeightValue();

	void from_json(const nlohmann::json& j, Armour& a);

private:

	int Type;
	int Atype;
	int Defence;
	int Weight;
};

