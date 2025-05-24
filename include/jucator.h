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
    void damage(caracter& c) override;
    jucator& operator=(const jucator& j);
    jucator& operator-(const inamic& i);
    jucator& operator-(const bombe& b);
    jucator& operator+(const inamic& i);
    // int get_viata() const override;
    void verifica_viata();
    void afis_viata() const;

};


#endif //JUCATOR_H
