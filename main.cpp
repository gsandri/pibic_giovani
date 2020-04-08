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
#include <chrono>
#include <unistd.h>

using namespace std::chrono;
using namespace std;

int main()
{
    wallet referencia, carteira;
    stock *acoes = new stock[78];

    cout << "Lendo acoes" << endl;
    readStocks(referencia, acoes);

    cout << "Aplicando a Teoria Moderda dos Portifolios na referencia" << endl;
    referencia.modernPortfolioTheory(TAXA_SELIC);
    referencia.print();

    delete [] acoes;
    return 0;
}

int main2()
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
    referencia.modernPortfolioTheory(TAXA_SELIC);
    referencia.print();

    size_t rep;
    vector<size_t> number_of_stocks = {2,3,4,5,7,10,15,20,30,45};
    vector<size_t>::iterator number, number_end = number_of_stocks.end();

    cout << "Compilando dados" << endl;
    auto start = high_resolution_clock::now();
    double tmp = 1.25;
    sleep(1);
    for(number = number_of_stocks.begin(); number<number_end; number++)
    {
        cout << "  " << *number << " acoes na carteira" << endl;
        for(rep = 1; rep<=REPETICOES; rep++)
        {
            if( !(rep%(REPETICOES/20)) )
            {
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                start = stop;

                if( (rep*20)==REPETICOES )
                    tmp = static_cast<double>(duration.count())/1000000;
                else
                    tmp = 0.9*tmp + 0.1*static_cast<double>(duration.count())/1000000;

                cout << "    [" << (REPETICOES-rep)/(REPETICOES/20) << "] (" << tmp-1 << ") " << tmp*(REPETICOES-rep)/(REPETICOES/20) << endl;
                sleep(1);
            }

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
        cout << endl;
    }

    fid.close();
    delete [] acoes;
    delete [] flag;
}
