#include "stock.h"

stock::stock()
{
    //ctor
}

stock::~stock()
{
    //dtor
}

bool stock::read(const char *filename, string name)
{
    ifstream fid(filename, ifstream::in);

    if( !fid.is_open() )
        return true;

    this->name = name;

    string line;
    double value;
    size_t pos[8];
    int i;

    pos[0] = static_cast<size_t>(-1);

    getline (fid,line);

    while( !fid.eof() )
    {
        getline (fid,line);
        if( !line.size() )
            continue;

        for(i=1; i<7; i++)
            pos[i] = line.find(',', pos[i-1]+1);
        pos[7] = line.size();

        value = stod(line.substr(pos[5]+1, pos[6]-pos[5]-1));

        values.insert(values.end(), value);
    }

    fid.close();
    return false;
}

double stock::corr(stock &that)
{
    size_t N = this->values.size();
    if( N>that.values.size() )
        N = that.values.size();

    vector<double>::iterator v1 = this->values.begin() + static_cast<long>(this->values.size()-N);
    vector<double>::iterator v2 = that.values.begin()  + static_cast<long>(that.values.size()-N);
    vector<double>::iterator vend = this->values.end();

    double S12 = 0, S11 = 0, S22 = 0;
    double m1 = 0, m2 = 0;

    while( v1<vend )
    {
        m1 += *(v1++);
        m2 += *(v2++);
    }
    m1 /= N;
    m2 /= N;

    v1 = this->values.begin() + static_cast<long>(this->values.size()-N);
    v2 = that.values.begin()  + static_cast<long>(that.values.size()-N);
    while( v1<vend )
    {
        double d1 = *(v1++)-m1;
        double d2 = *(v2++)-m2;

        S12 += d1*d2;
        S11 += d1*d1;
        S22 += d2*d2;
    }

    return S12/sqrt(S11*S22);
}

double stock::operator*(stock &that)
{
    return this->corr(that);
}
