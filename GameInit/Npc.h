#pragma once
#include "Entity.h"
class Npc : public Entity
{
public:
	Npc();
	~Npc();

	std::string Name;


	void Interact();
};

