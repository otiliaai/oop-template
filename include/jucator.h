#ifndef JUCATOR_H
#define JUCATOR_H
#include "caracter.h"
#include "labirint.h"
#include "ex_viata.h"
class jucator :public caracter{

public:
    jucator();
    std::pair<int,int> get_pozitie() const;
    void caracter_pozitie( int pos_x, int pos_y) override;
    jucator& operator=(const jucator& j);
    jucator& operator-(const inamic& i);
    jucator& operator+(const inamic& i);
    int get_viata(); //exemplu didactic de setrs!!!!!!!!!!!!
    void verifica_viata();
    void afis_viata();
    char get_simbol();
};


#endif //JUCATOR_H
