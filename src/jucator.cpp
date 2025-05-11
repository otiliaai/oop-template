#include "jucator.h"

jucator::jucator() : caracter(1,1,100) {
    this->simbol = 'P';
};

std::pair<int,int> jucator::get_pozitie() const {
    return {this->x,this->y};
}
//
// void jucator::set_pozitie(int pos_x, int pos_y) {
//     this->x=pos_x;
//     this->y=pos_y;
// };
//
void jucator::caracter_pozitie( int pos_x, int pos_y) {
    this->x=pos_x;
    this->y=pos_y;
}
// char jucator::print_jucator() const {
//     return this->simbol;
// }

jucator& jucator::operator=(const jucator& j) {
    if (this != &j) {
        this->simbol = j.simbol;
        this->x = j.x;
        this->y = j.y;
        this->viata = j.viata;
    }
    return *this;
}

jucator& jucator::operator-(const inamic& i) {
    this->viata-=i.get_viata();
    return *this;
}
jucator& jucator::operator+(const inamic& i) {
    this->viata-=i.get_viata();
    return *this;
}
int jucator::get_viata() {
    return this->viata;
}

void jucator::verifica_viata() {
    if (this->viata <=0)
        throw ex_viata("Nu mai ai viata! ");
}