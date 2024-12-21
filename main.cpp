#include "manager.h"
#include "operatorr.h"
#include "asistent.h"
#include <fstream>
#include <vector>

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

void gestiune_angajati()
{
    cout << " \n\n       Doresti sa:\n\n      - Adaugi(1) un nou angajat?\n      - Sa stergi(2) un angajat?\n      - Sa modifici(3) un angajat?\n      - Sau sa aflii mai multe detalii(4) despre un angajat?\n      - Poate doresti sa vezi lista(5) cu toti angajatii inregistrati la Rock the Shop?\n";
}

int main()
{
    try
    {
        populare_angajati();
        ecran_principal_logo();
        meniu_principal();
        int var;
        cin >> var;
        if(var==1)
            gestiune_angajati();


    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    
}