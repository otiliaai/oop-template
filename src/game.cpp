#include "game.h"
#include <conio.h>
#include "sabie.h"
#include "scut.h"
#include "obiect_aparare.h"
#include "generator.h"
#include "ex_insuficiente.h"
#include "potiune_factory.h"
#include "windows.h"
game* game::instance = nullptr;

game* game::get_instance() {
    if (instance == nullptr) {
        instance = new game();
    }
    return instance;
}

game::game() :lab(15,35){
    this->running = true;
}

bool game::pozitie_valida(const labirint &lab, int x, int y) {
    int lng = lab.get_dimensiuni().first;
    int lat = lab.get_dimensiuni().second;
    return  x > 0 && x < lng && y > 0 && y < lat && lab.drum_liber(x,y);
}

void game::run() {
    cumpara_obiecte();
    while (running) {
        //system("cls");
        inv.afisare();
        j.afis_viata();
        lab.afiseaza();
        actualizeaza_harta();
        verifica_status();
    }
}

void game::actualizeaza_harta() {
    int x_vechi = j.get_pozitie().first;
    int y_vechi = j.get_pozitie().second;

    int x_nou = x_vechi;
    int y_nou = y_vechi;

    int key = _getch();

    if (key == 224) {
        key = _getch();

        switch (key) {
            case 72: x_nou -= 1; break;
            case 80: x_nou += 1; break;
            case 75: y_nou -= 1; break;
            case 77: y_nou += 1; break;
            default: std::cout<<"Ai apasat o tasta gresita!";
        }
    }

    if (pozitie_valida(lab, x_nou, y_nou)) {
        j.set_pozitie(x_nou, y_nou);
        lab.ajusteaza_harta(j, x_vechi, y_vechi, x_nou, y_nou);
    } else {
        if (lab.get_inamic().obiect_in_cale(x_nou, y_nou))
            lupta_cu_inamicul(x_nou, y_nou);
        if (lab.get_diamant().obiect_in_cale(x_nou, y_nou))
            colecteaza_diamant(x_nou, y_nou);
        if (lab.get_bomba().obiect_in_cale(x_nou, y_nou))
            depaseste_bomba(x_nou, y_nou);
    }

}
void game::verifica_status() {
    if (j.get_pozitie().first==lab.get_dimensiuni().first-2 && j.get_pozitie().second==lab.get_dimensiuni().second-2) {
        //system("cls");
        std::cout<<"AI CASTIGAT JOCUL";
        running = false;
    }
}


 void game::lupta_cu_inamicul(int x, int y) {

     char optiune;
     bool inamic_viu = true;
     const inamic* p = lab.get_inamic().get_obiect(x, y);

     if (p == nullptr) return;

     while (inamic_viu) {
         //system("cls");
         inv.afisare();
         lab.afiseaza();
         j.afis_viata();
         std::cout << "\nAi in cale un inamic. Alege ce vrei sa faci in continuare: \n'l' - lupta\n'c' - continua fara lupta\n";
         std::cout<<"\nOptiune: ";
         std::cin >> optiune;
         bool alegere = true;
         char op;
         switch (optiune) {
             case 'l': {
                 while (alegere) {
                     //system("cls");
                     inv.afisare();
                     lab.afiseaza();
                     j.afis_viata();
                     std::cout<<"\n1. Foloseste sabia\n2. Actualizeaza inventarul\nOptiune: ";
                     std::cin>>op;

                     switch (op) {

                         case '1': {
                             auto s = inv.gaseste_obiect(typeid(sabie));
                             if (inv.suficiente(s)) {
                                 inv.sterge_obiect(s);
                                 j.set_viata(s->calc_putere());
                                 inamic_viu = false;
                                 lab.get_inamic().sterge_obiecte(x, y);
                                 lab.ajusteaza_harta(j, j.get_pozitie().first, j.get_pozitie().second, x, y);
                             } else {
                                 std::cout<<"\nNU AI SUFICIENTE SABII !!!\n";
                                // Sleep(1000);
                             }
                             alegere = false;
                             break;
                         }

                         case '2': {
                             //system("cls");
                             cumpara_obiecte();
                             break;
                         }

                         default: {
                             std::cout<<"Ai apasat o tasta gresita. Incearca din nou";
                             //Sleep(1000);
                         }

                     }
                 }
                 break;
             }
             case 'c': {
                 bool f = true;
                 while (alegere) {
                     //system("cls");
                     inv.afisare();
                     lab.afiseaza();
                     j.afis_viata();
                     std::cout<<"\nIn continuare ai doua optiuni: \n1. Continua si pierde 70% din viata ta"
                   "\n2. Bea o potiune pentru a castiga mai multa viata\n3. Actualizeaza inventarul\nOptiune: ";
                     std::cin >> op;

                     switch (op) {

                         case '1': {
                             try {
                                 j = j - (*p);
                                 j.verifica_viata();
                             }
                             catch (const ex_viata& e) {
                                 std::cout<<e.what()<<"\n";
                                 game_over();
                             }
                             f = false;
                             alegere = false;
                             break;
                         }

                         case '2': {
                             auto pn = inv.gaseste_obiect(typeid(potiune));
                             try {
                                 if (inv.suficiente(pn)) {
                                     inv.sterge_obiect(pn);
                                     j.set_viata(pn->calc_putere());
                                 }
                                 else throw ex_insuficiente("INSUFICIENTE!");
                             }
                             catch (const ex_insuficiente& e){
                                 std::cout<<e.what()<<"\n";
                                 //Sleep(1000);
                             }
                             alegere = false;
                             break;
                         }


                         case '3': {
                             //system("cls");
                             cumpara_obiecte();
                             break;
                         }

                         default: {
                             std::cout<<"Ai apasat o tasta gresita. Incearca din nou";
                             //Sleep(1000);
                         }
                     }
                 }
                 if (!f) {
                     inamic_viu = false;
                     lab.get_inamic().sterge_obiecte(x, y);
                     lab.ajusteaza_harta(j, j.get_pozitie().first, j.get_pozitie().second, x, y);
                 }
                 break;
             }
             default: {
                 std::cout<< "Ai apasat o tasta gresita";
                 //Sleep(1000);
             }
         }
     }

}

