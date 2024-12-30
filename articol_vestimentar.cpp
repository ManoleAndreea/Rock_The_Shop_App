#include "articol_vestimentar.h"

articol_vestimentar::articol_vestimentar():produs()
{

}

articol_vestimentar::articol_vestimentar(const string &den, float pret, int nr, const string & col, const string & marc):produs(den, pret, nr), culoare(col), marca(marc)
{

}

float articol_vestimentar::calcul_pret_final() const
{
    return pret_baza+20;
}

void articol_vestimentar::afisare() const
{
    cout << "Articolul vestimentar: " << endl;
    cout << "Culoarea: "<<culoare<<", Marca: "<< marca<<", ";
    produs::afisare();
}

articol_vestimentar* articol_vestimentar:: copie() const
{
    return new articol_vestimentar(*this);
}
