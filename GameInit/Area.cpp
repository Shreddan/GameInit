#include "Area.h"

Area::Area(std::string n)
{
	this->Name = n;

	this->Rooms.emplace_back(0, 1, 0, 0, 0, 0, 0, "A small dimly lit room, with a single door to the North.");
	this->Rooms.emplace_back(1, 0, 1, 1, 0, 0, 0, "A corridor lined with windows, a gentle breeze blows through.");
}

Area::~Area()
{
}



