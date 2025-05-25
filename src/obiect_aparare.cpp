#include "obiect_aparare.h"

obiect_aparare::obiect_aparare(int,int pret):putere(100),pret(pret){}

int obiect_aparare::get_pret() const {
  return this->pret;
}

