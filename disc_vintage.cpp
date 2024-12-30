#include "disc_vintage.h"

disc_vintage::disc_vintage():disc()
{

}

disc_vintage::disc_vintage(const string& den, float pr, int nr, const string& casa, const string& trup, const string& alb, const string& t, tm& data, bool min, int coef):disc(den, pr, nr, casa, trup, alb, t, data), mint(min), coeficient_raritate(coef)
{
    if(coef<1 || coef>5)
        throw invalid_argument("Coeficientul de raritate trebuie sa fie intre 1 si 5!");
}

float disc_vintage::calcul_pret_final() const
{
    return disc::calcul_pret_final() +15*coeficient_raritate;
}

void disc_vintage::afisare() const
{
    cout << "Discul vintage: " << endl;
    if(mint)
        cout <<"Este mint, ";
    else
        cout <<"Nu este mint, ";
    cout <<"Are coeficientul de raritate: " << coeficient_raritate << ", ";
    disc::afisare();
}


disc_vintage* disc_vintage::copie() const
{
    return new disc_vintage(*this);
}