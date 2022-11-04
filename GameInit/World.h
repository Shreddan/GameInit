#pragma once
#include "Area.h"

class World
{
public:
	World(std::string n);
	~World();

	std::string Name;
	Area* CurrentArea;
	std::vector<Area> Areas;
};

