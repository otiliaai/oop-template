#include "jucator.h"

jucator::jucator() : caracter(1,1,100) {
    this->simbol = 'P';
};

std::pair<int,int> jucator::get_pozitie() const {
    return {this->x,this->y};
}

void jucator::set_pozitie(int pos_x, int pos_y) {
    this->x=pos_x;
    this->y=pos_y;
};

void jucator::caracter_pozitie( int pos_x, int pos_y) {
    this->x=pos_x;
    this->y=pos_y;
}
char jucator::print_jucator() const {
    return this->simbol;
}