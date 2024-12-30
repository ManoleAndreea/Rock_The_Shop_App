#include "angajat.h"
#pragma once

class manager: public angajat
{
    public:
        manager();
        manager(const string&,const string&,const string&, tm&);
        float calcul_salariu() const;
        void afisare() const;
        ~manager();
};