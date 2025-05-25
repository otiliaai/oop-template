#include "potiune.h"

potiune::potiune():obiect_aparare(100,150){};

int potiune::calc_putere() const{
  return this->putere-20;
}
