#include "World.h"

World::World(std::string n)
{
	this->Name = n;

	Areas.emplace_back("Tutorial");

	SetCurrentArea(0);
}

World::~World()
{
	delete CurrentArea;
}

Area* World::GetCurrentArea()
{
	return CurrentArea;
}
