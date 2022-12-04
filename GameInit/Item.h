#pragma once
#include <single_include/nlohmann/json.hpp>

class Item
{
public:

	enum Types
	{
		Weapon,
		Armour,
		Accessory,
		Misc
	};
	
	virtual int GetType() = 0;
	virtual void from_json() = 0;
};

