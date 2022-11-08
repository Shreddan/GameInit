#include "Npc.h"

Npc::Npc(std::string n, int l)
{
	this->Name = n;
	this->Location = l;
}

Npc::~Npc()
{
}

void Npc::Interact()
{
}

std::string Npc::GetName()
{
	return this->Name;
}

int Npc::GetLocation()
{
	return this->Location;
}

std::string Npc::GetDialogue(int i)
{
	return Dialogue.at(i);
}
