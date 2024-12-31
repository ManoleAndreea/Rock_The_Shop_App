#include "disc.h"

disc::disc():produs()
{

}

disc::disc(const string& den, float pr, int nr, const string& casa, const string& trup, const string& alb, const string& t, tm& data):produs(den, pr, nr), casa_disc(casa), trupa(trup), album(alb), tip(t), data_vanzare(data)
{

}

float disc::calcul_pret_final() const
{
    return pret_baza+5;
}

void disc::afisare() const
{
    cout << "Discul: " << endl;
    cout << "Tip: " << tip << ", Casa: " << casa_disc << ", Trupa: " << trupa << ", Data punere in vanzare: " << data_vanzare.tm_year+1900 <<" - "<< data_vanzare.tm_mon+1 << " - " << data_vanzare.tm_mday<< ", ";
    produs::afisare();
}



disc* disc::copie() const
{
    return new disc(*this);
}