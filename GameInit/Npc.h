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

	void AddDialogue(int i, std::string s);

private:

	std::string Name;
	int Location;
	std::map<int, std::string> Dialogue;
};

