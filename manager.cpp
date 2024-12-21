#include "manager.h"

manager::manager():angajat()
{

}
manager::manager(const string& num,const string &prenum,const string& CNP, tm& data): angajat(num, prenum, CNP, data)
{

}

float manager:: calcul_salariu() const
{
    return (3500+100*ani_experienta())*1.25;
}

void manager:: afisare() const
{
    cout << "Managerul: " << endl;
    angajat::afisare();
}

manager::~manager()
 {

}