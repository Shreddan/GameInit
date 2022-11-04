#pragma once
#include "Area.h"

class World
{
public:
	World();
	~World();

	std::string Name;
	std::vector<Area> Areas;
};

