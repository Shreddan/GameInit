#include "Engine.h"

Engine::Engine()
{
	this->GameName = "IHaveNoIdeaYetButSoon";
	this->Playing = false;
	this->State = 0;
}

Engine::~Engine()
{
	delete CurrentPlayer;
	delete CurrentWorld;
	delete CurrentRoom;
}

void Engine::LoadAll()
{
	//LoadWeapons();
	//LoadArmour();
}

void Engine::LoadWeapons()
{

}

void Engine::LoadArmour()
{
}

void Engine::Login()
{
	int choice = 0;
	
	Output("Welcome to " + GameName + "...");
	Output("What would you like to do? (enter a number)");
	Output("\n");

	Output("1. Create Character ");
	Output("2. Load Character ");;
	Output("3. Delete Character ");
	Output("4. Help ");
	Output("5. Quit ");
	Output("\n");

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
		Output(Breakup);
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
	Output(" Level : " + std::to_string(CurrentPlayer->Level), false);
	Output(" || Exp : " + std::to_string(CurrentPlayer->CurrentExp), false);
	Output("/" + std::to_string(CurrentPlayer->TNL), false);
	Output(" || HP : " + std::to_string(CurrentPlayer->Health), false);
	Output("/" + std::to_string(CurrentPlayer->HealthMax), false);
	Output(" || MP : " + std::to_string(CurrentPlayer->Mana), false);
	Output("/" + std::to_string(CurrentPlayer->ManaMax));
	Output("\n");
	Output("\n");

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
			Output("1. Character Screen");
			Output("2. Inventory");
			Output("3. Skill Screen");
			Output("4. Quit to Main Menu"); 
			Output("\n");

			std::cin >> choice;
			Output("\n");
			
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

void Engine::Output(std::string s, bool newline)
{ 
	if (newline)
	{
		std::cout << s << std::endl;
	}
	else
	{
		std::cout << s;
	}
	return;
}

Player* Engine::CreateChar()
{
#if _DEBUG
	CurrentPlayer = new Player("Danicron", 1, 0, 15, 10, 1, 1, 1, 1, 1);
#endif
	return CurrentPlayer;
}

Player* Engine::LoadChar()
{
	return CurrentPlayer;
}

void Engine::SaveChar()
{
	
}

void Engine::DeleteChar()
{
}

void Engine::Move()
{
	std::cout << std::endl;
	std::string mv = "";

	std::cin >> mv;
	
	if (mv == "n" || mv == "north")
	{
		if (CurrentRoom->Exits[0] != 0)
		{
			CurrentPlayer->Loc = CurrentRoom->Exits[0];
		}
		else
		{
			std::cout << "There is no exit North" << std::endl;
		}
	}
	else if (mv == "e" || mv == "east")
	{
		if (CurrentRoom->Exits[1] != 0)
		{
			CurrentPlayer->Loc = CurrentRoom->Exits[1];
		}
		else
		{
			std::cout << "There is no exit East" << std::endl;
		}
	}
	else if (mv == "s" || mv == "south")
	{
		if (CurrentRoom->Exits[2] != 0)
		{
			CurrentPlayer->Loc = CurrentRoom->Exits[2];
		}
		else
		{
			std::cout << "There is no exit South" << std::endl;
		}
	}
	else if (mv == "w" || mv == "west")
	{
		if (CurrentRoom->Exits[3] != 0)
		{
			CurrentPlayer->Loc = CurrentRoom->Exits[3];
		}
		else
		{
			std::cout << "There is no exit West" << std::endl;
		}
	}
	else if (mv == "u" || mv == "up")
	{
		if (CurrentRoom->Exits[4] != 0)
		{
			CurrentPlayer->Loc = CurrentRoom->Exits[4];
		}
		else
		{
			std::cout << "There is no exit Up" << std::endl;
		}
	}
	else if (mv == "d" || mv == "down")
	{
		if (CurrentRoom->Exits[5] != 0)
		{
			CurrentPlayer->Loc = CurrentRoom->Exits[5];
		}
		else
		{
			std::cout << "There is no exit Down" << std::endl;
		}
	}
	else if (mv == "c")
	{
		State = 2;
	}
	else
	{
		return;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void Engine::DisplayRoom()
{
	if (CurrentRoom != GetCurrentRoom())
	{
		CurrentRoom = GetCurrentRoom();
	}

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

void Engine::DisplayInv()
{
	if (CurrentPlayer->Inventory.size() != 0)
	{
		for (size_t i = 0; i < CurrentPlayer->Inventory.size(); i++)
		{
			if (CurrentPlayer->Inventory[i]->GetType() == 0)
			{
				Weapon* w = dynamic_cast<Weapon*>(CurrentPlayer->Inventory[i]);
				if (w != nullptr)
				{
					std::cout << "Weapon  |" << w->GetDamageType() << " ¦ " << w->GetBaseDamage() << std::endl;
				}
			}
		}
	}
	else
	{
		std::cout << "Inventory is empty" << std::endl;
	}
}

Room* Engine::GetCurrentRoom()
{
	return &CurrentWorld->GetCurrentArea()->Rooms[CurrentPlayer->Loc - 1];
}
