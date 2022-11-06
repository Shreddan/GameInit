#pragma once
#include "Entity.h"
class Npc : public Entity
{
public:
	Npc();
	~Npc();

	void Interact();

	std::string Name;
	std::vector<std::string> Dialogue;
};

