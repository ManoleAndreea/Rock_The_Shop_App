#include "produs.h"
#include <ctime>
#pragma once

class disc: public produs 
{
    string casa_disc;
    string trupa;
    string album;
    string tip; 
    tm data_vanzare;

    public:
        disc();
        disc(const string&, float, int, const string&, const string&, const string&, const string&, tm&);
        float calcul_pret_final() const;
        void afisare() const;
        disc* copie() const;
};

