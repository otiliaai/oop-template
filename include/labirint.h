// #ifndef LABIRINT_H
// #define LABIRINT_H
// #include <vector>
// #include <queue>
// #include <iostream>
// #include <set>
// #include "generator.h"
// #include "inamic.h"
// #include <map>
//
// class labirint {
//     std::vector<std::vector<char>>harta;
//     const int lungime,latime;
//
//     void generare_labirint(int x, int y);
//     std::map<std::pair<int,int>,inamic*> inamici;
//     std::set<std::pair<int,int>>pozitii_inamici;
//
// public:
//     labirint(int lungime,int latime);
//     ~labirint();
//     void afiseaza() const;
//     bool valid(int x, int y) const;
//     std::pair<int,int> get_dimensiuni() const;
//     bool drum_liber(int x, int y) const;
//     void ajusteaza_harta(labirint& l,char p,int x_vechi,int y_vechi,int x_nou,int y_nou);
//     void plaseaza_inamicii();
//     std::set<std::pair<int,int>>get_pozitii_inamici();
//     void sterge_inamic(int x,int y);
//     inamic* get_inamic(int x,int y);
//     std::vector<std::vector<char>> get_harta();
//
//
// };
// #endif //LABIRINT_H
#ifndef LABIRINT_H
#define LABIRINT_H
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include "generator.h"
#include "inamic.h"
#include "diamant.h"
#include <map>

template<typename T>
class generator;


class labirint {
    std::vector<std::vector<char>>harta;
    const int lungime,latime;
//templates
    generator<inamic> inamici;
    generator<diamant> diamante;
    void generare_labirint(int x, int y);
public:
    labirint(int lungime,int latime);
    ~labirint();
    void afiseaza() const;
    bool valid(int x, int y) const;
    std::pair<int,int> get_dimensiuni() const;
    bool drum_liber(int x, int y) const;
    void ajusteaza_harta(labirint& l,char p,int x_vechi,int y_vechi,int x_nou,int y_nou);
    std::vector<std::vector<char>>& get_harta();
    generator<inamic>& get_inamic();
    generator<diamant>& get_diamant();


};
#endif //LABIRINT_H
