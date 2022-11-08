#pragma once
#include "Entity.h"
class Npc : public Entity
{
public:
	Npc(std::string n, int l);
	~Npc();

	void Interact();

	std::string GetName();
	int GetLocation();
	std::string GetDialogue(int i);

	void AddDialogue(std::string s);

private:

	std::string Name;
	int Location;
	//TODO: replace with map
	//would possibly be better for ordering?
	std::vector<std::string> Dialogue;
};

