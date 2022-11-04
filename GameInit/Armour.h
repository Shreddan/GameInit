#pragma once
#include "Item.h"
class Armour : public Item
{
public:
	Armour(int t, int d, int w);
	~Armour();

	int GetType();
	int GetDefenceValue();
	int GetWeightValue();

private:

	int Type;
	int Defence;
	int Weight;
};

