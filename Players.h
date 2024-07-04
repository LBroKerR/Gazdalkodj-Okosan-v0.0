#pragma once
#ifndef  PLAYERS_H

#define PLAYERS_H

	#include"Account.h"
	class Players
	{
		Account* player;
		unsigned current_player;
		unsigned MaxPlayer;

		void setMaxPlayer(unsigned);
	public:

		unsigned getMaxPlayer();

		void setCurrent_player(unsigned);
		unsigned getCurrent_player();

		Account *getplayer();
		bool setplayer(string, unsigned);

		Players();
		Players(unsigned);
		~Players();
		// gamevalue place to define!
	};

#endif // ! GAME_H
