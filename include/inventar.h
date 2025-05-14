#ifndef INVENTAR_H
#define INVENTAR_H
#include <vector>
#include "diamant.h"
#include "inamic.h"
#include "ex_insuficiente_sabii.h"
#include "ex_bani.h"
class inventar {
    static int comoara ;
    static int sabie;

public:

    static void adauga_sabie() ;
    static void scade_sabie();
    int get_sabii() const;
    static void verifica_cont( int suma = 200);
    static void verifica_sabii();
    void afis_cont();
    void afis_sabii();

    inventar& operator+=(const diamant& d);


};
#endif //INVENTAR_H
