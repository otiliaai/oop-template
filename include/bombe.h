#ifndef BOMBE_H
#define BOMBE_H
#include "obiect_labirint.h"
#include "jucator.h"

class jucator;

class bombe: public obiect_labirint {
  int dauna;
  public:
    bombe();
    ~bombe() override = default;
    [[nodiscard]] int get_dauna() const;
    [[nodiscard]] char print_caracter() const override;

  static void explodeaza(jucator& j);

};
#endif //BOMBE_H
