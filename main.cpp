#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include "stock.h"

using namespace std;

int main()
{
    stock BBAS3, MMM;

    BBAS3.read("/home/sandri/Downloads/BBAS3.SA.csv");
    MMM.read("/home/sandri/Downloads/MMM.csv");

    cout << "BBAS3 x BBAS3: " << BBAS3 * BBAS3 << endl;
    cout << "BBAS3 x  MMM : " << BBAS3 *  MMM  << endl;
    cout << " MMM  x BBAS3: " <<  MMM  * BBAS3 << endl;
    cout << " MMM  x  MMM : " <<  MMM  *  MMM  << endl;
}
