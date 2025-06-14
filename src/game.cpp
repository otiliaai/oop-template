#include "game.h"
#include "sabie.h"
#include "scut.h"
#include "obiect_aparare.h"
#include "generator.h"
#include "ex_insuficiente.h"
#include "potiune_factory.h"
#include "sabie_factory.h"
#include "scut_factory.h"
std::unique_ptr<game> game::instance = nullptr;

int game::greseli = 0;

game* game::get_instance() {
    if (instance == nullptr) {
        instance.reset(new game());
    }
    return instance.get();
}

game::game() :lab(15,20){
    this->running = true;
}

void game::run() {
    cumpara_obiecte();
    while (running && greseli < 100) {
        inv.afisare();
        j.afis_viata();
        lab.afiseaza();
        actualizeaza_harta();
    }
}

bool game::pozitie_valida(const labirint &lab, int x, int y) {
    int lng = lab.get_dimensiuni().first;
    int lat = lab.get_dimensiuni().second;
    return  x > 0 && x < lng && y > 0 && y < lat && lab.drum_liber(x,y);
}

void game::actualizeaza_harta() {
    int x_vechi = j.get_pozitie().first;
    int y_vechi = j.get_pozitie().second;

    int x_nou = x_vechi;
    int y_nou = y_vechi;

    char key = '\0';
    std::cin>>key;

        switch (key) {
            case 'w': x_nou -= 1; break;
            case 's': x_nou += 1; break;
            case 'a': y_nou -= 1; break;
            case 'd': y_nou += 1; break;
            default: std::cout<<"\nAi apasat o tasta gresita!\n"; greseli++;
        }

    if (pozitie_valida(lab, x_nou, y_nou)) {
        j.set_pozitie(x_nou, y_nou);
        if (lab.get_harta()[x_nou][y_nou] == 'X')
            std::cout<<"\nAI CASTIGAT JOCUL\n";
        lab.ajusteaza_harta(j, x_vechi, y_vechi, x_nou, y_nou);
    } else {
        if (lab.get_inamic().obiect_in_cale(x_nou, y_nou))
            lupta_cu_inamicul(x_nou, y_nou);
        if (lab.get_diamant().obiect_in_cale(x_nou, y_nou))
            colecteaza_diamant(x_nou, y_nou);
        if (lab.get_bomba().obiect_in_cale(x_nou, y_nou))
            depaseste_bomba(x_nou, y_nou);
    }
    verifica_status();

}
void game::verifica_status() {
    if (j.get_pozitie().first==lab.get_dimensiuni().first-2 && j.get_pozitie().second==lab.get_dimensiuni().second-2) {
        std::cout<<"\n\n\nAI CASTIGAT JOCUL\n";
        running = false;
    }
}


 void game::lupta_cu_inamicul(int x, int y) {

     char optiune;
     bool inamic_viu = true;
    std::shared_ptr<inamic> p = lab.get_inamic().get_obiect(x, y);

     if (p == nullptr) return;

     while (inamic_viu) {
         //system("cls");
         inv.afisare();
         j.afis_viata();
         lab.afiseaza();
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
                     j.afis_viata();
                     lab.afiseaza();
                     std::cout<<"\n1. Foloseste sabia\n2. Actualizeaza inventarul\nOptiune: ";
                     std::cin>>op;

                     switch (op) {

                         case '1': {
                             auto s = inv.gaseste_obiect(typeid(sabie));
                             try {
                                 if (inv.suficiente(s)) {
                                     inv.sterge_obiect(s);
                                     inamic_viu = false;
                                     lab.get_inamic().sterge_obiecte(x, y);
                                     lab.ajusteaza_harta(j, j.get_pozitie().first, j.get_pozitie().second, x, y);
                                     j.set_pozitie(x, y);
                                     verifica_status();
                                 } else  throw ex_insuficiente ("\n======== INSUFICIENTE SABII !!! ======\n");
                             }
                             catch (const std::exception &e) {
                                 std::cout<<e.what();
                             }
                             alegere = false;
                             break;
                         }

                         case '2': {
                             cumpara_obiecte();
                             alegere = false;
                             break;
                         }

                         default: {
                             std::cout<<"\nAi apasat o tasta gresita. Incearca din nou\n";
                         }

                     }
                 }
                 break;
             }
             case 'c': {
                 bool f = true;
                 while (alegere) {
                     inv.afisare();
                     j.afis_viata();
                     lab.afiseaza();
                     std::cout<<"\nIn continuare ai doua optiuni: \n1. Continua si pierde 70% din viata ta"
                   "\n2. Bea o potiune pentru a castiga mai multa viata\n3. Actualizeaza inventarul\nOptiune: ";
                     std::cin >> op;

                     switch (op) {

                         case '1': {
                             try {
                                 p->damage(j);
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
                                     j.set_viata(j.get_viata()+pn->calc_putere());
                                     j.verifica_viata();
                                 }
                                 else throw ex_insuficiente("======== INSUFICIENTE POTIUNI ! ============");
                             }
                             catch (const std::exception& e){
                                 std::cout<<e.what()<<"\n";
                             }
                             alegere = false;
                             break;
                         }


                         case '3': {
                             cumpara_obiecte();
                             alegere = false;
                             break;
                         }

                         default: {
                             std::cout<<"\nAi apasat o tasta gresita. Incearca din nou\n";
                         }
                     }
                 }
                 if (!f) {
                     inamic_viu = false;
                     lab.get_inamic().sterge_obiecte(x, y);
                     lab.ajusteaza_harta(j, j.get_pozitie().first, j.get_pozitie().second, x, y);
                     j.set_pozitie(x,y);
                     verifica_status();
                 }
                 break;
             }
             default: {
                 std::cout<< "\nAi apasat o tasta gresita\n";}
         }
     }

}

