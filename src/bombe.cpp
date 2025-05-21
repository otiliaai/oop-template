#include "bombe.h"

bombe::bombe() {
  this->simbol = '@';
  this->dauna = 40;
}

int bombe::get_dauna() const {
  return this->dauna;
}

char bombe::print_caracter() const {
  return this->simbol;
}

void bombe::explodeaza(jucator& j) {
  j.set_viata(-j.get_viata());
}