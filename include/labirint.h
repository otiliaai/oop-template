#ifndef LABIRINT_H
#define LABIRINT_H

#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <memory>
#include "bombe.h"

class inamic;
class diamant;
class caracter;
class bombe;

template<typename T>
class generator;

class labirint {
    std::vector<std::vector<char>> harta;
    const int lungime, latime;

    generator<inamic>* inamici;
    generator<diamant>* diamante;
    generator<bombe>* bomba;

    void generare_labirint(int x, int y);

public:
    labirint(int lungime, int latime);
    ~labirint();

    void afiseaza() const;
    bool valid(int x, int y) const;
    std::pair<int,int> get_dimensiuni() const;
    bool drum_liber(int x, int y) const;

    void ajusteaza_harta(caracter& p, int x_vechi, int y_vechi, int x_nou, int y_nou);
    std::vector<std::vector<char>>& get_harta();

    generator<inamic>& get_inamic();
    generator<diamant>& get_diamant();
    generator<bombe>& get_bomba();
};

#endif // LABIRINT_H
