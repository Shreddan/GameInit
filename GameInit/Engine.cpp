#include "Engine.h"

Engine::Engine()
{
	this->GameName = "IhaveNoIdeaYetButSoon";
	this->Playing = false;
}

Engine::~Engine()
{
	delete CurrentPlayer;
}

void Engine::Login()
{
	int choice = 0;
	std::cout << "Welcome to " + GameName + "..." << std::endl;
	std::cout << "What would you like to do? (enter a number)" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "1. Create Character " << std::endl;
	std::cout << "2. Load Character " << std::endl;
	std::cout << "3. Delete Character " << std::endl;
	std::cout << "4. Help " << std::endl;
	std::cout << "5. Quit " << std::endl;

	std::cin >> choice;
	
	switch (choice)
	{
		default:
		{
			break;
		}
		case 1:
		{
			CurrentPlayer = CreateChar();
			break;
		}
		case 2:
		{
			CurrentPlayer = LoadChar();
			break;
		}
		case 3:
		{
			DeleteChar();
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
	}

	if (CurrentPlayer != nullptr)
	{
		Playing = true;
	}

	if (Playing)
	{
		Update();
	}
	else
	{
		return;
	}
}

bool Engine::Update()
{
	while (Playing)
	{
		return true;
	}

	return false;
}

Player* Engine::CreateChar()
{
	
}

Player* Engine::LoadChar()
{
}

void Engine::DeleteChar()
{
}
