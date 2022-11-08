#include "Quest.h"

Quest::Quest(int ID, int s, bool IC)
{
	this->QuestID = ID;
	this->Steps = s;
	this->IsCompleted = false;
}

Quest::~Quest()
{
}
