#include <string>
#include <iostream>
#pragma once

using namespace std;

class produs
{
    protected:
        string denumire;
        const int cod_unic;
        static int urmatorul_cod;
        float pret_baza;
        int stoc;

    public:
        produs();
        produs(const string&, float, int);
        produs(const produs&);
        virtual produs& operator=(const produs&);
        virtual ~produs();
        virtual void afisare() const=0;
        virtual float calcul_pret_final() const=0;
        int get_cod() const;
        int get_stoc() const;
        string get_denumire() const;
        float get_pret_baza() const;
        void set_denumire(string &);
        void set_pret(float);
        virtual produs* copie() const=0;
        void scade_stoc(int);
};