#include "operatorr.h"


operatorr::operatorr():angajat()
{
    valoare_comenzi_procesate=0;
}
operatorr::operatorr(const string& num,const string &prenum,const string& CNP, tm& data): angajat(num, prenum, CNP, data)
{
    valoare_comenzi_procesate=0;
}

float operatorr::calcul_salariu() const
{
    int bonus=0;
    if(verificare_zi_nastere())
        bonus=100;
    return (3500 + 100*ani_experienta())*1.00 +0.005*valoare_comenzi_procesate+bonus;
}

void operatorr:: afisare() const
{
    cout << "Operatorul: " << endl;
    angajat::afisare();
}

operatorr::~operatorr() 
{

}

void operatorr:: adaugare_comanda_procesata(float x)
{
    valoare_comenzi_procesate+=x;
}

size_t operatorr:: get_numar_comenzi() const
{
    return comenzi_asignate.size();
}

void operatorr:: proceseaza_comenzi(int timp_global)
{
    if(!comenzi_asignate.empty()) 
    {
        comanda& actuala=comenzi_asignate.front();
        int durata=actuala.get_durata();
        actuala.decrementare_durata();
        cout << "[Timp: " << timp_global << "] Operatorul " << get_nume() << " proceseaza comanda ID: " << actuala.get_id() << ". Timp ramas: " << actuala.get_durata() << " minute.\n";

        if(actuala.get_durata()<=0)
         {
            cout << "[Timp: " << timp_global << "] Operatorul " << get_nume() << " a finalizat comanda ID: " << actuala.get_id() << ".\n";
            nr_comenzi_procesate++;
            valoare_comenzi_procesate+=actuala.calcul_val_finala();
            comenzi_asignate.pop();
        }
    } 
    else 
        cout << "[Timp: " << timp_global << "] Operatorul " << get_nume() << " este inactiv.\n";
    
}

void operatorr::asignare_comanda(const comanda &c)
{
    if(comenzi_asignate.size()>=3)
        throw length_error("Operatorul poate prelua maxim 3 comenzi!");
    comenzi_asignate.push(c);
   
    cout << "Operatorul "<<get_nume()<< " a preluat comanda ID: " << c.get_id() << "\n";
}

int operatorr::get_numar_comenzi_procesate() const
{
    return nr_comenzi_procesate;
}

float operatorr::get_valoare_comenzi()const
{
    return valoare_comenzi_procesate;
}