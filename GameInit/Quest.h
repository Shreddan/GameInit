#pragma once
#include <string>
#include <vector>
#include <set>

class Quest
{
public:
	Quest(int ID, int s, bool IC);
	~Quest();

	void AddTokens();

private:
	int QuestID;
	int Steps;
	std::vector<bool> Tokens;
	bool IsCompleted;
};

