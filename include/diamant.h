#ifndef DIAMANT_H
#define DIAMANT_H
#include "inamic.h"
#include "obiect_labirint.h"

class diamant : public obiect_labirint{
    static int valoare;
public:
    diamant();
    char print_caracter() const override;
    int get_valoare() const;

};
#endif //DIAMANT_H
