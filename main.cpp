#include "manager.h"
#include "operatorr.h"
#include "asistent.h"
#include "stergere.h"
#include "articol_vestimentar.h"
#include <fstream>
#include <vector>
#include <typeinfo>



ifstream fin("angajati.txt");

vector<angajat*> angajati;


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
            angajati.push_back(new asistent(nume, prenume, cnp, data));
        }
        else
            if(tip=="Manager")
            {
                string nume, prenume, cnp;
                tm data;
                fin >> nume >> prenume >> cnp >> data.tm_year >> data.tm_mon >> data.tm_mday;
                angajati.push_back(new manager(nume, prenume, cnp, data));
            }
            else
                if(tip=="Operator")
                {
                    string nume, prenume, cnp;
                    tm data;
                    fin >> nume >> prenume >> cnp >> data.tm_year >> data.tm_mon >> data.tm_mday;
                    operatorr* op = new operatorr(nume, prenume, cnp, data);
                    angajati.push_back(op);
                    op->adaugare_comanda_procesata(1000);
                }
                else
                    cout <<"Lista nu e buna!"<<endl;
    }

    for(int i=0; i<10; i++)
        angajati[i]->afisare();
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
                angajati.push_back(new operatorr(nume, prenume, cnp, data));
        else
            if(tip=="Manager")
                angajati.push_back(new manager(nume, prenume, cnp, data));
            else
                if(tip=="Asistent")
                    angajati.push_back(new asistent(nume, prenume, cnp, data));
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
        

}

void stergere_angajat()
{
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
    int contor_manageri=count_if(angajati.begin(), angajati.end(), [](const angajat*a)
    {
        return typeid(*a)==typeid(manager);
    });
    int contor_asistenti=count_if(angajati.begin(), angajati.end(), [](const angajat*a)
    {
        return typeid(*a)==typeid(asistent);
    });
    int contor_operatori=count_if(angajati.begin(), angajati.end(), [](const angajat*a)
    {
        return typeid(*a)==typeid(operatorr);
    });

    cout << contor_manageri << ' '<< contor_asistenti << ' ' << contor_operatori<<endl ;
    cout <<"\n\n      Doresti sa stergi un angajat dupa CNP(1), sau dupa ID(2)? ";
    int tip;
    cin >> tip;
    vector<angajat*>::iterator it;
    if(tip==1)
    {
        cout <<"\n\n      Introdu CNP:  ";
        string cnp;
        cin >> cnp;
        if(::validare_cnp(cnp)==0)
            throw invalid_argument("CNP INVALID!!");
        stergere criteriu("CNP", cnp);
        it=find_if(angajati.begin(), angajati.end(), criteriu);
    }
    else if(tip==2)
    {
        cout <<"\n\n      Introdu ID:  ";
        string id;
        cin >> id;
        stergere criteriu("ID", id);
        it=find_if(angajati.begin(), angajati.end(), criteriu);
    }
        
        if(it==angajati.end())
            cout << "                       ANGAJATUL NU A FOST GASIT!\n";
        else
        {

            (*it)->afisare();
            if(dynamic_cast<manager*>(*it) && contor_manageri==1)
                cout << "NU PUTETI STERGE MANAGERUL! Magazinul trebuie sa aiba cel putin un manager.\n";
            else
                if(dynamic_cast<operatorr*>(*it) && contor_operatori==3)
                    cout << "NU PUTETI STERGE OPERATORUL! Magazinul trebuie sa aiba minim 3 operatori\n";
                else
                    if(dynamic_cast<asistent*>(*it) && contor_asistenti==1)
                        cout << "NU PUTETI STERGE ASISTENTUL! Magazinul trebuie sa aiba cel putin un asistent.\n";
                    else
                        {
                            cout << "A FOST STERS! \n";
                            angajati.erase(it);
                            cout <<"\n\n      Lista actualizata:  \n";
                            cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';

                            for(auto& at:angajati)
                                at->afisare();

                        }

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
        stergere criteriu("CNP", cnp);
        auto it=find_if(angajati.begin(), angajati.end(), criteriu);
        if(it==angajati.end())
            cout << "                ANGAJATUL NU A FOST GASIT!\n";
        else
            (*it)->afisare();
         
        
    }
    else if(tip==2)
    {
        cout <<"\n\n      Introdu ID:  ";
        string id;
        cin >> id;
        stergere criteriu("ID", id);
        auto it=find_if(angajati.begin(), angajati.end(), criteriu);
        if(it==angajati.end())
            cout << "ANGAJATUL NU A FOST GASIT!\n";
        else
        {
            (*it)->afisare();
        }
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
        string cnp;
        cin >> cnp;
        string nume;
        cout <<"\n\n      Introdu noul Nume:  ";
        cin >> nume;
        if(::validare_cnp(cnp)==0)
            throw invalid_argument("CNP INVALID!!");
        stergere criteriu("CNP", cnp);
        auto it=find_if(angajati.begin(), angajati.end(), criteriu);
        if(it==angajati.end())
            cout << "ANGAJATUL NU A FOST GASIT!\n";
        else
        {
            (*it)->afisare();
            cout << "A FOST REDENUMIT \n";
            (*it)->set_nume(nume);
            cout <<"\n\n      Lista actualizata:  \n";
	cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';

            for(auto& at:angajati)
                at->afisare();
        }
        
    }
    else if(tip==2)
    {
        cout <<"\n\n      Introdu ID:  ";
        string id;
        cin >> id;
        string nume;
        cout <<"\n\n      Introdu noul Nume:  ";
        cin >> nume;
        stergere criteriu("ID", id);
        auto it=find_if(angajati.begin(), angajati.end(), criteriu);
        if(it==angajati.end())
            cout << "ANGAJATUL NU A FOST GASIT!\n";
        else
        {
            (*it)->afisare();
            cout << "A FOST REDENUMIT \n";
            (*it)->set_nume(nume);
            cout <<"\n\n      Lista actualizata:  \n";
	    cout << "---------------------------------------------------------------------------------------------------------------------------" <<'\n';
        
            for(auto& at:angajati)
                at->afisare();
        }
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

                        for(auto& at:angajati)
                            at->afisare();
                    }
    }

}

int main()
{
    try
    {
        populare_angajati();
        ecran_principal_logo();
        //meniu_principal();
        int var;
       // cin >> var;
       // if(var==1)
        //    gestiune_angajati();

        articol_vestimentar a("tricou", 20, 1, "negru", "gucci");
        a.afisare();

    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    
}