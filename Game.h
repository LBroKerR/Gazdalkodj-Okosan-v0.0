#pragma once
#ifndef GAME_H

#define GAME_H

#include <stdexcept>
#include <unordered_map>
#include <malloc.h>
#include <string>
#include<iostream>

#include "Players.h"

#define END  "end"
#define HELP "help"
#define MAX_FUNCS 6

using namespace std;
class Game: public Players
{
	string input;
	unordered_map<string, int> num_map;
	void (Game::*menu_funcs[MAX_FUNCS])(Account*);

	int string_to_num(const string& name);
	bool Exiting();
	int Input(bool wantNum);
	void accountinfo(Account* player);
	void Hitel(Account* player);
	void Berlet(Account* player);
	void Biztositasok(Account* player);
	void Tranzakciok(Account* player);
	void Kamat(Account* player);
	void Bankszamla(Account* player);
	void help_print();
	void account(Account* player);


public:

	Game();
	~Game();
	bool menu(Players*);
	void init(Players*);
};

#endif // !GAME_H