void game::colecteaza_diamant(int x,int y) {
    const diamant* d = lab.get_diamant().get_obiect(x,y);
    if (!d) return;
    inv+=(*d);
    lab.get_diamant().sterge_obiecte(x,y);
    std::pair<int,int> poz = j.get_pozitie();
   lab.ajusteaza_harta(j,poz.first,poz.second,x,y);
}


void game::game_over() {
   // system("cls");
    std::cout<<"\nGAME OVER!"<<std::endl;
    this->running = false;
}

inventar &game::get_inventar() {
    return this->inv;
}

void game::cumpara_obiecte() {

    char optiune;

    bool cumparare = true;
    while (cumparare) {
        //system("cls");
        inv.afisare();
        j.afis_viata();
        std::cout<<"\nCUMPARA:\n";
        std::cout<<"1. Sabie - 100$\n";
        std::cout<<"2. Scut - 150$\n";
        std::cout<<"3. Potiune - 150$\n";
        std::cout<<"4. Am terminat!\n";
        std::cout<<"\nOptiune: ";
        std::cin>>optiune;

        switch (optiune) {
            case '1': {
                inv.adauga_obiect(std::make_shared<sabie>());
                break;
            }
            case '2': {
                inv.adauga_obiect(std::make_shared<scut>());
                break;
            }
            case '3': {
                inv.adauga_obiect(std::make_shared<potiune>());
                break;
            }
            case '4': {
                //system("cls");
                std::cout<<"\nAi actualizati inventarul cu succes!\n";
               // Sleep(1000);
                cumparare = false;
                break;
            }
            default: {
                std::cout<<"Ai apasat o tasta gresita. Incearca din nou";
               // Sleep(1000);
            }
        }
    }
}

jucator& operator+(jucator& j, const obiect_aparare& ob) {
    j.set_viata(j.get_viata()+(100-ob.calc_putere()));
    return j;
}

void game::depaseste_bomba(int x,int y) {
    const bombe* b = lab.get_bomba().get_obiect(x,y);
    if (b == nullptr) return;
    bool alegere = true;
    char ch;
    while (alegere) {
        //system("cls");
        inv.afisare();
        lab.afiseaza();
        j.afis_viata();
        std::cout<<"\nAi o bomba in cale. Daca continui sa mergi, bomba explodeaza. Poti diminua efectele asupra vietii "
               "folosind un scut.\n1. Continua\n2. Foloseste scut\n3. Actualizeaza inventar\nOptiune: ";
        std::cin>>ch;
        switch (ch) {

            case '1': {
                b->explodeaza(j);
                game_over();
                alegere = false;
                break;
            }

            case '2' : {
                try {
                    auto s = inv.gaseste_obiect(typeid(scut));
                    if (inv.suficiente((s))) {
                        j = j-(*b);
                        inv.sterge_obiect(s);
                        lab.get_bomba().sterge_obiecte(x, y);
                        lab.ajusteaza_harta(j, j.get_pozitie().first, j.get_pozitie().second, x, y);
                        alegere = false;
                    } else throw ex_insuficiente("Insuficiente scuturi");
                }
                catch (const std::exception& e) {
                    std::cout<<e.what();
                    //Sleep(1000);
                }
                break;
            }
            case '3': {
                //system("cls");
                cumpara_obiecte();
                alegere = false;
                break;
            }

            default: {
                std::cout<<"Ai apasat o tasta gresita. Incearca din nou";
                //Sleep(1000);
            }
        }
    }
}
