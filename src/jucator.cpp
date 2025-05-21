#include "jucator.h"

jucator::jucator() : caracter(1,1,100) {
    this->simbol = 'P';
};

std::pair<int,int> jucator::get_pozitie() const {
    return {this->x,this->y};
}

void jucator::caracter_pozitie( int pos_x, int pos_y) {
    this->x=pos_x;
    this->y=pos_y;
}


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

jucator& jucator::operator-(const bombe& b) {
    this->viata-=b.get_dauna();
    return *this;
}

jucator& jucator::operator+(const inamic& i) {
    this->viata+=i.get_viata();
    return *this;
}
int jucator::get_viata() const {
    return this->viata;
}

void jucator::afis_viata() const {
    std::cout << "\nVIATA: "<<this->viata<<"\n";
}


void jucator::verifica_viata() {
    if (this->viata <0)
        throw ex_viata("\nNu mai ai viata! Nu mai poti lupta cu inamicii!");
    else if (this->viata >100)
        this->viata=100;
}

char jucator::get_simbol() const {
    return this->simbol;
}

void jucator::set_viata(int v) {
    this->viata+=v;
    verifica_viata();
}