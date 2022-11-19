#pragma once
#include "Entity.h"
#include "Quest.h"
class Npc : public Entity
{
public:
	Npc(std::string n, int l);
	~Npc();

	void Interact();

	std::string GetName();
	int GetLocation();
	std::string GetDialogue(int i);


	void SetLocation(int l) { this->Location = l; };
	void AddDialogue(int i, std::string s);
	void AddQuest();

private:

	std::string Name;
	int Location;
	std::map<int, std::string> Dialogue;
	std::vector<Quest> Quests;
	bool First;

};

