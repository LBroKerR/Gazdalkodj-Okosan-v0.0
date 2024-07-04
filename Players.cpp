//TO DO
//Game ending


#include "Players.h"

void Players::setMaxPlayer(unsigned param)
{
	this->MaxPlayer = param;
}

unsigned Players::getMaxPlayer()
{
	return this->MaxPlayer;
}

void Players::setCurrent_player(unsigned param)
{
	this->current_player = param;
}

unsigned Players::getCurrent_player()
{
	return this->current_player;
}

Account* Players::getplayer()
{
	return &player[getCurrent_player()];
}

bool Players::setplayer(string name, unsigned elem)
{
	if (elem >= getMaxPlayer())
	{
		return false;
	}
	this->player[elem].setName(name);
	return true;
}

Players::Players()
{
}

Players::Players(unsigned max)
{
	this->player = new Account[max];
	setMaxPlayer(max);
	setCurrent_player(0);

}

Players::~Players()
{
	delete[] this->player;
}
