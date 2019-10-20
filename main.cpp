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

    // Get historical data from file
    acoes[0].read("/home/sandri/Projects/pibic_giovani/BVMF/ABEV3.SA.csv","Ambev");
    acoes[1].read("/home/sandri/Projects/pibic_giovani/BVMF/BBAS3.SA.csv","Banco do Brasil");
    acoes[2].read("/home/sandri/Projects/pibic_giovani/BVMF/MDIA3.SA.csv","M. Dias Branco");

    // Reference wallet
    referencia.insert(acoes[2]);
    referencia.insert(acoes[0]);
    referencia.modernPortfolioTheory(.05);

    cout << endl << "REFERENCIA (Teoria Moderna de Portifolios)" << endl;
    referencia.print();

    // Create carteira
    carteira.insert(acoes[0]);
    carteira.insert(acoes[1]);
    carteira.insert(acoes[2]);

    // Imprime carteira
    cout << endl << "CARTEIRA (baseada na referencia definida pela Teoria Moderna de Portifolios)" << endl;
    carteira.fromReference(&referencia);
    carteira.print();

    cout << endl << "CARTEIRA (baseada na referencia definida pelo metodo naive)" << endl;
    referencia.naive();
    carteira.fromReference(&referencia);
    carteira.print();

    cout << endl << "CARTEIRA (Teoria Moderna de Portifolios)" << endl;
    carteira.modernPortfolioTheory(.05);
    carteira.print();

    cout << endl << "CARTEIRA (baseada em si mesma)" << endl;
    if( carteira.itselfIterative() )
        cout << "Nao consegui determinar carteira pelo metodo itselfIterative" << endl;
    else
        carteira.print();

    cout << endl << "CARTEIRA (definida por Huffman)" << endl;
    carteira.huffman();
    carteira.print();

    cout << endl << "CARTEIRA (baseada em si mesma definida por Huffman)" << endl;
    carteira.fromReference(&carteira);
    carteira.print();

    delete [] acoes;
}
