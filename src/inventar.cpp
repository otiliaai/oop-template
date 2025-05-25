#include "inventar.h"
#include <ex_viata.h>
#include "obiect_aparare.h"
#include "sabie.h"
#include "scut.h"
#include <algorithm>
#include "potiune.h"
#include "generator.h"
#include <iostream>


int inventar::comoara = 500;

void inventar::afisare() const {
    std::cout <<"\n====INVENTAR=====\n" << std::endl;
    std::cout<<"Sabii (100$): "<<this->numar_sabii()<<"\n";
    std::cout<<"Scuturi (150$): "<<this->numar_scuturi()<<"\n";
    std::cout<<"Potiuni (150$): "<<this->numar_potiuni()<<"\n";
    std::cout<<"Bani: "<<this->comoara<<"$\n";

}


void inventar::verifica_cont(int suma) {
    if (comoara-suma<0)
        throw ex_bani("\nNU AI SUFICIENTI BANI.\n");
}

inventar& inventar::operator+=(const diamant& d) {
    this->comoara+=d.get_valoare();
    return *this;
}

// int inventar::introdu_cantitate() {
//     int cantitate = 0;
//     std::cout<<"Cantitate: ";
//     std::cin>>cantitate;
//     return cantitate;
// }
int inventar::introdu_cantitate() {
    long long val;
    std::string line;
    int greseli = 0;

    while (greseli < 3) {
        std::cout << "Cantitate: ";
        std::getline(std::cin, line);
        std::cout << "[DEBUG] Input: " << line << "\n";

        try {
            val = std::stoll(line);
            if (val <= 0 || val > 1000000) {
                std::cout << "Numar invalid (max 1.000.000). Incearca din nou.\n";
                greseli++;
                continue;
            }
            return static_cast<int>(val);
        }
        catch (...) {
            std::cout << "Input invalid. Te rog introdu un numar valid.\n";
            greseli++;
        }
    }
    std::cout << "Prea multe incercari gresite, cantitate setata la 0.\n";
    return 0;
}
//upcasting
void inventar::adauga_obiect(const std::shared_ptr<obiect_aparare>& ob) {
    int c = introdu_cantitate();
    if (c <= 0) {
        std::cout << "Cantitate invalida, cumparare anulata.\n";
        return;
    }

    int i = 0;
    while (i < c) {
        try {
            verifica_cont(ob->get_pret());

            std::shared_ptr<obiect_aparare> ob_nou;

            if (std::dynamic_pointer_cast<sabie>(ob))
                ob_nou = std::make_shared<sabie>();
            else if (std::dynamic_pointer_cast<scut>(ob))
                ob_nou = std::make_shared<scut>();
            else if (std::dynamic_pointer_cast<potiune>(ob))
                ob_nou = std::make_shared<potiune>();

            if (!ob_nou) {
                std::cout << "Obiect necunoscut, nu poate fi adaugat.\n";
                return;
            }

            this->defense.push_back(ob_nou);
            this->comoara -= ob->get_pret();
            i++;
        }
        catch (const ex_bani& e) {
            std::cout << e.what() << "\n";
            break;
        }
    }
}

void inventar::sterge_obiect(std::shared_ptr<obiect_aparare>& ob) {
    const auto it = std::ranges::remove_if(defense,
        [&ob](const std::shared_ptr<obiect_aparare>& ptr) {
            return ptr == ob;
    }).begin();
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


bool inventar::suficiente(const std::shared_ptr<obiect_aparare> &ob) const {
    if (std::dynamic_pointer_cast<scut>(ob))
        return this->numar_scuturi()>0;
    if (std::dynamic_pointer_cast<sabie>(ob))
        return this->numar_sabii()>0;
    if (std::dynamic_pointer_cast<potiune>(ob))
            return this->numar_potiuni()>0;

    return false;
}

std::shared_ptr<obiect_aparare> inventar::gaseste_obiect(const std::type_info& tip) {
    for (const auto& i : defense) {
        const auto& obj = *i;
        if (typeid(obj) == tip)
            return i;
    }
    return nullptr;

}


