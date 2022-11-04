#include "Room.h"

Room::Room(int i, int n, int e, int s, int w, int u, int d, std::string desc)
{
	this->Id = i;
	Exits.push_back(n);
	Exits.push_back(e);
	Exits.push_back(s);
	Exits.push_back(w);
	Exits.push_back(u);
	Exits.push_back(d);

}
