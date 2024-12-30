#include "comanda.h"

int comanda::urmatorul_id=1;
comanda::comanda():id_comanda(urmatorul_id++)
{

}

comanda::comanda(const comanda& copie):id_comanda(urmatorul_id++)
{
    data_primire=copie.data_primire;
    durata_solutionare=copie.durata_solutionare;
    valoare_de_baza=copie.valoare_de_baza; 
    valoare_finala=copie.valoare_finala;
    for(const auto& produs:copie.produse)
        produse.push_back(produs->copie());
}

float comanda:: calcul_val_baza() const
{
    float valoare=0;
    for(const auto& produs:produse)
        valoare+=produs->get_pret_baza();
    return valoare;
}

bool comanda:: validare() const
{   
    if(calcul_val_baza()<100)
        throw invalid_argument("Valoarea comenzii trebuie sa fie de minim 100 de lei!");
    int discuri=count_if(produse.begin(), produse.end(), [](produs* p) 
    { 
        return dynamic_cast<disc*>(p)!=nullptr; 
    });
    int discuri2=count_if(produse.begin(), produse.end(), [](produs* p) 
    { 
        return dynamic_cast<disc_vintage*>(p)!=nullptr; 
    });
    int articole=count_if(produse.begin(), produse.end(), [](produs* p) 
    { 
        return dynamic_cast<articol_vestimentar*>(p)!=nullptr;
    }); 

    return discuri+discuri2<=5 && articole<=3;  
}

float comanda:: calcul_val_finala() const
{
    float valoare=0;
    for(const auto& produs:produse)
        valoare+=produs->calcul_pret_final();
    return valoare; 
}

comanda::comanda(tm data, const vector<produs*> prod):id_comanda(urmatorul_id++), data_primire(data)
{
    durata_solutionare.tm_min=0;
    durata_solutionare.tm_hour=0;
    for(const auto& produs:prod)
    {
        produse.push_back(produs->copie());
        if(dynamic_cast<disc*>(produs) || dynamic_cast<disc_vintage*>(produs))
            durata_solutionare.tm_min+=15;
        else
            durata_solutionare.tm_min+=30;      
    }
    valoare_de_baza=calcul_val_baza();
    valoare_finala = calcul_val_finala();
}


comanda& comanda:: operator=(const comanda& copie)
{
    if(this!=&copie)
    {
        for(auto& produs:produse) 
            delete produs;
        produse.clear();

        data_primire=copie.data_primire;
        durata_solutionare=copie.durata_solutionare;
        valoare_de_baza=copie.valoare_de_baza; 
        valoare_finala=copie.valoare_finala;
        for(const auto& produs:copie.produse)
            produse.push_back(produs->copie());
    }
        return *this;
}

void comanda:: afisare () const
{
    cout << "Comanda cu id ul: "<< id_comanda <<"a fost facuta la data: "<< data_primire.tm_mon-1 << " " << data_primire.tm_mday << ", ora: " << data_primire.tm_hour <<":" << data_primire.tm_min<<", durata de solutionare: "<<durata_solutionare.tm_min << ", valoarea finala: "<<valoare_finala << ", si contine "<< produse.size() << " produse: ";
    for(const auto& produs:produse)
            produs->afisare();
    
}

comanda::~comanda() 
{
    for(auto& produs:produse) 
        delete produs;
    produse.clear();
}