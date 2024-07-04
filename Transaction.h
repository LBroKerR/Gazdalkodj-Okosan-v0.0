#pragma once
#ifndef  TRANSACTION_H

#define TRANSACTION_H
#include<iostream>
using namespace std;
class Transaction
{
	int money;
	string comment;

	int getMoney();
	string getComment();

public:
	Transaction();
	Transaction(int, string);
	~Transaction();

	void setMoney(int);
	void setComment(string);

	void print();
	
};

#endif
