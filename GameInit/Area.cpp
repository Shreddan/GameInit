#include "Area.h"

Area::Area(std::string n)
{
	this->Name = n;

	this->Rooms.emplace_back(1, 2, 0, 0, 0, 0, 0, "A small dimly lit room, with a single door to the North.");
	this->Rooms.emplace_back(2, 0, 3, 1, 0, 0, 0, "A corridor lined with windows, a gentle breeze blows through.");
	this->Rooms.emplace_back(3, 0, 0, 0, 2, 0, 0, "A trapdoor leading down is at the center of the room.");
}

Area::~Area()
{
}



