#ifndef WALLET_H
#define WALLET_H

#include "stock.h"

class wallet
{
public:
    vector<stock> acoes;
    vector<double> porcentagem;

    wallet();
    ~wallet();

    void insert(stock &acoes, double porcentagem = 0);
    void defineFromReference(wallet *reference);
};

#endif // WALLET_H
