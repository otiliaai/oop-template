#ifndef INVENTAR_H
#define INVENTAR_H
#include <vector>
#include "diamant.h"
#include "memory"
#include "inamic.h"
#include "ex_insuficiente_sabii.h"
#include "ex_bani.h"
#include "obiect_aparare.h"
#include "potiune.h"
#include <windows.h>
class inventar {
    static int comoara ;
    std::vector<std::shared_ptr<obiect_aparare>> defense;

public:
    void afisare() const;
    static void verifica_cont( int suma = 200);
    void afis_cont();

    inventar& operator+=(const diamant& d);

    void adauga_obiect(std::shared_ptr<obiect_aparare> ob);
    void sterge_obiect(std::shared_ptr<obiect_aparare> ob);
    void afisare_obiecte_aparare();
    std::vector<std::shared_ptr<obiect_aparare>> get_vector();

    int numar_sabii() const;
    int numar_scuturi() const;
    int numar_potiuni () const;
    bool suficiente(std::shared_ptr<obiect_aparare>& ob);


};
#endif //INVENTAR_H
