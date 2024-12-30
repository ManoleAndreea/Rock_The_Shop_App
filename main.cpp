
#include "stergere.h"
#include <fstream>
#include <vector>
#include <typeinfo>
#include "gestiune.h"



ifstream fin("angajati.txt");
ifstream finn("produse.txt");

gestiune<angajat*> angajati;
gestiune<produs*>produse;

void populare_produse()
{
    for(int i=0; i<7; i++)
    {
        string den;
        float pret;
        int stoc;
        string tip;
        finn >> tip;
        finn>> den >> pret >> stoc;
        if(tip=="Articol_Vestimentar")
        {
            string cul, marca;
            finn >> cul >> marca;
            produse.adauga(new articol_vestimentar(den, pret, stoc, cul, marca));
        }
        else
            if(tip=="Disc")
            {
                string casa, trupa, album, tipp;
                tm data;
                int an, luna, zi;
                finn >> casa >> trupa >> album >> tipp >> an >> luna >> zi;
                luna--;
                an-=1900;
                data.tm_year=an;
                data.tm_mday=zi;
                data.tm_mon=luna;
                produse.adauga(new disc(den, pret, stoc, casa, trupa, album, tip, data));        
            }
            else
                if(tip=="Disc_Vintage")
                {
                    string casa, trupa, album, tipp;
                    tm data;
                    int an, luna, zi;
                    finn >> casa >> trupa >> album >> tipp >> an >> luna >> zi;
                    luna--;
                    an-=1900;
                    data.tm_year=an;
                    data.tm_mday=zi;
                    data.tm_mon=luna;
                    bool mint;
                    int coeficient;
                    finn >> mint >> coeficient;
                    produse.adauga(new disc_vintage(den, pret, stoc, casa, trupa, album, tip, data, mint, coeficient));  
                }

    }
    produse.afisare();
}


void populare_angajati()
{
    for(int i=0; i<10; i++)
    {
        string tip;
        fin >> tip;
        if(tip=="Asistent")
        {
            string nume, prenume, cnp;
            tm data;
            fin >> nume >> prenume >> cnp >> data.tm_year >> data.tm_mon >> data.tm_mday;
            angajati.adauga(new asistent(nume, prenume, cnp, data));
        }
        else
            if(tip=="Manager")
            {
                string nume, prenume, cnp;
                tm data;
                fin >> nume >> prenume >> cnp >> data.tm_year >> data.tm_mon >> data.tm_mday;
                angajati.adauga(new manager(nume, prenume, cnp, data));
            }
            else
                if(tip=="Operator")
                {
                    string nume, prenume, cnp;
                    tm data;
                    fin >> nume >> prenume >> cnp >> data.tm_year >> data.tm_mon >> data.tm_mday;
                    operatorr* op = new operatorr(nume, prenume, cnp, data);
                    angajati.adauga(op);
                    op->adaugare_comanda_procesata(1000);
                }
                else
                    cout <<"Lista nu e buna!"<<endl;
    }

    angajati.afisare();
}

void ecran_principal_logo()
{
    cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
	cout << "                                                                                                                           " <<'\n';
	cout << "                                                                                                                           " <<'\n';
	cout << "                                                                                                                           " <<'\n';
	cout << "     ______     ____     _______    _   __                                                                                 " <<'\n';
	cout << "    |  __  |   / __ \\   |  _____|  | | / /                                                                                " <<'\n'; 
	cout << "    | | _| /  | /  \\ |  | |        | | \\/                                                                                " <<'\n';
	cout << "    | |\\ \\    | \\__/ |  | |_____   | | \\                                                                               " <<'\n';
	cout << "    |_| \\_\\    \\____/   |_______|  |_|\\_\\                                                                             " <<'\n';
	cout << "                                     _________    _     _    ______                                                        " <<'\n';
	cout << "                                    |___   ___|  | |___| |  |  ____|                                                       " <<'\n';
	cout << "                                        | |      |  ___  |  | |____                                                        " <<'\n';
	cout << "                                        | |      | |   | |  |  ____|                                                       " <<'\n';
	cout << "                                        |_|      |_|   |_|  |__|____                                                       " <<'\n';
	cout << "                                                              _____    _     _    ______    ______                         " <<'\n';
	cout << "                                                             |  ___|  | |___| |  /  __  \\  |  __  |                       " <<'\n'; 
	cout << "                                                             | |___   |  ___  |  | /  \\ |  |  ___/                        " <<'\n';
	cout << "                                                             |___  |  | |   | |  | \\__/ |  | |                            " <<'\n';
	cout << "                                                              ___| |  |_|   |_|   \\____/   |_|                            " <<'\n';
	cout << "                                                             |_____|                                                       " <<'\n';
	cout << "                                                                                                                           " <<'\n';
	cout << "                                                                                                                           " <<'\n';
	cout << "                                                                                                                           " <<'\n';
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
}

void meniu_principal()
{
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';

    cout << "\n                                               ==== Meniu Principal ====\n\n";
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
    cout << "\n                                                  Ce te intereseaza? \n";
    cout << "            1. Gestiune angajati\n";
    cout << "            2. Gestiune stoc\n";
    cout << "            3. Procesare comenzi\n";
    cout << "            4. Raportare\n";
    cout << "            0. Iesire\n\n";
    cout << "Introdu optiunea dorita: ";

}

