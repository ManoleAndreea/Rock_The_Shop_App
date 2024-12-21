#include "angajat.h"


class operatorr: public angajat
{
    float valoare_comenzi_procesate=0;

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
};