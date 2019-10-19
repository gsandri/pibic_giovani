#ifndef WALLET_H
#define WALLET_H

#include "stock.h"

class wallet
{
public:
    vector<stock *> acoes;
    vector<double> porcentagem;

    wallet() {}
    ~wallet();

    void insert(stock &acoes, double porcentagem = 0);
    void fromReference(wallet *reference);
    void modernPortfolioTheory(double r0=0);
    void naive();
};

#endif // WALLET_H
