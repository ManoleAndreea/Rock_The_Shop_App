#include "asistent.h"



asistent::asistent():angajat()
{

}
asistent::asistent(const string& num,const string &prenum,const string& CNP, tm& data): angajat(num, prenum, CNP, data)
{
    
}

float asistent::calcul_salariu() const
{
    int bonus=0;
    if(verificare_zi_nastere())
        bonus=100;
    return (3500 + 100*ani_experienta())*0.75+bonus;
}

void asistent:: afisare() const
{
    cout << "Asistentul: " << endl;
    angajat::afisare();
}

asistent::~asistent() 
{

}

