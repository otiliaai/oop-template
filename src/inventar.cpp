#include "inventar.h"

#include <conio.h>
#include <ex_viata.h>

int inventar::sabie = 1;
int inventar::comoara = 500;

void inventar::adauga_sabie() {
    sabie++;
    comoara-=500;
}

void inventar::scade_sabie() {
    sabie--;
}

int inventar::get_sabii() const {
    return this->sabie;
}

void inventar::verifica_cont(int suma) {
    if (comoara-suma<0)
        throw ex_bani("\nNU AI SUFICIENTI BANI.\nSold: ");
}

void inventar::verifica_sabii() {
    if (sabie == 0)
        throw ex_insuficiente_sabii("\nNu ai suficiente sabii! ");
}

inventar& inventar::operator+=(const diamant& d) {
    this->comoara+=d.get_valoare();
    return *this;
}
void inventar::afis_cont() {
    std::cout<<"\nCONT: "<<this->comoara;
}
void inventar::afis_sabii() {
    std::cout<<"\nNR_SABII: "<<this->sabie;
}



