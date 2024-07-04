#pragma once
#ifndef ACCOUNT_H

#define ACCOUNT_H

#include<iostream>
using namespace std;
#include "Transaction.h"
#define START 0
#define SIZE 3
#define FELHASZNALT_E 2
class Account
{
	string Name;
	int hitel;
	bool biztositas[3];
	bool berlet;
	double kartya;
	unsigned TrCount;
	Transaction* Bank;

	void addTranzakcio(int, string);

public:
	Account(string);
	Account();
	~Account();
	string getName();

	int getHitel();
	double getKartya();

	bool* getBiztositas();
	bool getberlet();
	unsigned getTrCount()const;

	Transaction* getBank();

	void setName(string);

	void setHitel(int);
	void setKartya(double, string);

	void setBiztositas(bool, bool, bool);
	void setberlet(bool);
};

#endif // !ACCOUNT_H