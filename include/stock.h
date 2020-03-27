#ifndef STOCK_H
#define STOCK_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>

#define YEAR_START  2000
#define YEAR_MIDDLE 2019
#define YEAR_END    2020
#define YEAR_NUMEL  ((YEAR_END-YEAR_START)*12)
#define YEAR_NEVAL  ((YEAR_END-YEAR_MIDDLE)*12)

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
    double variance_in_evaluate_interval(stock &that);
    double operator^(stock &that);

    // Compute anual gain in value, desconsidering the evaluate interval
    // from YEAR_START to YEAR_MIDDLE
    double gain();

    // Compute anual gain in value
    // from YEAR_MIDDLE to YEAR_END
    double gain_in_evaluate_interval();

protected:

private:
};

#endif // STOCK_H
