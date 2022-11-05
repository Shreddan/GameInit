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

	Sleep(400);
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
			CurrentWorld = new World("CantThinkOfOneRightNowButSoon");
			CurrentPlayer = CreateChar();
			DisplayChar();
			State = 1;
			break;
		}
		case 2:
		{
			CurrentPlayer = LoadChar();
			State = 1;
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
			Playing = false;
			break;
		}
	}
}

void Engine::Prompt()
{
	int choice = 0;
	std::cout << "Level : " << CurrentPlayer->Level << " || Exp : " << CurrentPlayer->CurrentExp << "/" << CurrentPlayer->TNL;
	std::cout << " || HP : " << CurrentPlayer->Health << "/" << CurrentPlayer->HealthMax;
	std::cout << " || MP : " << CurrentPlayer->Mana << "/" << CurrentPlayer->ManaMax << std::endl;
	std::cout << std::endl;

	switch (State)
	{
		case 1:
		{
			DisplayRoom();
			Move();
			break;
		}
		case 2:
		{
			std::cout << "1. Character Screen" << std::endl;
			std::cout << "2. Inventory" << std::endl;
			std::cout << "3. Skill Screen" << std::endl;
			std::cout << "4. Quit to Main Menu" << std::endl;
			std::cout << std::endl;

			std::cin >> choice;
			std::cout << std::endl;
			
			break;
		}
	}
	Input(choice);
	Sleep(400);

}

void Engine::Input(int c)
{
	
	switch (State)
	{
		case 1:
		{
			
			break;
		}
		case 2:
		{
			switch (c)
			{
			case 1:
			{
				DisplayChar();

				break;
			}
			case 2:
			{
				break;
			}
			case 3:
			{
				break;
			}
			case 4:
			{
				State = 0;
				CurrentPlayer = nullptr;
				Sleep(500);
				Login();
			}
			}
			break;
		}
	}
	
}

Player* Engine::CreateChar()
{
#if _DEBUG
	CurrentPlayer = new Player("Danicron", 1, 0, 15, 10, 1, 1, 1, 1, 0);
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

void Engine::Move()
{
	std::string mv;

	std::cin >> mv;
	
	if (mv == "n" || mv == "north")
	{
		if (GetCurrentRoom()->Exits[0] != 0)
		{
			CurrentPlayer->Location = GetCurrentRoom()->Exits[0];
		}
		else
		{
			std::cout << "There is no exit North" << std::endl;
		}
	}
	else if (mv == "e" || mv == "east")
	{
		if (GetCurrentRoom()->Exits[1] != 0)
		{
			CurrentPlayer->Location = GetCurrentRoom()->Exits[1];
		}
		else
		{
			std::cout << "There is no exit East" << std::endl;
		}
	}
	else if (mv == "s" || mv == "south")
	{
		if (GetCurrentRoom()->Exits[2] != 0)
		{
			CurrentPlayer->Location = GetCurrentRoom()->Exits[2];
		}
		else
		{
			std::cout << "There is no exit South" << std::endl;
		}
	}
	else if (mv == "w" || mv == "west")
	{
		if (GetCurrentRoom()->Exits[3] != 0)
		{
			CurrentPlayer->Location = GetCurrentRoom()->Exits[3];
		}
		else
		{
			std::cout << "There is no exit West" << std::endl;
		}
	}
	else if (mv == "u" || mv == "up")
	{
		if (GetCurrentRoom()->Exits[4] != 0)
		{
			CurrentPlayer->Location = GetCurrentRoom()->Exits[4];
		}
		else
		{
			std::cout << "There is no exit Up" << std::endl;
		}
	}
	else if (mv == "d" || mv == "down")
	{
		if (GetCurrentRoom()->Exits[5] != 0)
		{
			CurrentPlayer->Location = GetCurrentRoom()->Exits[5];
		}
		else
		{
			std::cout << "There is no exit Down" << std::endl;
		}
	}

}

void Engine::DisplayRoom()
{
	CurrentRoom = GetCurrentRoom();

	std::cout << std::endl;
	std::cout << CurrentRoom->desc << std::endl;

	std::cout << "Exits : ";
	if (CurrentRoom->Exits[0] != 0)
	{
		std::cout << "North ,";
	}
	if (CurrentRoom->Exits[1] != 0)
	{
		std::cout << "East ,";
	}
	if (CurrentRoom->Exits[2] != 0)
	{
		std::cout << "South ,";
	}
	if (CurrentRoom->Exits[3] != 0)
	{
		std::cout << "West ,";
	}
	if (CurrentRoom->Exits[4] != 0)
	{
		std::cout << "Up ,";
	}
	if (CurrentRoom->Exits[5] != 0)
	{
		std::cout << "Down";
	}
	std::cout << std::endl;
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

Room* Engine::GetCurrentRoom()
{
	return &CurrentWorld->CurrentArea->Rooms[CurrentPlayer->Location];
}
