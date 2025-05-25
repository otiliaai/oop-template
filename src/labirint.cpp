#include "labirint.h"
#include <algorithm>
#include <random>
#include <ctime>
#include "diamant.h"
#include "generator.h"
#include <iostream>

void labirint::generare_labirint(int x, int y) {
    harta[x][y]='_';
    std::vector<std::pair<int ,int>>
    directii = {{0,2},{0,-2}, {-2,0},{2,0}};

    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    std::ranges::shuffle(directii, rng);

    for (const auto& directie: directii) {
        int dx = directie.first;
        int dy = directie.second;
        //coordonatele noii celule
        int xx = x + dx;
        int yy = y + dy;
        if (valid(xx,yy)) {
            harta[xx][yy]='_';
            harta[x + dx / 2][y + dy / 2] = '_';
            generare_labirint(xx,yy);
        }

    }

}

void labirint::afiseaza() const {
    for (const auto& i : harta) {
        for (const auto& j : i)
            std::cout << j;
        std::cout << '\n';
    }
}

bool labirint::valid(int x, int y) const {
    return  x > 0 && x < lungime && y > 0 && y < latime && harta[x][y] == '#';
}

std::pair<int,int> labirint::get_dimensiuni() const {
  return {this->lungime,this->latime} ;
}

bool labirint::drum_liber(int x, int y) const {
    return harta[x][y]=='_' || harta[x][y]=='X';
}

void labirint::ajusteaza_harta(caracter& p, int x_vechi, int y_vechi, int x_nou, int y_nou) {
    p.set_pozitie(x_nou, y_nou);
    this->harta[x_nou][y_nou] = p.print_caracter();
    this->harta[x_vechi][y_vechi]='_';
}


std::vector<std::vector<char>>& labirint::get_harta() {
    return this->harta;
}

int labirint::spatiu() const{
    int nr = 0;
    for (const auto& i :  harta) {
        for (const auto& j : i) {
            if (j == '_')
                nr++;
        }
    }
    return nr;
}

labirint::labirint(int lungime, int latime) : lungime(lungime), latime(latime) {
    if (lungime % 2 == 0) lungime++;
    if (latime % 2 == 0) latime++;
    harta.resize(lungime, std::vector<char>(latime, '#'));
    generare_labirint(1,1);
    harta[1][1] = 'P';
    harta[lungime-2][latime-2] = 'X';

    inamici = new generator<inamic>(*this, int(sqrt(spatiu())));
    diamante = new generator<diamant>(*this, int(sqrt(spatiu())));
    bomba = new generator<bombe>(*this, int(sqrt(spatiu()))/2);

    inamici->plaseaza_obiecte();
    diamante->plaseaza_obiecte();
    bomba->plaseaza_obiecte();
}

labirint::~labirint() {
    delete inamici;
    delete diamante;
    delete bomba;
}

generator<inamic>& labirint::get_inamic() const {
    return *inamici;
}

generator<diamant>& labirint::get_diamant() const {
    return *diamante;
}

generator<bombe>& labirint::get_bomba() const {
    return *bomba;
}


