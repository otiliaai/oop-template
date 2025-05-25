#include "inamic.h"

inamic::inamic() : caracter(){
    this->viata = 70;
   this->simbol = 'E';
}

std::pair<int,int > inamic::get_pozitie() {
    return std::pair<int,int>(this->x,this->y);
}

void inamic::damage(caracter& c) {
    c.set_viata(c.get_viata()-70);
}