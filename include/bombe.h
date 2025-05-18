#ifndef BOMBE_H
#define BOMBE_H
#include "obiect_labirint.h"
#include "jucator.h"

class jucator;

class bombe: public obiect_labirint {
  int dauna;
  public:
    bombe();
    ~bombe() = default;
    int get_dauna() const;
    char print_caracter() const override;
    void explodeaza(jucator& j) const;

};
#endif //BOMBE_H
