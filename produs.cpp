#include "produs.h"

int produs::urmatorul_cod=1;

produs::produs():cod_unic(urmatorul_cod++)
{

}

produs::produs(const string & den, float pret, int nr):denumire(den), pret_baza(pret), stoc(nr), cod_unic(urmatorul_cod++)
{

}

produs::produs(const produs & copie):cod_unic(urmatorul_cod++)
{
    denumire=copie.denumire;
    pret_baza=copie.pret_baza;
    stoc=copie.stoc;
}

produs& produs::operator=(const produs &copie)
{
    if(this!=&copie)
    {
        this->denumire=copie.denumire;
        this->stoc=copie.stoc;
        this->pret_baza=copie.pret_baza;
    }

    return *this;
}

int produs::get_cod() const
{
    return cod_unic;
}

produs::~produs()
{

}

void produs:: afisare() const
{
    float pret=calcul_pret_final();
    cout <<"Cod: " << cod_unic << ", Denumire: " << denumire <<", Pret: " << pret << ", Stoc: "<< stoc << endl; 
     
}