void game::colecteaza_diamant(int x,int y) {
    const std::shared_ptr<diamant> d = lab.get_diamant().get_obiect(x,y);
    if (!d) return;
    d->impact_jucator(j);
    j.verifica_viata();
    inv+=(*d);
    lab.get_diamant().sterge_obiecte(x,y);
    std::pair<int,int> poz = j.get_pozitie();
    j.set_pozitie(x,y);
   lab.ajusteaza_harta(j,poz.first,poz.second,x,y);
    verifica_status();
}


void game::game_over() {
    std::cout<<"\nGAME OVER!\n"<<std::endl;
    this->running = false;
}

void game::cumpara_obiecte() {
    std::string optiune;
    bool cumparare = true;
    greseli = 0;

    while (cumparare && greseli < 100) {
        try {
            inv.verifica_cont();
            inv.afisare();
            j.afis_viata();

            std::cout << "\nCUMPARA:\n";
            std::cout << "1. Sabie - 100$\n";
            std::cout << "2. Scut - 150$\n";
            std::cout << "3. Potiune - 150$\n";
            std::cout << "4. Am terminat!\n";
            std::cout << "\nOptiune: ";

            std::getline(std::cin, optiune);
            if (optiune.empty()) {
                std::cout << "\nOptiune invalida. Incearca din nou.\n";
                greseli++;
                continue;
            }
            switch (optiune[0]) {
                case '1': {
                    sabie_factory sf;
                    inv.adauga_obiect(sf.creare_ob_aparare());
                    optiune = '\0';
                    break;
                }
                case '2': {
                    scut_factory scf;
                    inv.adauga_obiect(scf.creare_ob_aparare());
                    optiune = '\0';
                    break;
                }
                case '3': {
                    potiune_factory pf;
                    inv.adauga_obiect(pf.creare_ob_aparare());
                    optiune = '\0';
                    break;
                }
                case '4': {
                    std::cout << "\nAi actualizat inventarul cu succes!\n";
                    cumparare = false;
                    break;
                }
                default: {
                    std::cout << "\nOptiune invalida. Incearca din nou.\n";
                    greseli++;
                    break;
                }
            }
        }
        catch ( ex_bani& e) {
            //cumparare = false;
            std::cout <<  e.what() << "\n";
            break;
        }
    }
}


jucator& operator+(jucator& j, const obiect_aparare& ob) {
    j.set_viata(j.get_viata()+(ob.calc_putere()));
    j.verifica_viata();
    return j;
}

void game::depaseste_bomba(int x,int y) {
    const std::shared_ptr<bombe> b = lab.get_bomba().get_obiect(x,y);
    if (b == nullptr) return;
    bool alegere = true;
    char ch;
    while (alegere) {
        inv.afisare();
        j.afis_viata();
        lab.afiseaza();
        std::cout<<"\nAi o bomba in cale. Daca continui sa mergi, bomba explodeaza. Poti diminua efectele asupra vietii "
               "folosind un scut.\n1. Continua\n2. Foloseste scut\n3. Bea o potiune\n4. Actualizeaza inventar\nOptiune: ";
        std::cin>>ch;
        switch (ch) {

            case '1': {
                b->impact_jucator(j);
                try {
                    j.verifica_viata();
                }
                catch (const ex_viata& e) {
                    std::cout<<"\n"<<e.what()<<"\n";
                    game_over();
                }
                lab.get_bomba().sterge_obiecte(x, y);
                lab.ajusteaza_harta(j, j.get_pozitie().first, j.get_pozitie().second, x, y);
                j.set_pozitie(x,y);
                verifica_status();
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
                        j.set_pozitie(x,y);
                        verifica_status();
                        alegere = false;
                    } else throw ex_insuficiente("\nInsuficiente scuturi\n");
                }
                catch (const std::exception& e) {
                    std::cout<<e.what();
                }
                break;
            }
            case '3' : {
                auto pn = inv.gaseste_obiect(typeid(potiune));
                try {
                    if (inv.suficiente(pn)) {
                        inv.sterge_obiect(pn);
                        j.set_viata(j.get_viata()+pn->calc_putere());
                        j.verifica_viata();
                        alegere = false;
                    }
                    else throw ex_insuficiente("\n=============   INSUFICIENTE POTIUNI!!!  =============\n");
                }
                catch (const ex_insuficiente& e){
                    std::cout<<e.what()<<"\n";
                }
                break;
            }
            case '4': {
                cumpara_obiecte();
                alegere = false;
                break;
            }

            default: {
                std::cout<<"\nAi apasat o tasta gresita. Incearca din nou\n";
            }
        }
    }
}
