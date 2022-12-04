#pragma once
#include "Room.h"

class Area
{
public:
	Area(std::string n);
	~Area();

	std::string GetName() { return this->Name; };
	

	std::string Name;
	int ID;
	std::vector<Room> Rooms;
};


