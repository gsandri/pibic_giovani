#include "wallet.h"

wallet::~wallet()
{
    this->acoes.clear();
    this->porcentagem.clear();
}

void wallet::insert(stock &acao, double porcentagem)
{
    this->acoes.push_back(&acao);
    this->porcentagem.push_back(porcentagem);
}

void wallet::fromReference(wallet *reference)
{
    size_t ind_ref, ind_car;
    double *corr = new double[this->acoes.size()];
    double corr_sum;
    double *w = new double[this->acoes.size()];

    ind_car = this->acoes.size();
    while( ind_car-- )
        w[ind_car] = 0;

    ind_ref = reference->acoes.size();
    while( ind_ref-- )
    {
        ind_car = this->acoes.size();
        corr_sum = 0;
        while( ind_car-- )
        {
            corr[ind_car] = *this->acoes[ind_car] * *reference->acoes[ind_ref];
            if( corr[ind_car]<0 )
                corr[ind_car] = 0;

            corr_sum += corr[ind_car];
        }

        ind_car = this->acoes.size();
        while( ind_car-- )
            w[ind_car] += (corr[ind_car]/corr_sum)*reference->porcentagem[ind_ref];
    }

    ind_car = this->acoes.size();
    while( ind_car-- )
        this->porcentagem[ind_car] = w[ind_car];

    delete [] corr;
    delete [] w;
}

void wallet::modernPortfolioTheory(double r0)
{
    size_t N = this->acoes.size();

    double *R = new double[N];      // Return vector
    double *C = new double[N*N];    // Covariance matrix
    double *w = new double[N];      // weights
    double *wC = new double[N];     // weights * Covariance matrix

    double maxIndiceSharpe = -1000000000;

    // Compute Return and Covariance matrix
    size_t n, i, j;
    for(i=0; i<N; i++)
    {
        R[i] = this->acoes[i]->gain();
        for(j=0; j<N; j++)
            C[i+N*j] = *this->acoes[i] ^ *this->acoes[j];
    }

    // Random guess of weights
    n = N<<12;
    while( n-- )
    {
        double S = 0;
        for(i=0; i<N; i++)
        {
            w[i] = rand()%1024;
            S += w[i];
        }
        for(i=0; i<N; i++)
            w[i] /= S;

        double r = 0;
        double s = 0;
        for(i=0; i<N; i++)
        {
            r += w[i]*R[i];
            wC[i] = 0;
            for(j=0; j<N; j++)
                wC[i] += w[j]*C[i+N*j];
        }
        for(i=0; i<N; i++)
            s += w[i]*wC[i];

        double indiceSharpe = (r-r0)/sqrt(s);
        if( indiceSharpe>maxIndiceSharpe )
        {
            maxIndiceSharpe = indiceSharpe;
            for(i=0; i<N; i++)
                this->porcentagem[i] = w[i];
        }
    }

    // Refining
    n = 0;
    while( n<8192 )
    {
        double S = 0;
        for(i=0; i<N; i++)
        {
            w[i] = this->porcentagem[i] + (rand()%1024)/2048/N;
            S += w[i];
        }
        for(i=0; i<N; i++)
            w[i] /= S;

        double r = 0;
        double s = 0;
        for(i=0; i<N; i++)
        {
            r += w[i]*R[i];
            wC[i] = 0;
            for(j=0; j<N; j++)
                wC[i] += w[j]*C[i+N*j];
        }
        for(i=0; i<N; i++)
            s += w[i]*wC[i];

        double indiceSharpe = (r-r0)/sqrt(s);
        if( indiceSharpe>maxIndiceSharpe )
        {
            maxIndiceSharpe = indiceSharpe;
            for(i=0; i<N; i++)
                this->porcentagem[i] = w[i];
            n = 0;
        }
        else
            n++;
    }

    delete [] R;
    delete [] C;
    delete [] w;
    delete [] wC;
}

void wallet::naive()
{
    size_t N = this->acoes.size();
    double prop = 1.0/N;

    while( N-- )
        this->porcentagem[N] = prop;
}
