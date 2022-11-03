#include "Engine.h"

Engine::Engine()
{
	this->GameName = "IhaveNoIdeaYetButSoon"
}

Engine::~Engine()
{
}

void Engine::Login()
{
	std::cout << "Welcome to " + GameName + "..." << std::endl;
	std::cout << "What would you like to do?" << std::endl;
}

bool Engine::Update()
{
	return true;
}
