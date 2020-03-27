#ifndef DEFINICOES_H
#define DEFINICOES_H

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include "stock.h"
#include "wallet.h"
#include <stdlib.h>

#define FOLDER "/home/sandri/Documents/Serie Historica B3/IBRX/DATA/"
#define SAVE_TSV_FILES "/home/sandri/Documents/Serie Historica B3/IBRX/"
#define REPETICOES 2000
#define TAXA_SELIC 0.064

using namespace std;

void readStocks(wallet &referencia, stock *acoes);
void createRandonWallet(wallet &carteira, stock *acoes, bool *flag, size_t total_number_of_stocks, size_t number_of_stocks);

#endif // DEFINICOES_H
