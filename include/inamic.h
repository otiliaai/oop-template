//
// Created by ionel on 02.05.2025.
//

#ifndef INAMIC_H
#define INAMIC_H
#include "caracter.h"

class inamic :public caracter{

public:
    inamic();
    void caracter_pozitie( int pos_x, int pos_y) override;
    std::pair<int,int > get_pozitie();
    int get_viata() const;
};

#endif //INAMIC_H
