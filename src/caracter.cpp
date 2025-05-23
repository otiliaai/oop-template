#include "caracter.h"

///constructor de initializare
caracter::caracter(): simbol('S') {
    this->x = 0;
    this->y = 0;
    this->viata = 100;
}

///constructor cu parametri
caracter::caracter(char simbol,int x,int y,int viata) {
    this->x=x;
    this->y=y;
    this->viata=viata;
    this->simbol=simbol;
}
///constructor supraincarcat->il voi folosi ptu inamic
caracter::caracter(int x,int y,int viata): simbol('S') {
    this->x = x;
    this->y = y;
    this->viata = viata;
}

///constructor de copiere
caracter::caracter(const caracter& org): simbol(org.simbol) {
    this->x=org.x;
    this->y=org.y;
    this->viata=org.viata;
    this->simbol=org.simbol;
}
///destructor
caracter::~caracter() {
    this->viata=0;
}
///operator =
caracter& caracter::operator=(const caracter& org){
    if (this == &org)
        return *this;
    this->x=org.x;
    this->y=org.y;
    this->viata=org.viata;
    this->simbol=org.simbol;
    return *this;
}

std::istream& operator>>(std::istream &in,caracter& ob) {
    std::cout<<"Introdu coordoantele:un simbol:" <<"\n";
    std::cout<<"Introdu coordoantele: " << "\n";
    in>>ob.x;
    in>>ob.y;
    std::cout<<"Introdu nivelul vietii: " << "\n";
    in>>ob.viata;
    return in;
}
std::ostream& operator<<(std::ostream &out,const caracter& ob) {
    out<<"Simbol: "<<ob.simbol << "\n";
    out<<"Coordonate: ("<<ob.x<<","<<ob.y<<")" << "\n";
    out<<"Viata: "<<ob.viata << "\n";
    return out;
}
/// supraincarea operatorului + pentru a putea aduna
/// viata inamicului la viata jucatorului dupa ce acesta moare
caracter& caracter::operator+(const caracter& ob) {
    this->viata+=ob.viata;
    return  *this;
}

void caracter::set_pozitie(int pos_x, int pos_y) {
    this->x=pos_x;
    this->y=pos_y;
};
char caracter::print_caracter() const {
    return this->simbol;
}

void caracter::set_viata(int v) {
    this->viata=v;
}

int caracter::get_viata() const {
    return this->viata;
}




