#ifndef GENERATOR_H
#define GENERATOR_H

#include <ctime>
#include <map>
#include <memory>
#include <random>
#include "labirint.h"

class labirint;

template<typename T>
class generator {
    labirint &lab;
    std::map<std::pair<int,int>, std::unique_ptr<T>> obiect;
    int nr_obiecte;
public:
    generator(labirint& lab, int nr);
    ~generator() = default;
    void plaseaza_obiecte();
    void sterge_obiecte(int x, int y);
    T* get_obiect(int x, int y);
    bool obiect_in_cale(int x, int y);
};

template<typename T>
generator<T>::generator(labirint& lab, int nr) : lab(lab), nr_obiecte(nr) {}

template<typename T>
void generator<T>::plaseaza_obiecte() {
    int i = 0;
    while (i < nr_obiecte) {
        int new_x = rand() % lab.get_dimensiuni().first;
        int new_y = rand() % lab.get_dimensiuni().second;
        if (lab.drum_liber(new_x, new_y) && lab.drum_liber(new_x, new_y + 1) && lab.drum_liber(new_x, new_y - 1)) {
            auto ob = std::make_unique<T>();
            ob->set_pozitie(new_x, new_y);
            lab.get_harta()[new_x][new_y] = ob->print_caracter();
            obiect[{new_x, new_y}] = std::move(ob);
            i++;
        }
    }
}

template<typename T>
void generator<T>::sterge_obiecte(int x, int y) {
    obiect.erase({x, y});
    lab.get_harta()[x][y] = '_';
}

template<typename T>
T* generator<T>::get_obiect(int x, int y) {
    auto it = obiect.find({x, y});
    if (it != obiect.end())
        return it->second.get();
    return nullptr;
}

template<typename T>
bool generator<T>::obiect_in_cale(int x, int y) {
    return get_obiect(x, y) != nullptr;
}

template<typename T, typename Baza>
int numara_obiecte(const std::vector<std::shared_ptr<Baza>>& obiecte) {
    int nr = 0;
    for (auto& ob : obiecte) {
        if (std::dynamic_pointer_cast<T>(ob))
            nr++;
    }
    return nr;
}

#endif
