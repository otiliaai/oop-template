#include "inamic.h"

inamic::inamic() : caracter(){
    this->viata = 70;
   this->simbol = 'E';
}

std::pair<int,int > inamic::get_pozitie() {
    return std::pair<int,int>(this->x,this->y);
}

// int inamic::get_viata() const{
//     return this->viata;
// }

void inamic::damage(caracter& c) {
    c.set_viata(c.get_viata()-50);
}