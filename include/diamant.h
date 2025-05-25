#ifndef DIAMANT_H
#define DIAMANT_H
#include "obiect_labirint.h"

class jucator;

class diamant : public obiect_labirint{
    static int valoare;
public:
    diamant();
    [[nodiscard]] int get_valoare() const;

    void impact_jucator(jucator& j)const  override;

};
#endif //DIAMANT_H
