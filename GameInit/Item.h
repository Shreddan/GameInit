#pragma once
#include <single_include/nlohmann/json.hpp>

class Item
{
public:
	
	virtual int GetType() = 0;
	virtual void to_json() = 0;
	virtual void from_json() = 0;
};

