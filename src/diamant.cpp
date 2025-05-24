#include "diamant.h"
#include "jucator.h"
int diamant::valoare = 100;

diamant::diamant() {
   this->simbol = '*';
}
int diamant::get_valoare() const {
   return this->valoare;
}

void diamant::impact_jucator(jucator& j) const {
   j.set_viata(j.get_viata() + 10);
}
