#include "World.h"

World::World(std::string n)
{
	this->Name = n;

	Areas.emplace_back("Tutorial");

	this->CurrentArea = &Areas[0];
}

World::~World()
{
}
