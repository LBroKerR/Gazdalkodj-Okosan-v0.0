#include "Transaction.h"

int Transaction::getMoney()
{
    return this->money;
}

string Transaction::getComment()
{
    return this->comment;
}

Transaction::Transaction()
{
    setMoney(0);
    setComment("Not defined");
}

Transaction::Transaction(int moneyparam, string commentparam)
{
    setMoney(moneyparam);
    setComment(commentparam);
}

Transaction::~Transaction()
{
    //?
}

void Transaction::setMoney(int param)
{
    this->money = param;
}

void Transaction::setComment(string param)
{
    this->comment = param;
}

void Transaction::print()
{
    cout << "Money:   " << getMoney() << endl
        << "Comment: " << getComment() << endl;
}
