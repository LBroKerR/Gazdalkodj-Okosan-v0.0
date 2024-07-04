#include "Account.h"
Account::Account(string name)
{
	this->Bank = nullptr;
	this->kartya = 0;
	setName(name);
	this->hitel = 0;
	this->TrCount = 0;
	setBiztositas(false, false, false);
	setberlet(false);
	setKartya(START, "Start");
}

Account::Account()
{
	this->Bank = nullptr;
	this->kartya = 0;
	setName("Not Defined");
	this->hitel = 0;
	this->TrCount = 0;
	setBiztositas(false, false, false);
	setberlet(false);
	setKartya(START, "Start");
}

Account::~Account()
{
	//Bank struktura
	delete[] this->Bank;
}
string Account::getName()
{
	return this->Name;
}

int Account::getHitel()
{
	return this->hitel;
}

double Account::getKartya()
{
	return this->kartya;
}

bool* Account::getBiztositas()
{
	return this->biztositas;
}

bool Account::getberlet()
{
	return this->berlet;
}

unsigned Account::getTrCount() const
{
	return TrCount;
}

Transaction* Account::getBank()
{
	return this->Bank;
}

void Account::setName(string param)
{
	this->Name = param;
}

void Account::setHitel(int param)
{
	this->hitel += param;
}

void Account::setKartya(double param, string kozlemeny)
{
	this->kartya += param;
	addTranzakcio(param, kozlemeny);
}

void Account::setBiztositas(bool param1, bool param2, bool param3)
{
	this->biztositas[0] = param1;
	this->biztositas[1] = param2;
	this->biztositas[FELHASZNALT_E] = param3;
}

void Account::setberlet(bool param)
{
	this->berlet = param;
}

void Account::addTranzakcio(int iparam, string sparam)
{
	Transaction* tmp = nullptr;
	tmp = new Transaction[getTrCount() + 1];
	tmp[0].setMoney(iparam);
	tmp[0].setComment(sparam);
	if (this->Bank != nullptr)
	{
		for (unsigned i = 1; i < getTrCount() + 1; i++)
		{
			tmp[i] = this->Bank[i-1];
		}
		delete[] this->Bank;
	}
	TrCount++;
	this->Bank = tmp;
}
