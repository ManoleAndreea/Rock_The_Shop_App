#include <iostream>
#include <string>
#include <ctime>
#pragma once
#include "validare_cnp.h"

using namespace std;

class angajat
{
    static int urmatorul_id;
    const int id;
    string nume, prenume, cnp;
    tm data_angajare; // face parte in ctime este un struct
    //tm_year: Anul minus 1900 (de exemplu, pentru 2024, valoarea este 2024 - 1900 = 124)
    //tm_mon: Luna din an (0 pentru ianuarie, 11 pentru decembrie)
    //tm_mday: Ziua din lună (1–31)


    public:
        angajat();
        angajat(const string &,const string &,const string &, tm & );
        angajat(const angajat&); // cosnt de copiere si mutare sunt singurele care se mostenesc si in clasele derivate, fara a mai fi precizate. 
        virtual float calcul_salariu() const=0;
        virtual void afisare() const=0;
        virtual ~angajat()=default;
        void set_nume(string &);
        int ani_experienta() const;
        static bool validare_cnp(string&);
        virtual bool verificare_zi_nastere() const;
        virtual angajat& operator=(const angajat&);
        virtual string get_cnp() const;
        virtual int get_id() const;
        virtual string get_nume() const;


};