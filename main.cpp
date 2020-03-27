#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include "stock.h"
#include "wallet.h"
#include <stdlib.h>
#include "definicoes.h"

using namespace std;

int main()
{
    wallet referencia, carteira;
    stock *acoes = new stock[78];
    double gain, variance;
    bool *flag = new bool[78];
    ofstream fid(SAVE_TSV_FILES "Compilados_PIBIC_Giovani.tsv", ofstream::out | ofstream::binary | ofstream::trunc);

    fid << "Numero de acoes na carteira\tMetodo\tGanho\tVariancia\n";

    cout << "Lendo acoes" << endl;
    readStocks(referencia, acoes);

    cout << "Aplicando a Teoria Moderda dos Portifolios na referencia" << endl;
    referencia.modernPortfolioTheory();

    size_t rep;
    vector<size_t> number_of_stocks = {30,20,15,10,7,5,4,3,2};
    vector<size_t>::iterator number, number_end = number_of_stocks.end();

    cout << "Compilando dados" << endl;
    for(number = number_of_stocks.begin(); number<number_end; number++)
    {
        cout << "  " << *number << " acoes na carteira" << endl;
        for(rep = 0; rep<REPETICOES; rep++)
        {
            createRandonWallet(carteira, acoes, flag, 78, *number);

            carteira.naive();
            carteira.gain_in_evaluate_interval(gain, variance);
            fid << *number << "\t0\t" << gain << "\t" << variance << endl;

            carteira.fromReference(&referencia);
            carteira.gain_in_evaluate_interval(gain, variance);
            fid << *number << "\t1\t" << gain << "\t" << variance << endl;

            carteira.modernPortfolioTheory(TAXA_SELIC);
            carteira.gain_in_evaluate_interval(gain, variance);
            fid << *number << "\t2\t" << gain << "\t" << variance << endl;
        }
    }

    fid.close();
    delete [] acoes;
    delete [] flag;
}
