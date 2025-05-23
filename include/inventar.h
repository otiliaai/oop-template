#ifndef INVENTAR_H
#define INVENTAR_H
#include <vector>
#include "diamant.h"
#include "memory"
#include "ex_bani.h"
#include "obiect_aparare.h"
class inventar {
    static int comoara ;
    std::vector<std::shared_ptr<obiect_aparare>> defense;

public:
    void afisare() const;
    static void verifica_cont( int suma = 200);

    inventar& operator+=(const diamant& d);

    void adauga_obiect(const std::shared_ptr<obiect_aparare> &ob);
    void sterge_obiect(std::shared_ptr<obiect_aparare>& ob);
    void afisare_obiecte_aparare() const;
    std::vector<std::shared_ptr<obiect_aparare>> get_vector();

    static int introdu_cantitate();

    int numar_sabii() const;
    int numar_scuturi() const;
    int numar_potiuni () const;
    bool suficiente(const std::shared_ptr<obiect_aparare>& ob) const;

    std::shared_ptr<obiect_aparare> gaseste_obiect(const std::type_info& tip);


};
#endif //INVENTAR_H
