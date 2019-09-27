#include "stock.h"

stock::stock()
{
    //ctor
}

stock::~stock()
{
    //dtor
}

bool stock::read(const char *filename)
{
    ifstream fid(filename, ifstream::in);

    if( !fid.is_open() )
        return true;

    string line;
    double value;
    size_t pos[8];
    int i;

    pos[0] = -1;

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
