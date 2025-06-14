#ifndef LABIRINT_H
#define LABIRINT_H

#include <vector>
#include <memory>
#include "bombe.h"
#include "caracter.h"
#include "inamic.h"


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

public:
    labirint(int lungime, int latime);
    ~labirint();
    void generare_labirint(int x, int y);
    labirint(const labirint& lab) =  delete;
    labirint& operator=(const labirint& lab) = delete;

    void afiseaza() const;
    bool valid(int x, int y) const;
    std::pair<int,int> get_dimensiuni() const;
    bool drum_liber(int x, int y) const;

    void ajusteaza_harta(caracter& p, int x_vechi, int y_vechi, int x_nou, int y_nou);
    std::vector<std::vector<char>>& get_harta();

    int spatiu() const;

    generator<inamic>& get_inamic() const;
    generator<diamant>& get_diamant() const;
    generator<bombe>& get_bomba() const;
};

#endif // LABIRINT_H
