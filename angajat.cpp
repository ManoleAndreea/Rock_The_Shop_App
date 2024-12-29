#include "angajat.h"

int angajat::urmatorul_id=1;
angajat::angajat():id(urmatorul_id++)
{

}

bool angajat:: validare_cnp(string & c)
{
    return ::validare_cnp(c);
}

bool angajat::verificare_zi_nastere() const
{
    int luna_nastere=stoi(cnp.substr(3, 2));
    time_t t=time(nullptr);
    tm *luna_curenta=localtime(&t);
    if(luna_curenta->tm_mon+1==luna_nastere)
        return true;
    return false;
}

angajat::angajat(const angajat& copie):id(urmatorul_id++)
{
    nume=copie.nume;
    prenume=copie.prenume;
    cnp=copie.cnp;
    data_angajare=copie.data_angajare;
}

angajat::angajat(const string & num,const string &prenum,const string &CNP, tm & d):id(urmatorul_id++), nume(num), prenume(prenum), cnp(CNP), data_angajare(d)
{
    if(num.length()<3 || num.length()>30)
        throw invalid_argument("Numele trebuie sa aiba intre 3 si 3o de caractere");
    if(prenum.length()<3 || prenum.length()>30)
        throw invalid_argument("Prenumele trebuie sa aiba intre 3 si 30 de caracatere");
    string c=CNP;
    if(!validare_cnp(c))
        throw invalid_argument("CNP-ul este invalid!");
}

int angajat::ani_experienta() const
{
    time_t t=time(nullptr);
    tm data_curenta=*localtime(&t);
    return data_curenta.tm_year+1900-data_angajare.tm_year;
}

void angajat::set_nume(string & num)
{
    this->nume=num;
    /// ana are mere si andra ar putea sa ma aiba pe mine daca si ar dori asta cu adevarat offff
}

void angajat:: afisare() const
{
    float sal=calcul_salariu();
    cout <<"ID: " << id << ", Nume: " << nume << " " << prenume << ", CNP: " << cnp << ", Salariu: "<< sal << endl; 
}


angajat& angajat:: operator=(const angajat& copie)
{
    if(this!=&copie)
    {
        nume=copie.nume;
        prenume=copie.prenume;
        cnp=copie.cnp;
        data_angajare=copie.data_angajare;
    }
    return *this;
}

string angajat::get_cnp() const
{
    return cnp;
}

int angajat::get_id() const
{
    return id;
}