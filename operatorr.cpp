#include "operatorr.h"


operatorr::operatorr():angajat()
{
    valoare_comenzi_procesate=0;
}
operatorr::operatorr(const string& num,const string &prenum,const string& CNP, tm& data): angajat(num, prenum, CNP, data)
{
    valoare_comenzi_procesate=0;
}

float operatorr::calcul_salariu() const
{
    int bonus=0;
    if(verificare_zi_nastere())
        bonus=100;
    return (3500 + 100*ani_experienta())*1.00 +0.005*valoare_comenzi_procesate+bonus;
}

void operatorr:: afisare() const
{
    cout << "Operatorul: " << endl;
    angajat::afisare();
}

operatorr::~operatorr() 
{

}

void operatorr:: adaugare_comanda_procesata(float x)
{
    valoare_comenzi_procesate+=x;
}