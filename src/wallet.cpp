#include "wallet.h"

wallet::wallet()
{

}

wallet::~wallet()
{
    this->acoes.clear();
    this->porcentagem.clear();
}

void wallet::insert(stock &acao, double porcentagem)
{
    this-> acoes.insert(this->acoes.end(), acao);
    this-> porcentagem.insert(this->porcentagem.end(), porcentagem);
}

void wallet::defineFromReference(wallet *reference)
{
    size_t ind_ref, ind_car;
    double *corr = new double[this->acoes.size()];
    double corr_sum;

    ind_car = this->acoes.size();
    while( ind_car-- )
        this->porcentagem[ind_car] = 0;

    ind_ref = reference->acoes.size();
    while( ind_ref-- )
    {
        ind_car = this->acoes.size();
        corr_sum = 0;
        while( ind_car-- )
        {
            corr[ind_car] = this->acoes[ind_car] * reference->acoes[ind_ref];
            if( corr[ind_car]<0 )
                corr[ind_car] = 0;

            corr_sum += corr[ind_car];
        }

        ind_car = this->acoes.size();
        while( ind_car-- )
            this->porcentagem[ind_car] += (corr[ind_car]/corr_sum)*reference->porcentagem[ind_ref];
    }

    delete [] corr;
}
