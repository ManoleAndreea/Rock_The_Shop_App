#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "disc.h"
#include "articol_vestimentar.h"
#include "disc_vintage.h"
#pragma once

class comanda
{
    static int urmatorul_id;
    const int id_comanda;
    tm durata_solutionare;///o sa fie calculata in functie de numarul de produse din lista comenzii
    /// o sa iau 30 de minute pentru fiecare articol vestimentar, 15 minute pentru discuri si discuri vintage
    tm data_primire;
    float valoare_de_baza;
    float valoare_finala;
    vector<produs*> produse;

    public:
        comanda();
        comanda(tm data, const vector<produs*>);
        float calcul_val_baza() const;
        float calcul_val_finala() const;
        comanda& operator=(const comanda&);
        comanda(const comanda&);
        void afisare() const;
        ~comanda();
        bool validare() const;
};
