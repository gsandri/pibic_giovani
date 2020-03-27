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
    {
        cout << "Unable to open: " << filename << endl;
        return true;
    }

    this->name = name;

    uint32_t premed[YEAR_NUMEL];

    fid.read(reinterpret_cast<char *>(premed), sizeof(uint32_t)*YEAR_NUMEL);
    fid.close();

    int i = 0;
    while( i<YEAR_NUMEL && !premed[i] )
        i++;
    while( i<YEAR_NUMEL )
        values.push_back(static_cast<double>(premed[i++])/100.0);

    return false;

    /*
    ifstream fid(filename, ifstream::in);

    if( !fid.is_open() )
    {
        cout << "Unable to open: " << filename << endl;
        return true;
    }

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

        values.push_back(value);
    }

    fid.close();
    return false;
    */
}

double stock::corr(stock &that)
{
    size_t N = this->values.size();
    if( N>that.values.size() )
        N = that.values.size();

    if( N<2 )
        return 0;

    vector<double>::iterator v1 = this->values.begin() + static_cast<long>(this->values.size()-N);
    vector<double>::iterator v2 = that.values.begin()  + static_cast<long>(that.values.size()-N);
    vector<double>::iterator vend = this->values.end() - YEAR_NEVAL;

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

double stock::variance(stock &that)
{
    size_t N = this->values.size();
    if( N>that.values.size() )
        N = that.values.size();

    vector<double>::iterator v1 = this->values.begin() + static_cast<long>(this->values.size()-N);
    vector<double>::iterator v2 = that.values.begin()  + static_cast<long>(that.values.size()-N);
    vector<double>::iterator vend = this->values.end() - YEAR_NEVAL;

    double S12 = 0;
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
        double d1 = *(v1++)/m1-1;
        double d2 = *(v2++)/m2-1;

        S12 += d1*d2;
    }

    return S12/(N-1);
}

double stock::variance_in_evaluate_interval(stock &that)
{
    size_t N = this->values.size();
    if( N>that.values.size() )
        N = that.values.size();

    vector<double>::iterator v1 = this->values.end() - YEAR_NEVAL;
    vector<double>::iterator v2 = that.values.end()  - YEAR_NEVAL;
    vector<double>::iterator vend = this->values.end();

    if( N<YEAR_NEVAL )
    {
        v1 += YEAR_NEVAL-N;
        v2 += YEAR_NEVAL-N;
    }

    double S12 = 0;
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
        double d1 = *(v1++)/m1-1;
        double d2 = *(v2++)/m2-1;

        S12 += d1*d2;
    }

    return S12/(N-1);
}

double stock::operator*(stock &that)
{
    return this->corr(that);
}

double stock::operator^(stock &that)
{
    return this->variance(that);
}

double stock::gain()
{
    double S0 = this->values.size() - YEAR_NEVAL;
    double S1 = S0*(S0-1)/2;
    double S2 = S0*(S0-1)*(2*S0-1)/6;
    double SY = 0;
    double SYI = 0;

    size_t n = this->values.size() - YEAR_NEVAL;
    while( n-- )
    {
        double ln = log(this->values[n]);
        SY += ln;
        SYI += ln*n;
    }

    return exp( 12*(S0*SYI-S1*SY)/(S0*S2-S1*S1) ) - 1;
}

double stock::gain_in_evaluate_interval()
{
    size_t n = this->values.size();
    if( n>YEAR_NEVAL )
        n = YEAR_NEVAL;

    double S0 = n;
    double S1 = S0*(S0-1)/2;
    double S2 = S0*(S0-1)*(2*S0-1)/6;
    double SY = 0;
    double SYI = 0;


    vector<double>::iterator v1 = this->values.end();
    while( n-- )
    {
        v1--;
        double ln = log(*v1);
        SY += ln;
        SYI += ln*n;
    }

    return exp( 12*(S0*SYI-S1*SY)/(S0*S2-S1*S1) ) - 1;
}
