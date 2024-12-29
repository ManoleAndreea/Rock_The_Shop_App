#include "disc.h"

class disc_vintage: public disc
{
    bool mint;
    int coeficient_raritate;

    public:
        disc_vintage();
        disc_vintage(const string&, float, int, const string&, const string&, const string&, const string&, tm&, bool, int);
        float calcul_pret_final() const;
        void afisare() const;
};