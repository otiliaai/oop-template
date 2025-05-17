#include "inventar.h"
#include <conio.h>
#include <ex_viata.h>
#include "obiect_aparare.h"
#include "sabie.h"
#include "scut.h"
#include <algorithm>

#include "generator.h"

int inventar::comoara = 500;

void inventar::afisare() const {
    std::cout <<"====INVENTAR=====" << std::endl;
    std::cout<<"Sabii (100$): "<<this->numar_sabii()<<"\n";
    std::cout<<"Scuturi (150$): "<<this->numar_scuturi()<<"\n";
    std::cout<<"Potiuni (150$): "<<this->numar_potiuni()<<"\n";
    std::cout<<"Bani: "<<this->comoara<<"$\n";

}


void inventar::verifica_cont(int suma) {
    if (comoara-suma<0) {
        throw ex_bani("\nNU AI SUFICIENTI BANI.\n");
    }
}

inventar& inventar::operator+=(const diamant& d) {
    this->comoara+=d.get_valoare();
    return *this;
}
void inventar::afis_cont() {
    std::cout<<"\nCONT: "<<this->comoara;
}

void inventar::afisare_obiecte_aparare() {
    for (auto& i : defense)
        std::cout<<i->get_putere()<<" ";
}

std::vector<std::shared_ptr<obiect_aparare>> inventar::get_vector() {
    return this->defense;
}
///upcasting
void inventar::adauga_obiect(std::shared_ptr<obiect_aparare> ob) {
    try {
        verifica_cont(ob->get_pret());
        this->defense.push_back(ob);
        this->comoara-=ob->get_pret();
    }
    catch (const ex_bani& e) {
        std::cout<<e.what()<<"\n";
        Sleep(1000);
    }

}

void inventar::sterge_obiect(std::shared_ptr<obiect_aparare> ob) {
    auto it = std::remove_if(defense.begin(), defense.end(),
        [&ob](const std::shared_ptr<obiect_aparare>& ptr) {
            return ptr == ob;
        });
    defense.erase(it, defense.end());
}

///downcasting
int inventar::numar_sabii() const {
    return numara_obiecte<sabie>(defense);
}

int inventar::numar_scuturi() const{
    return numara_obiecte<scut>(defense);
}

int inventar::numar_potiuni() const {
    return numara_obiecte<potiune>(defense);
}


bool inventar::suficiente(std::shared_ptr<obiect_aparare> &ob) {
    if (auto ptr = std::dynamic_pointer_cast<scut>(ob))
        return this->numar_scuturi()>0;
    else
        if (auto ptr = std::dynamic_pointer_cast<sabie>(ob))
            return this->numar_sabii()>0;
    else
        if (auto ptr = std::dynamic_pointer_cast<potiune>(ob))
            return this->numar_potiuni()>0;

    return false;
}

std::shared_ptr<obiect_aparare> inventar::gaseste_obiect(const std::type_info& tip) {
    for (auto& i : defense)
        if (typeid(*i) == tip)
            return i;
    return nullptr;
}


