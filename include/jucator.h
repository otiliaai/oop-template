#ifndef JUCATOR_H
#define JUCATOR_H
#include "caracter.h"
#include "labirint.h"

class jucator :public caracter{

public:
    jucator();
    std::pair<int,int> get_pozitie() const;
    void set_pozitie(int pos_x, int pos_y);
    void caracter_pozitie( int pos_x, int pos_y);
    char print_jucator() const;

};


#endif //JUCATOR_H
