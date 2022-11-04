#pragma once
#include <vector>
#include <string>

class Room
{
public:
	Room(int i, int n, int e, int s, int w, int u, int d, std::string desc);
	int Id;
	std::string desc;
	std::vector<int> Exits;
};

