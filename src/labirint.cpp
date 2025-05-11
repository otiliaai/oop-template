#include "labirint.h"
#include <algorithm>
#include <random>
#include <ctime>

labirint::labirint(int lungime, int latime) : lungime(lungime), latime(latime), inamici(*this,12),diamante(*this,15){
    if (lungime % 2 == 0) lungime++;
    if (latime % 2 == 0) latime++;
    harta.resize(lungime, std::vector<char>(latime, '#'));
    generare_labirint(1,1);
    harta[1][1]='P';
    harta[lungime-2][latime-2]='X';
    inamici.plaseaza_obiecte();
    diamante.plaseaza_obiecte();
}

labirint::~labirint() = default;

void labirint::generare_labirint(int x, int y) {
    harta[x][y]='_';
    std::vector<std::pair<int ,int>>
    directii = {{0,2},{0,-2}, {-2,0},{2,0}};

    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    std::shuffle(directii.begin(), directii.end(), rng);

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
        for (auto& j : i)
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

void labirint::ajusteaza_harta(labirint& l,char p,int x_vechi,int y_vechi,int x_nou,int y_nou) {
    l.harta[x_nou][y_nou] = p;
    l.harta[x_vechi][y_vechi] = '_';
}

std::vector<std::vector<char>>& labirint::get_harta() {
    return this->harta;
}

generator<inamic>& labirint::get_inamic() {
    return this->inamici;
}

generator<diamant>& labirint::get_diamant() {
    return this->diamante;
}