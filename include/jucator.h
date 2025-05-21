#ifndef JUCATOR_H
#define JUCATOR_H
#include "caracter.h"
#include "labirint.h"
#include "inamic.h"
#include "ex_viata.h"
class bombe;



class jucator :public caracter{

public:
    jucator();
    std::pair<int,int> get_pozitie() const;
    void caracter_pozitie( int pos_x, int pos_y) override;
    jucator& operator=(const jucator& j);
    jucator& operator-(const inamic& i);
    jucator& operator-(const bombe& b);
    jucator& operator+(const inamic& i);
    int get_viata() const;
    void verifica_viata();
    void afis_viata() const;
    char get_simbol() const;
    void set_viata(int v);
};


#endif //JUCATOR_H
