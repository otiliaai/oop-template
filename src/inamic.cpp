#include "inamic.h"

inamic::inamic() : caracter(){
    this->viata = 70;
   this->simbol = 'E';
}

// void inamic::caracter_pozitie( int pos_x, int pos_y)  {
//     this->x = pos_x;
//     this->y = pos_y;
// }
std::pair<int,int > inamic::get_pozitie() {
    return std::pair<int,int>(this->x,this->y);
}

int inamic::get_viata() const{
    return this->viata;
}

void inamic::damage(caracter& c) {
    c.set_viata(20);
}