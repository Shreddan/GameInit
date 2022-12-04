#include "Player.h"

//Player::Player()
//{
//}

Player::Player(std::string n, int l, int exp, int hm, int mm, int str, int end, int wis, int intel, int loc)
{
	this->Name = n;
	this->Level = l;
	this->CurrentExp = exp;
	this->TNL = Level * 1.3f + 4;
	this->HealthMax = hm;
	this->Health = this->HealthMax;
	this->ManaMax = mm;
	this->Mana = this->ManaMax;
	this->Loc = loc;

	this->Strength = str;
	this->Endurance = end;
	this->Wisdom = wis;
	this->Intelligence = intel;

	//These are rough stand in calculations and not representative of the final
	this->BaseDamage = Strength * 7 / 5;
	this->BaseDefence = Endurance * 8 / 4;
}

Player::~Player()
{
}

void Player::AddQuest(Quest q)
{
	ActiveQuests.push_back(q);
}

void Player::CompleteQuest()
{
}

void Player::DisplayQuests()
{
}

void Player::to_json(nlohmann::json& j, const Player& p)
{
	j = nlohmann::json
	{
		{"Name", p.Name },
		{"Level", p.Level},
		{"CurrentExp", p.CurrentExp},
		{"HealthMax", p.HealthMax},
		{"ManaMax", p.ManaMax},
		{"Location", p.Loc},
		{"Area", p.Aloc},
		{"Strength", p.Strength},
		{"Endurance", p.Endurance},
		{"Wisdom", p.Wisdom},
		{"Intelligence", p.Intelligence}
	};
}

void Player::from_json(const nlohmann::json& j, Player& p)
{
	j.at("Name").get_to(p.Name);
	j.at("Level").get_to(p.Level);
	j.at("CurrentExp").get_to(p.CurrentExp);
	j.at("HealthMax").get_to(p.HealthMax);
	j.at("ManaMax").get_to(p.ManaMax);
	j.at("Location").get_to(p.Loc);
	j.at("Area").get_to(p.Aloc);
	j.at("Strength").get_to(p.Strength);
	j.at("Endurance").get_to(p.Endurance);
	j.at("Wisdom").get_to(p.Wisdom);
	j.at("Intelligence").get_to(p.Intelligence);
}


