#ifndef BOMBE_H
#define BOMBE_H
#include "obiect_labirint.h"

class jucator;

class bombe: public obiect_labirint {
  int dauna;
  public:
    bombe();
    ~bombe() = default;
    [[nodiscard]] int get_dauna() const;

    void impact_jucator(jucator& j) const override;

    static void explodeaza(jucator& j);

};
#endif //BOMBE_H
