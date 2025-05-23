#ifndef INAMIC_H
#define INAMIC_H
#include "caracter.h"

class inamic :public caracter{

public:
    inamic();
    //void caracter_pozitie( int pos_x, int pos_y) override;
    void damage(caracter& c) override;
    std::pair<int,int > get_pozitie();
    int get_viata() const override;
};

#endif //INAMIC_H
