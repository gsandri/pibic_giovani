#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include "stock.h"
#include "wallet.h"

using namespace std;

int main()
{
    wallet referencia, carteira;
    stock *acoes = new stock[3];

    acoes[0].read("/home/sandri/Projects/pibic_giovani/BVMF/ABEV3.SA.csv","Ambev");
    acoes[1].read("/home/sandri/Projects/pibic_giovani/BVMF/BBAS3.SA.csv","Banco do Brasil");
    acoes[2].read("/home/sandri/Projects/pibic_giovani/BVMF/MDIA3.SA.csv","M. Dias Branco");

    referencia.insert(acoes[2]);
    referencia.insert(acoes[0]);
    referencia.modernPortfolioTheory();

    cout << endl << "REFERENCIA (Definido pela Teoria Moderna de Portifolios)" << endl;
    for(size_t i=0; i<referencia.acoes.size(); i++)
        cout << "  " << referencia.porcentagem[i] << '\t' << referencia.acoes[i]->name << endl;
    cout << endl;

    carteira.insert(acoes[0]);
    carteira.insert(acoes[1]);
    carteira.insert(acoes[2]);

    carteira.fromReference(&referencia);

    cout << endl << "CARTEIRA" << endl;
    for(size_t i=0; i<carteira.acoes.size(); i++)
        cout << "  " << carteira.porcentagem[i] << '\t' << carteira.acoes[i]->name << endl;
    cout << endl;

    delete [] acoes;
}
