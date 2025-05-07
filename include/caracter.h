#ifndef CARACTER_H
#define CARACTER_H
#include <iostream>


class caracter {
protected:
    char simbol;
    int x,y;
    int viata;
public:
    caracter();
    caracter(const char simbol,int x,int y,int viata);
    caracter(int x,int y,int viata);
    caracter(const caracter& org);
    virtual ~caracter();

    caracter& operator=(const caracter& org);
    friend std::istream& operator>>(std::istream &in,caracter& ob);
    friend std::ostream& operator<<(std::ostream &out,const caracter& ob);
    caracter& operator+(const caracter& ob);

    virtual void caracter_pozitie( int pos_x, int pos_y) = 0;
};



#endif //CARACTER_H
