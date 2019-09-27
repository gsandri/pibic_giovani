#ifndef STOCK_H
#define STOCK_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class stock
{
    public:
        vector<double> values;

        stock();
        virtual ~stock();
        bool read(string filename);

    protected:

    private:
};

#endif // STOCK_H
