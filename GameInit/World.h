#pragma once
#include "Area.h"

class World
{
public:
	World(std::string n);
	~World();

	std::string Name;
	std::vector<Area> Areas;
};

