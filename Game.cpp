#include "Game.h"

int Game::string_to_num(const string& name)
{
	// Try to find the name in the map
	auto it = num_map.find(name);
	// If found, return the corresponding number
	if (it != num_map.end())
	{
		return it->second;
	}
	// If not found, return -1
	else
	{
		throw invalid_argument("Funcion not founded!");
	}
}

int Game::Input(bool wantNum)
{
	int message = 1;
	cout << "input: ";
	cin >> input;
	if (input == HELP)
	{
		help_print();
		message = Input(wantNum);
	}
	else if (input == END)
	{
		message = 0;
	}
	else if (wantNum)
	{
		message = stoi(input);
	}
	return message;
}
//###########################################################
// új .h, és .cpp -be?
void Game::Hitel(Account* player)//input ->> use try, throw, catch !!!
{
	try
	{
		int num = 1;
		cout << "Hitel torlesztes osszege: ";
		num = Input(true);
		if (num > 0 && num <= 15000)
		{
			player->setKartya(((-1) * num), "Hitel torlesztes");
			player->setHitel(num);
		}
		else if (num < 0)
		{
			player->setHitel((-1)*num);
		}
		else
		{
			cout << "Nem megfelelo a szam. A szam legy ezen a tartomyányon ]0;15000]" << endl;
		}
	}
	catch (invalid_argument& e)
	{
		cout << "Error!" << endl << "Invalid argument!" << endl;
	}
}
void Game::Berlet(Account* player)
{
	if (!player->getberlet())
	{
		player->setberlet(true);
		player->setKartya(-200, "Berlet Vasarlas");
	}
}
void Game::Biztositasok(Account* player)
{
	if (!player->getBiztositas()[0])
	{
		player->setKartya(-350, "Biztoitas vasarlas");
		player->setBiztositas(true, true, false);
	}
	else if (!player->getBiztositas()[FELHASZNALT_E] && player->getBiztositas()[0])
	{
		player->setKartya(5000, "Biztoitas vasarlas");
		player->setBiztositas(true, true, true);
	}
}
void Game::Tranzakciok(Account* player)
{
	for (unsigned i = 0; i < player->getTrCount(); i++)
	{
		player->getBank()[i].print();
	}
}
void Game::Kamat(Account* player)
{
	player->setKartya((player->getKartya() * 0.07), "Kamat");
}
void Game::Bankszamla(Account* player)
{
	try
	{
		cout << "Osszeg hozzadas(+num)/levetel(-num)" << endl;
		int num = Input(true);
		if (num != 0 || num != -1)
		{
			player->setKartya(num, "Bankolas");
		}
	}
	catch (invalid_argument& e)
	{
		cout << "Error!" << endl << "Invalid argument!" << endl;
	}
}
void Game::help_print()
{
	cout << "Parancs szavak:" << endl
		<< "Hitel:			Itt lehet torlesztni" << endl
		<< "Berlet:			Berlehetet lehet venni." << endl
		<< "Bankszamla:		Osszeget lehet hozza adni a szamlahoz" << endl
		<< "Biztositasok:	Biztosítás kotes, es felhasznalas" << endl
		<< "Tranzakciok:	Kiirja az eddig koltsegeket" << endl
		<< "Kamat:			Bankszamla összege kamatozik" << endl
		<< "end:			Kilepes az adott menupontbol" << endl;
}
void Game::accountinfo(Account* player)
{
	cout << "Nev: " << player->getName() << endl
		<< "Hitel: " << player->getHitel() << endl
		<< "Berlet: " << endl;
	if (player->getberlet())
	{
		cout << "	Van" << endl;
	}
	else
	{
		cout << "	Nincs" << endl;
	}
	cout << "Bankszamla: " << player->getKartya() << endl
		<< "Biztositasok: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (i != FELHASZNALT_E)
		{
			if (!player->getBiztositas()[i])
			{
				cout << "	Nincs biztositas " << i + 1 << "." << endl;
			}
			else
			{
				cout << "	Van biztositas " << i + 1 << "." << endl;
			}
		}
		else
		{
			if (player->getBiztositas()[i])
			{
				cout << "A biztositasok fel lettek hasznalva!" << endl;
			}
		}
	}
	cout << "Tranzakciok" << endl << "Kamat" << endl;
}
void Game::account(Account* player)
{
	accountinfo(player);
	while (Input(false) != false)
	{
		try
		{
			(this->*menu_funcs[string_to_num(input)])(player);
		}
		catch (invalid_argument& e)
		{
			cout << "Error!" << endl << e.what() << endl;
		}
		accountinfo(player);
	}
	input = "";
}


//#####################################################################################
bool Game::Exiting()
{
	cout << "Do you want end the game?(yes/no)" << endl;
	Input(false);
	if (input == "yes")
	{
		return false;
	}
	else if (input == "no")
	{
		return true;
	}
	else
	{
		throw invalid_argument("Invalid input!");
	}
	return false;
}

bool Game::menu(Players *players)
{
	bool isend = 1;
	cout << "Menu:" << endl;
	cout << "chose player! " << endl << "from:" << endl;
	players->setCurrent_player(0);
	while (players->getCurrent_player() < players->getMaxPlayer() && players->getplayer()->getName() != "Not Defined")
	{
		cout << players->getplayer()->getName() << endl;
		players->setCurrent_player(players->getCurrent_player() + 1);
	}
	players->setCurrent_player(0);
	isend = (bool)Input(false);
	while (players->getCurrent_player() < players->getMaxPlayer() && players->getplayer()->getName() != "Not Defined")
	{
		if (isend)
		{
			if (players->getplayer()->getName() == input)
			{
				account(players->getplayer());
				break;
			}
		}
		players->setCurrent_player(players->getCurrent_player() + 1);
	}
	if (input == END)
	{
		try
		{
			isend = Exiting();
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
		}
	}
	return isend;
}
void Game::init(Players* players)
{
	do
	{
		cout << "player name:" << endl;
		if (Input(false))
		{
			players->setplayer(input, players->getCurrent_player());
		}
		players->setCurrent_player(players->getCurrent_player() + 1);
	} while (input != END && players->getCurrent_player() < players->getMaxPlayer());
	cout << "Loading..." << endl;

}

Game::Game()
{
	menu_funcs[0] = &Game::Hitel;
	menu_funcs[1] = &Game::Biztositasok;
	menu_funcs[2] = &Game::Berlet;
	menu_funcs[3] = &Game::Tranzakciok;
	menu_funcs[4] = &Game::Kamat;
	menu_funcs[5] = &Game::Bankszamla;
	num_map = {
		{"Hitel", 0},
		{ "Biztositasok", 1 },
		{ "Berlet", 2 },
		{ "Tranzakciok", 3 },
		{ "Kamat", 4 },
		{ "Bankszamla", 5 },
	};
}
Game::~Game()
{

}