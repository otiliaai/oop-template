#ifndef LABIRINT_H
#define LABIRINT_H
#include <vector>
#include <iostream>

class labirint {
    std::vector<std::vector<char>>harta;
    const int latime,lungime;

    void generare_labirint(int x, int y);

public:
    labirint(int lungime,int latime);
    void afiseaza() const;
    bool valid(int x, int y) const;
    std::pair<int,int> get_dimensiuni(labirint& l) const;
    bool drum_liber(labirint& l,int x, int y) const;
    void ajusteaza_harta(labirint& l,char p,int x_vechi,int y_vechi,int x_nou,int y_nou);
};
#endif //LABIRINT_H
