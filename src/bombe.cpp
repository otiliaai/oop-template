#include "bombe.h"
#include "jucator.h"
bombe::bombe() {
  this->simbol = '@';
  this->dauna = 40;
}

int bombe::get_dauna() const {
  return this->dauna;
}

void bombe::explodeaza(jucator& j) {
  j.set_viata(j.get_viata()-90);
}

void bombe::impact_jucator(jucator& j) const {
  explodeaza(j);
}

