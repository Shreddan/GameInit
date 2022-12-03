#pragma once
#include "Room.h"

class Area
{
public:
	Area(std::string n);
	~Area();

	std::string GetName() { return this->Name; };
	

	std::string Name;
	std::vector<Room> Rooms;
};


