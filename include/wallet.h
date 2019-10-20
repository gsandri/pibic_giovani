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

    // Insert new stock to wallet
    void insert(stock &acoes, double porcentagem = 0);

    /* Determine wallet stock distribution based on reference wallet
     * The weights of each stock is determined by its correlation with
     * the stocks in the reference
     */
    void fromReference(wallet *reference);

    /* Determine wallet stock distribution using the Modern Portifolio
     * Theory, which tries to maximize the Sharpe Ratio
     *
     * r0 is the risk free annual gain
     */
    void modernPortfolioTheory(double r0=0);

    /* Determine wallet stock distribution using the naive approach where
     * stocks are equally distributed
     */
    void naive();

    /* Determine wallet stock distribution using the naive approach where
     * stocks are equally distributed
     */
    bool itselfIterative();

    void huffman();

    void print();
};

#endif // WALLET_H
