#ifndef DIAMANT_H
#define DIAMANT_H
#include "inamic.h"
class diamant : public inamic{
    static int valoare;
public:
    diamant();
    char print_caracter() const;
    int get_valoare() const;

};
#endif //DIAMANT_H
