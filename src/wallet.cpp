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

void wallet::smallerVariance()
{
    size_t N = this->acoes.size();

    double *C = new double[N*N];    // Covariance matrix
    double *w = new double[N];      // weights
    double *wC = new double[N];     // weights * Covariance matrix

    double minVariance = 1000000000;

    // Compute Covariance matrix
    size_t n, i, j;
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            C[i+N*j] = *this->acoes[i] ^ *this->acoes[j];

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

        double variance = 0;
        for(i=0; i<N; i++)
        {
            wC[i] = 0;
            for(j=0; j<N; j++)
                wC[i] += w[j]*C[i+N*j];
        }
        for(i=0; i<N; i++)
            variance += w[i]*wC[i];

        if( variance<minVariance )
        {
            minVariance = variance;
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

        double variance = 0;
        for(i=0; i<N; i++)
        {
            wC[i] = 0;
            for(j=0; j<N; j++)
                wC[i] += w[j]*C[i+N*j];
        }
        for(i=0; i<N; i++)
            variance += w[i]*wC[i];

        if( variance<minVariance )
        {
            minVariance = variance;
            for(i=0; i<N; i++)
                this->porcentagem[i] = w[i];
            n = 0;
        }
        else
            n++;
    }

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

bool wallet::itselfIterative()
{
    double *prop = new double[this->acoes.size()];
    this->naive();
    size_t i, n;
    double diff_max, diff;

    i = this->acoes.size();
    while( i-- )
        prop[i] = this->porcentagem[i];

    n = 0;
    do
    {
        n++;

        this->fromReference(this);
        diff_max = 0;

        i = this->acoes.size();
        while( i-- )
        {
            diff = abs( prop[i] - this->porcentagem[i] );
            prop[i] = this->porcentagem[i];
            if( diff>diff_max )
                diff_max = diff;
        }
    } while( diff_max > 1e-6 && n<10000 );

    delete [] prop;
    return n>=10000;
}

void __agrupa(size_t N, vector<double> &prop, double *corr, vector<size_t> *index)
{
    size_t m, n, im=0, in=0;
    double corr_max = -2;

    for(n=0; n<N; n++)
    {
        for(m=n+1; m<N; m++)
        {
            if( corr[n+m*N]>corr_max )
            {
                corr_max = corr[n+m*N];
                in = n;
                im = m;
            }
        }
    }
    if( corr_max<-1 )
        return;

    for(n=0; n<N; n++)
    {
        corr[in+n*N] = max(corr[in+n*N], corr[im+n*N]);
        corr[n+in*N] = max(corr[n+in*N], corr[n+im*N]);
    }
    for(n=0; n<N; n++)
    {
        corr[im+n*N] = -2;
        corr[n+im*N] = -2;
    }

    n = index[im].size();
    while( n-- )
        index[in].push_back(index[im][n]);
    index[im].clear();

    n = index[in].size();
    while( n-- )
        prop[index[in][n]] /= 2;

    __agrupa(N, prop, corr, index);
}

void wallet::huffman()
{
    size_t N = this->acoes.size();
    double *corr = new double[N*N];
    vector<size_t> *index = new vector<size_t>[N];

    size_t n, m;

    for(n=0; n<N; n++)
    {
        this->porcentagem[n] = 1;
        index[n].push_back(n);

        for(m=0; m<=n; m++)
            corr[n+m*N] = -2;
        for(; m<N; m++)
            corr[n+m*N] = *this->acoes[n] * *this->acoes[m];
    }

    __agrupa(N, this->porcentagem, corr, index);

    delete [] corr;
    delete [] index;
}

void wallet::print()
{
    for(size_t i=0; i<this->acoes.size(); i++)
    {
        printf("  %+7.2f\t(%+7.2f, %+7.2f)\t", 100*this->porcentagem[i], 100*this->acoes[i]->gain(), 100*this->acoes[i]->gain_in_evaluate_interval());
        cout << this->acoes[i]->name << endl;
    }
    cout << endl;
}

void wallet::gain_in_evaluate_interval(double &gain, double &variance)
{
    size_t N = this->acoes.size();

    double *C = new double[N*N];    // Covariance matrix
    double *wC = new double[N];     // weights * Covariance matrix

    // Compute Covariance matrix
    size_t i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            C[i+N*j] = this->acoes[i]->variance_in_evaluate_interval(*this->acoes[j]);
    }

    // Compute gain and variance
    gain = 0;
    variance = 0;
    for(i=0; i<N; i++)
    {
        gain += this->porcentagem[i]*this->acoes[i]->gain_in_evaluate_interval();
        wC[i] = 0;
        for(j=0; j<N; j++)
            wC[i] += this->porcentagem[j]*C[i+N*j];
    }
    for(i=0; i<N; i++)
        variance += this->porcentagem[i]*wC[i];

    delete [] C;
    delete [] wC;
}
