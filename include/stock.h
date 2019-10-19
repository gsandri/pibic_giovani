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
    vector<double> values;  // Historical data. Stored from oldest data to newest
    string name;

    stock();
    virtual ~stock();

    /* Get historical data from file
     *
     * filename: Path to CSV file containing the historical data download from Yahoo Fincances
     * name:     Stock name
     */
    bool read(const char* filename, string name);

    // Compute correlation between two stocks
    double corr(stock &that);
    double operator*(stock &that);

    // Compute variance between two stocks (stocks are normalized to have an average of 1)
    double variance(stock &that);
    double operator^(stock &that);

    // Compute anual gain in value
    double gain();

protected:

private:
};

#endif // STOCK_H
