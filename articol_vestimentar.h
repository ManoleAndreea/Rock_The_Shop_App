#include "produs.h"

class articol_vestimentar: public produs
{
    string culoare;
    string marca;

    public:
        articol_vestimentar();
        articol_vestimentar(const string&, float, int, const string&, const string&);
        float calcul_pret_final() const;
        void afisare() const;
        articol_vestimentar* copie() const;
};