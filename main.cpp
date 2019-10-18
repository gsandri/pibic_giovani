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
    stock BBAS3, MMM, TIET11;

    BBAS3.read("./pibic_giovani/BVMF/BBAS3.SA.csv", "Banco do Brasil");
    MMM.read("./pibic_giovani/BVMF/MMM.csv", "3M");
    TIET11.read("./pibic_giovani/BVMF/ABEV3.SA.csv", "Ambev");

    referencia.insert(BBAS3, 0.5);
    referencia.insert(MMM, 0.5);

    carteira.insert(BBAS3);
    carteira.insert(MMM);
    carteira.insert(TIET11);

    carteira.defineFromReference(&referencia);

    for(size_t i=0; i<carteira.acoes.size(); i++)
    {
        cout << carteira.acoes[i].name << endl;
        cout << "\t" << carteira.porcentagem[i] << endl;
    }
}
