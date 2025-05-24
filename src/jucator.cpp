#include "jucator.h"

jucator::jucator() : caracter(1,1,100) {
    this->simbol = 'P';
};

std::pair<int,int> jucator::get_pozitie() const {
    return {this->x,this->y};
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

void jucator::afis_viata() const {
    std::cout << "\nVIATA: "<<this->viata<<"\n";
}


void jucator::verifica_viata() {
    if (this->viata <0)
        throw ex_viata("\nNu mai ai viata! Nu mai poti lupta cu inamicii!");
    if (this->viata >100)
        this->viata=100;
}

void jucator::damage(caracter& c) {
    c.set_viata(0);
}

