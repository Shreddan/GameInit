#pragma once
#include <single_include/nlohmann/json.hpp>

class Item
{
public:

	enum Types
	{
		Wep,
		Arm,
		Acc,
		Misc
	};
	
	virtual int GetType() = 0;
};

