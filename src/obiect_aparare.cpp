#include "obiect_aparare.h"

obiect_aparare::obiect_aparare(int putere,int pret):putere(putere),pret(pret){}

int obiect_aparare::get_pret() const {
  return this->pret;
}