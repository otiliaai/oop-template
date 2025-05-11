#include "diamant.h"
int diamant::valoare = 100;

diamant::diamant() {
   this->simbol = '*';
}
char  diamant::print_caracter() const {
   return this->simbol;
}
int diamant::get_valoare() const {
   return this->valoare;
}