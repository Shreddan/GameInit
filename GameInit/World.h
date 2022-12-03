#pragma once
#include "Area.h"

class World
{
public:
	World(std::string n);
	~World();

	void SetCurrentArea(int i) { this->CurrentArea = &this->Areas[i]; }

	Area* GetCurrentArea();

private:
	std::string Name;
	Area* CurrentArea;
	std::vector<Area> Areas;
};

 