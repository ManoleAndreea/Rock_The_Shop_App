#include "angajat.h"
#pragma once

class asistent: public angajat
{
    public:
        asistent(const string&,const string&,const string&, tm&);
        asistent();
        ~asistent();
        float calcul_salariu() const;
        void afisare() const;

};