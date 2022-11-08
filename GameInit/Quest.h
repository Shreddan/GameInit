#pragma once
class Quest
{
public:
	Quest();
	~Quest();

private:
	int QuestID;
	int Steps;
	std::vector<bool> Tokens;
};

