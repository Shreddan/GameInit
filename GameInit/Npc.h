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



private:

	std::string Name;
	int Location;
	std::vector<std::string> Dialogue;
};

