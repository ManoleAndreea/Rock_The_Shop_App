#include "angajat.h"
#include <queue>
#include "comanda.h"
#pragma once

class operatorr: public angajat
{
    float valoare_comenzi_procesate=0;
    queue<comanda> comenzi_asignate;

    public:
        operatorr();
        operatorr(const string&, const string&, const string&, tm &);
        void adaugare_comanda_procesata(float);
        float calcul_salariu() const;
        void afisare() const;
        ~operatorr();
        //chiar daca am o valoare in plus in clasa derivata operatorr, operator= functioneaza mostenit.
        //Compilatorul combină operatorul = suprascris din clasa de bază cu atribuirea implicită a membrilor suplimentari ai clasei derivate
        //clasa operatorr apeleaza operator= din clasa de baza pentru a copia membrii din anagajat si copiaza proprii membri suplimentari folosind o atribuire simpla
        void asignare_comanda(const comanda&);
        void proceseaza_comenzi(int);
        size_t get_numar_comenzi() const;

};