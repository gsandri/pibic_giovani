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

    stock();
    virtual ~stock();
    bool read(const char* filename);
    double corr(stock &that);
    double operator*(stock &that);

protected:

private:
};

#endif // STOCK_H
