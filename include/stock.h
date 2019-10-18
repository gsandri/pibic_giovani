#ifndef STOCK_H
#define STOCK_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

class stock
{
public:
    vector<double> values;
    string name;

    stock();
    virtual ~stock();
    bool read(const char* filename, string name);
    double corr(stock &that);
    double variance(stock &that);
    double operator*(stock &that);
    double operator^(stock &that);
    double gain();

protected:

private:
};

#endif // STOCK_H
