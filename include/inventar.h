#ifndef INVENTAR_H
#define INVENTAR_H
#include <vector>
#include "diamant.h"
class inventar {
    static int comoara ;
    std::vector<diamant> diamante;
public:
    inventar();
    void adaugaDiamant(const diamant& d);
    int operator+=(const diamant& od);
};
#endif //INVENTAR_H
