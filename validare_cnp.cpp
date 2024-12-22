#include "validare_cnp.h"


bool validare_cnp(const string & c)
{
    if(c.length()!=13)
        return false;

    for(int i=0; i<c.length(); i++)
        if(!std::isdigit(c[i]))
            return false;

    int constanta[12]={2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9};
    int suma=0;
    for(int i=0; i<12; i++)
        suma+=(c[i]-'0')*constanta[i];

    int verificare=suma%11;
    if(verificare>10)
        verificare=1;

    return verificare==c[12]-'0';
}