void adaugare_angajat()
{
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';

    cout <<"\n\n      Introdu tipul de angajat: ";
    string tip, nume, prenume, cnp;
    cin >> tip;
    cout << "\n      Introdu numele: ";
    cin >> nume >> prenume;
    cout << "\n      Introdu CNP ul: ";
    cin >> cnp;
    
        auto verificare_major=[](const string cnp)->bool
        {
            if(::validare_cnp(cnp)==0)
                throw invalid_argument("CNP INVALID");
            int sex=cnp[0]-'0';
            int an=stoi(cnp.substr(1, 2));
            int luna=stoi(cnp.substr(3, 2));
            int zi=stoi(cnp.substr(5, 2)); 
            int secol;
            if (sex==1 || sex==2) 
                secol=1900;
            else 
                if (sex==5 || sex==6) 
                    secol=2000;
                else 
                    if (sex==3 || sex==4) 
                        secol=1800;
            an+=secol;
            cout << "!!! "<<an << endl;
            tm data_nastere={};
            data_nastere.tm_year=an-1900;
            data_nastere.tm_mon=luna-1;
            data_nastere.tm_mday=zi;

            time_t t=time(nullptr);
            tm* data_curenta=localtime(&t);

            int varsta = data_curenta->tm_year + 1900 - an;
            cout << "---" << varsta << endl;
            if ((data_curenta->tm_mon<data_nastere.tm_mon) || (data_curenta->tm_mon==data_nastere.tm_mon && data_curenta->tm_mday<data_nastere.tm_mday)) 
                varsta--;
            cout << "---" << varsta << endl;

                if(varsta>=18)
                    return true;    
                return false;
        };

        if(!verificare_major(cnp))
            throw invalid_argument("Angajatul nu este major!");
        cout << "\n      Si data la care a fost angajat(AA LL ZZ): ";
        tm data;
        cin >> data.tm_year >> data.tm_mon >> data.tm_mday;

        if(tip=="Operator")
                angajati.adauga(new operatorr(nume, prenume, cnp, data));
        else
            if(tip=="Manager")
                angajati.adauga(new manager(nume, prenume, cnp, data));
            else
                if(tip=="Asistent")
                    angajati.adauga(new asistent(nume, prenume, cnp, data));
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
        

}

void stergere_angajat()
{
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
  
 
    cout <<"\n\n      Doresti sa stergi un angajat dupa CNP(1), sau dupa ID(2)? ";
    int tip;
    cin >> tip;
    if(tip==1)
    {
        cout <<"\n\n      Introdu CNP:  ";
        string cnp;
        cin >> cnp;
        if(::validare_cnp(cnp)==0)
            throw invalid_argument("CNP INVALID!!");
            string criteriu="CNP";
        angajati.sterge(criteriu, cnp);
        
    }
    else if(tip==2)
    {
        cout <<"\n\n      Introdu ID:  ";
        string id;
        cin >> id;
        string criteriu="ID";
        angajati.sterge(criteriu, id);
    }
        
        
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';

    

}


void detalii_angajat()
{
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';

    cout <<"\n\n      Doresti sa cauti angajatul dupa CNP(1), sau dupa ID(2)? ";
     int tip;
    cin >> tip;
    if(tip==1)
    {
        cout <<"\n\n      Introdu CNP:  ";
        string cnp;
        cin >> cnp;
        if(::validare_cnp(cnp)==0)
            throw invalid_argument("CNP INVALID!!");
        auto it=angajati.cauta("CNP", cnp);
        it->afisare();
         
        
    }
    else if(tip==2)
    {
        cout <<"\n\n      Introdu ID:  ";
        string id;
        cin >> id;
        auto it=angajati.cauta("ID", id);
        it->afisare();
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';


    }



}

void modificare_angajat()
{
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';

    cout <<"\n\n      Doresti sa modifici angajatul dupa CNP(1), sau dupa ID(2)? ";
    int tip;
    cin >> tip;
    if(tip==1)
    {
        cout <<"\n\n      Introdu CNP:  ";
        string cnp, num;
        cin >> cnp;
        if(::validare_cnp(cnp)==0)
            throw invalid_argument("CNP INVALID!!");
        cout << "\n\n      Introdu noul nume: ";
        cin >> num;
        auto it=angajati.cauta("CNP", cnp);
        it->set_nume(num);
        it->afisare();
         
        
    }
    else if(tip==2)
    {
        cout <<"\n\n      Introdu ID:  ";
        string id, num;
        cin >> id;
        cout << "\n\n      Introdu noul nume: ";
        cin >> num;
        auto it=angajati.cauta("ID", id);
        it->set_nume(num);
        it->afisare();
    }
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';


}
void gestiune_angajati()
{

    int var=1;
    while(var)
    {
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';

    cout << " \n\n       Doresti sa:\n\n      - Adaugi(1) un nou angajat?\n      - Sa stergi(2) un angajat?\n      - Sa modifici(3) un angajat?\n      - Sau sa aflii mai multe detalii(4) despre un angajat?\n      - Poate doresti sa vezi lista(5) cu toti angajatii inregistrati la Rock the Shop?\n      -Doresti sa te intorci la meniul principal?(0) \n";

    cin >> var;

	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
    if(var==1)
        adaugare_angajat();
    else
        if(var==2)
            stergere_angajat();
        else 
            if(var==3)
                modificare_angajat();
            else
                if(var==4)
                detalii_angajat();
                else
                    if(var==5)
                    {
                        cout <<"\n\n      Lista angajatilor:  ";
                        angajati.afisare();
                    }
    }

}

