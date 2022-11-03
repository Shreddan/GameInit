#include "Engine.h"

Engine::Engine()
{
	this->GameName = "IhaveNoIdeaYetButSoon";
	this->Playing = false;
	this->State = 0;
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
	std::cout << std::endl;

	std::cin >> choice;
	std::cout << std::endl;

	Choice(choice);

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
		Prompt();
		Input();
	}

	return false;
}

void Engine::Choice(int choice)
{
	switch (choice)
	{
	default:
	{
		break;
	}
	case 1:
	{
		CurrentPlayer = CreateChar();
		DisplayChar();
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
}

void Engine::Prompt()
{
	std::cout << "Level : " << CurrentPlayer->Level << " || Exp : " << CurrentPlayer->CurrentExp << "/" << CurrentPlayer->TNL;
	std::cout << " || HP : " << CurrentPlayer->Health << "/" << CurrentPlayer->HealthMax;
	std::cout << " || MP : " << CurrentPlayer->Mana << "/" << CurrentPlayer->ManaMax << std::endl;
}

void Engine::Input()
{
	switch (State)
	{

	}
	
}

Player* Engine::CreateChar()
{
#if _DEBUG
	CurrentPlayer = new Player("Danicron", 1, 0, 15, 10, 1, 1, 1, 1);
#endif
	return CurrentPlayer;
}

Player* Engine::LoadChar()
{
	return CurrentPlayer;
}

void Engine::DeleteChar()
{
}

void Engine::DisplayChar()
{
	std::cout << CurrentPlayer->Name << std::endl;
	std::cout << "Level : " << CurrentPlayer->Level  << std::endl;
	std::cout << "Experience : " << CurrentPlayer->CurrentExp << "/" << CurrentPlayer->TNL << std::endl;
	std::cout << "Health : " << CurrentPlayer->Health << "/" << CurrentPlayer->HealthMax << std::endl;
	std::cout << "Mana : " << CurrentPlayer->Mana << "/" << CurrentPlayer->ManaMax << std::endl;
	std::cout << "Strength : " << CurrentPlayer->Strength << std::endl;
	std::cout << "Endurance : " << CurrentPlayer->Endurance << std::endl;
	std::cout << "Wisdom : " << CurrentPlayer->Wisdom << std::endl;
	std::cout << "Intelligence : " << CurrentPlayer->Intelligence << std::endl;
	std::cout << std::endl;

#if _DEBUG
	std::cout << "BaseDamage : " << CurrentPlayer->BaseDamage << std::endl;
	std::cout << "BaseDefence : " << CurrentPlayer->BaseDefence << std::endl;
	std::cout << std::endl;
#endif // _DEBUG

}
