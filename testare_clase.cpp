#include "articol_vestimentar.h"
#include "disc.h"
#include "disc_vintage.h"
#include "asistent.h"
#include "operatorr.h"
#include "manager.h"
#include <iostream>




int main() {
    try {
        // Testare pentru clasa "articol_vestimentar"
        articol_vestimentar av("tricou", 50.0, 10, "negru", "Nike");
        articol_vestimentar av_copy(av); // Test constructor copiere
        articol_vestimentar av_default; // Test constructor fara parametri
        av_default = av; // Test operator egal

        av.afisare();
        cout << "Pret final: " << av.calcul_pret_final() << " RON\n";
        av_copy.afisare();
        av_default.afisare();

        // Testare pentru clasa "disc"
        tm data_disc; // Data: 1 Ianuarie 2023
        data_disc.tm_year=123;
        data_disc.tm_mon=0;
        data_disc.tm_mday=1;
        disc d("album", 80.0, 5, "Sony", "Metallica", "Black Album", "CD", data_disc);
        disc d_copy(d); // Test constructor copiere
        disc d_default; // Test constructor fara parametri
        d_default = d; // Test operator egal

        d.afisare();
        cout << "Pret final: " << d.calcul_pret_final() << " RON\n";
        d_copy.afisare();
        d_default.afisare();

        // Testare pentru clasa "disc_vintage"
        disc_vintage dv("vinil", 150.0, 3, "Universal", "Queen", "Greatest Hits", "Vinil", data_disc, true, 3);
        disc_vintage dv_copy(dv); // Test constructor copiere
        disc_vintage dv_default; // Test constructor fara parametri
        dv_default = dv; // Test operator egal

        dv.afisare();
        cout << "Pret final: " << dv.calcul_pret_final() << " RON\n";
        dv_copy.afisare();
        dv_default.afisare();

        // Testare pentru clasa "asistent"
        tm data_angajare = {0, 0, 0, 15, 5, 115}; // Data: 15 Iunie 2015
        asistent a("Ion", "Popescu", "6031124410163", data_angajare);
        asistent a_copy(a); // Test constructor copiere
        asistent a_default; // Test constructor fara parametri
        a_default = a; // Test operator egal

        a.afisare();
        std::cout << "Salariu: " << a.calcul_salariu() << " RON\n";
        a_copy.afisare();
        a_default.afisare();

        // Testare pentru clasa "operatorr"
        operatorr o("Maria", "Ionescu", "6031124410163", data_angajare);
        operatorr o_copy(o); // Test constructor copiere
        operatorr o_default; // Test constructor fara parametri
        o_default = o; // Test operator egal

        o.afisare();
        o.adaugare_comanda_procesata(10000.0);
        std::cout << "Salariu: " << o.calcul_salariu() << " RON\n";
        o_copy.afisare();
        o_default.afisare();

        // Testare pentru clasa "manager"
        manager m("Andrei", "Popa", "6031124410163", data_angajare);
        manager m_copy(m); // Test constructor copiere
        manager m_default; // Test constructor fara parametri
        m_default = m; // Test operator egal

        m.afisare();
        std::cout << "Salariu: " << m.calcul_salariu() << " RON\n";
        m_copy.afisare();
        m_default.afisare();

    } catch (const std::exception &e) {
        std::cerr << "Eroare: " << e.what() << "\n";
    }

    return 0;
}