void adaugare_produs()
{
    cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';

    cout <<"\n\n      Introdu tipul de produs: ";
    string tip;
    cin >> tip;
    if(tip=="Articol_Vestimentar")
    {
        cout <<"\n\n      Introdu denumirea, pretul, stocul, culoarea si marca: ";
        string denumire, culoare, marca;
        float pret;
        int stoc;
        cin >> denumire >> pret >> stoc >> culoare >> marca;
        produse.adauga(new articol_vestimentar(denumire, pret, stoc, culoare, marca));
    }
    else
        if(tip=="Disc")
        {
            cout <<"\n\n      Introdu denumirea, pretul, stocul, casa, trupa, album, data de la lansare(AN, LUNA, ZI), tipul(cd sau vinil): ";
            string den, casa, trupa, album, tip;
            int an, luna, zi, stoc;
            float pret;
            cin >> den >> pret >> stoc >> casa >> trupa >> album >> an >> luna >> zi >> tip;
            luna--;
            an-=1900;
            tm data;
            data.tm_year=an;
            data.tm_mday=zi;
            data.tm_mon=luna;
            produse.adauga(new disc(den, pret, stoc, casa, trupa, album, tip, data));

       }
       else
            if(tip=="Disc_Vintage")
            {
                cout <<"\n\n      Introdu denumirea, pretul, stocul, casa, trupa, album, data de la lansare(AN, LUNA, ZI), tipul(cd sau vinil), daca este mint(1 sau 0), si coeficientul de raritate: ";
                string den, casa, trupa, album, tip;
                int an, luna, zi, stoc, coef;
                float pret;
                bool mint;
                cin >> den >> pret >> stoc >> casa >> trupa >> album >> an >> luna >> zi >> tip >> mint >> coef;
                luna--;
                an-=1900;
                tm data;
                data.tm_year=an;
                data.tm_mday=zi;
                data.tm_mon=luna;
                produse.adauga(new disc_vintage(den, pret, stoc, casa, trupa, album, tip, data, mint, coef));
            }



}
void stergere_produs()
{
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
    cout <<"\n\n      Introdu Codul unic al produsului pe care vrei sa il stergi:  ";
    int cod;
    cin >> cod;
    produse.sterge("COD", to_string(cod));
}
void detalii_produse()
{
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';

    cout <<"\n\n      Introdu Codul unic:  ";
    int cod;
    cin >> cod;
    auto it=produse.cauta("COD", to_string(cod));
    it->afisare();


}
void modificare_produs()
{
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
    cout <<"\n\n      Introdu Codul unic al produsului pe care vrei sa l modifici:  ";
    int cod;
    cin >> cod;
    auto it=produse.cauta("COD", to_string(cod));
    cout <<"\n\n      Doresti sa modifici denumirea(1) sau pretul(2)?  ";
    int tip;
    cin >> tip;
    if(tip==1)
    {
        cout <<"\n\n      Introdu noua denumire:  ";
        string denumire;
        cin >> denumire;
        it->set_denumire(denumire);
        cout << "\n\n     Produsul a fost modificat!\n";
        it->afisare();
        
    }
    else
        if(tip==2)
        {
            cout <<"\n\n      Introdu noul pret:  ";
            float pret;
            cin >> pret;
            it->set_pret(pret);
            cout << "\n\n     Produsul a fost modificat!\n";
            it->afisare();
        }

}

void gestiune_produse()
{
    int var=1;
    while(var)
    {
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';

    cout << " \n\n       Doresti sa:\n\n      - Adaugi(1) un nou produs?\n      - Sa stergi(2) un produs?\n      - Sa modifici(3) un produs?\n      - Sau sa aflii mai multe detalii(4) despre un produs?\n      - Poate doresti sa vezi lista(5) cu toate produsele de la Rock the Shop?\n      -Doresti sa te intorci la meniul principal?(0) \n";

    cin >> var;

	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
    if(var==1)
        adaugare_produs();
    else
        if(var==2)
            stergere_produs();
        else 
            if(var==3)
                modificare_produs();
            else
                if(var==4)
                detalii_produse();
                else
                    if(var==5)
                    {
                        cout <<"\n\n      Lista produselor:  ";
                        produse.afisare();
                    }
    }

}
int main()
{
    try
    {
        populare_angajati();
        populare_produse();
        ecran_principal_logo();
        meniu_principal();
        int var;
        cin >> var;
        if(var==1)
            gestiune_angajati();
        else
            if(var==2)
                gestiune_produse();


    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    
}