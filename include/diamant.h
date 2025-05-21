#ifndef DIAMANT_H
#define DIAMANT_H
#include "obiect_labirint.h"

class diamant : public obiect_labirint{
    static int valoare;
public:
    diamant();
    [[nodiscard]] char print_caracter() const override;
    [[nodiscard]] int get_valoare() const;

};
#endif //DIAMANT_H
