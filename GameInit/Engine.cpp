#include "Engine.h"

Engine::Engine()
{
	this->GameName = "IHaveNoIdeaYetButSoon";
	this->Playing = false;
	this->State = 0;
	CheckRoot();
	CheckRoot();

	PopulateSaves();
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

void Engine::PopulateSaves()
{
	for (auto const& dir_entry : std::filesystem::directory_iterator(players))
	{
		Players.push_back(dir_entry);
	}

}

void Engine::Login()
{
	int choice = 0;
	
	Output("Welcome to " + GameName + "...");
	Output("What would you like to do? (enter a number)");
	Output("");

	Output("1. Create Character ");
	Output("2. Load Character ");;
	Output("3. Delete Character ");
	Output("4. Help ");
	Output("5. Quit ");
	Output("");

	std::cin >> choice;
	Output("");

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
	Output("Level : " + std::to_string(CurrentPlayer->Level) + " || Exp : " + std::to_string(CurrentPlayer->CurrentExp) + "/" + std::to_string(CurrentPlayer->TNL), false);
	Output(" || HP : " + std::to_string(CurrentPlayer->Health) + "/" + std::to_string(CurrentPlayer->HealthMax), false);
	Output(" || MP : " + std::to_string(CurrentPlayer->Mana) + "/" + std::to_string(CurrentPlayer->ManaMax));
	Output("");
	Output("");

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
			Output("4. Save");
			Output("5. Quit to Main Menu"); 
			Output("");

			std::cin >> choice;
			Output("");
			
			break;
		}
	}
	Input(choice);

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
				SaveChar();
				break;
			}
			case 5:
			{
				State = 0;
				CurrentPlayer = nullptr;
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

void Engine::CheckRoot()
{
	if (!std::filesystem::is_directory(root))
	{
		std::filesystem::create_directory(root);

		if (!std::filesystem::is_directory(players))
		{

			std::filesystem::create_directory(players);
		}
	}

}

Player* Engine::CreateChar()
{
#if _DEBUG
	CurrentPlayer = new Player("Danicron", 1, 0, 15, 10, 1, 1, 1, 1, 0, 0);
	ppath = "Game/Players/" + CurrentPlayer->Name;
#endif
	return CurrentPlayer;
}

Player* Engine::LoadChar()
{
	Output("Character List : ");
	Output("");

	std::string n;

	for (auto const& player : Players)
	{
		Output(player.path().filename().string());
	}

	Output("");

	Output("Enter name of Character to load save");

	std::cin >> n;

	if (std::filesystem::is_directory(n))
	{
		Output("Player found");
		return CurrentPlayer;
	}
	
}

void Engine::SaveChar()
{
	try
	{
		nlohmann::json j = *CurrentPlayer;

		std::filesystem::current_path(players);

		if (!std::filesystem::is_directory(CurrentPlayer->Name))
		{
			std::filesystem::create_directory(CurrentPlayer->Name);
			Output("Character Directory Created!");
			
		}

		std::ofstream ofs(CurrentPlayer->Name + ".json");

		if (ofs.is_open())
		{
			if (!j.empty())
			{
				ofs << j.dump();
				ofs.close();
				Output("Character Saved!");
			}
			else
			{
				Output("Json string empty :(");
				ofs.close();
			}
		}

	}
	catch (nlohmann::json::exception e)
	{
		Output(e.what());
	}

}

void Engine::DeleteChar()
{
}

void Engine::Move()
{
	Output("");
	std::string mv = "";

	std::cin >> mv;
	
	if (mv == "n" || mv == "north")
	{
		if (CurrentRoom->Exits[0] != 0)
		{
			CurrentPlayer->Loc.second = CurrentRoom->Exits[0];
		}
		else
		{
			Output("There is no exit North");
		}
	}
	else if (mv == "e" || mv == "east")
	{
		if (CurrentRoom->Exits[1] != 0)
		{
			CurrentPlayer->Loc.second = CurrentRoom->Exits[1];
		}
		else
		{
			Output("There is no exit East");
		}
	}
	else if (mv == "s" || mv == "south")
	{
		if (CurrentRoom->Exits[2] != 0)
		{
			CurrentPlayer->Loc.second = CurrentRoom->Exits[2];
		}
		else
		{
			Output("There is no exit South");
		}
	}
	else if (mv == "w" || mv == "west")
	{
		if (CurrentRoom->Exits[3] != 0)
		{
			CurrentPlayer->Loc.second = CurrentRoom->Exits[3];
		}
		else
		{
			Output("There is no exit West");
		}
	}
	else if (mv == "u" || mv == "up")
	{
		if (CurrentRoom->Exits[4] != 0)
		{
			CurrentPlayer->Loc.second = CurrentRoom->Exits[4];
		}
		else
		{
			Output("There is no exit Up");
		}
	}
	else if (mv == "d" || mv == "down")
	{
		if (CurrentRoom->Exits[5] != 0)
		{
			CurrentPlayer->Loc.second = CurrentRoom->Exits[5];
		}
		else
		{
			Output("There is no exit Down");
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
	Output("");
	Output("");
}

void Engine::DisplayRoom()
{
	if (CurrentRoom != GetCurrentRoom())
	{
		CurrentRoom = GetCurrentRoom();
	}

	Output("");
	Output(CurrentRoom->desc);

	Output("Exits : ", false);
	if (CurrentRoom->Exits[0] != 0)
	{
		Output("North ,", false);
	}
	if (CurrentRoom->Exits[1] != 0)
	{
		Output("East ,", false);
	}
	if (CurrentRoom->Exits[2] != 0)
	{
		Output("South ,", false);
	}
	if (CurrentRoom->Exits[3] != 0)
	{
		Output("West ,", false);
	}
	if (CurrentRoom->Exits[4] != 0)
	{
		Output("Up ,", false);
	}
	if (CurrentRoom->Exits[5] != 0)
	{
		Output("Down", false);
	}
	Output("");
	Output("");
}

void Engine::DisplayChar()
{
	Output(CurrentPlayer->Name);
	Output("Level : " + std::to_string(CurrentPlayer->Level));
	Output("Experience : " + std::to_string(CurrentPlayer->CurrentExp) + "/" + std::to_string(CurrentPlayer->TNL));
	Output("Health : " + std::to_string(CurrentPlayer->Health) + "/" + std::to_string(CurrentPlayer->HealthMax));
	Output("Mana : " + std::to_string(CurrentPlayer->Mana) + "/" + std::to_string(CurrentPlayer->ManaMax));
	Output("Strength : " + std::to_string(CurrentPlayer->Strength));
	Output("Endurance : " + std::to_string(CurrentPlayer->Endurance));
	Output("Wisdom : " + std::to_string(CurrentPlayer->Wisdom));
	Output("Intelligence : " + std::to_string(CurrentPlayer->Intelligence));
	Output("\n");

#if _DEBUG
	Output("BaseDamage : " + std::to_string(CurrentPlayer->BaseDamage));
	Output("BaseDefence : " + std::to_string(CurrentPlayer->BaseDefence));
	Output("\n");
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
					Output("Weapon  |" + std::to_string(w->DamageType) + " ¦ " + std::to_string(w->BaseDamage));
				}
			}
		}
	}
	else
	{
		Output("Inventory is empty");
	}
}

Room* Engine::GetCurrentRoom()
{
	if (CurrentPlayer->Loc.second > 0)
		return &CurrentWorld->GetCurrentArea()->Rooms[CurrentPlayer->Loc.second - 1];
	else
		return &CurrentWorld->GetCurrentArea()->Rooms[CurrentPlayer->Loc.second];
}
