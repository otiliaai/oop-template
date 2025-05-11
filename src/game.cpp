#include "game.h"
#include <conio.h>

game::game() :lab(15,35){
    this->running = true;
}
bool game::pozitie_valida(labirint &lab, int x, int y) {
    int lng = lab.get_dimensiuni().first;
    int lat = lab.get_dimensiuni().second;
    return  x > 0 && x < lng && y > 0 && y < lat && lab.drum_liber(x,y);
}

void game::run() {
    while (running) {
        system("cls");
        lab.afiseaza();
        inventar.afis_cont();
        inventar.afis_sabii();
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
        }
    }

    if (pozitie_valida(lab, x_nou, y_nou)) {
        j.set_pozitie(x_nou, y_nou);
        lab.ajusteaza_harta(lab, j.print_caracter(), x_vechi, y_vechi, x_nou, y_nou);
    } else {
        if (inamic_in_cale(x_nou, y_nou))
            lupta_cu_inamicul(x_nou, y_nou);
        if (diamant_in_cale(x_nou, y_nou))
            colecteaza_diamant(x_nou, y_nou);
    }

}
void game::verifica_status() {
    if (j.get_pozitie().first==lab.get_dimensiuni().first-2 && j.get_pozitie().second==lab.get_dimensiuni().second-2) {
        system("cls");
        std::cout<<"AI CASTIGAT JOCUL";
        running = false;
    }
}

bool game::inamic_in_cale(int x, int y) {
    return lab.get_inamic().get_obiect(x, y) != nullptr;
}

bool game::diamant_in_cale(int x, int y) {
    return lab.get_diamant().get_obiect(x, y) != nullptr;
}


void game::lupta_cu_inamicul(int x, int y) {
    std::cout<<"\nAi in cale un inamic. Daca alegi sa mergi mai departe, pierzi 80% din viata ta, "
               "daca alegi sa lupti, poti lua viata inamicului\nPentru lupta apasa 'l', pentru a continua apasa 'c'\nOptiune: ";
    char alegere = _getch();
    inamic* p = lab.get_inamic().get_obiect(x,y);

    if (!p) return;


    if (alegere == 'c') {
        j = j - (*p);
        std::cout<<j.get_viata()<<std::endl;
        _getch();
    } else {
        std::cout<<"\nPentru a invinge inamicul folosid sabia apasa 's'\nOptiune: ";
        _getch();
        try {
            inventar.verifica_sabii();
            inventar.scade_sabie();
            std::cout<<"Ai invins cu succes inamicul!";
        } catch (const  ex_insuficiente_sabii& e) {
            std::cout << e.what() << std::endl;
            std::cout<<"\nPentru a cumpara o sabie (200$), apasa pe 'b'.\nOption: ";
            char c = _getch();
            if (c == 'b') {
                try {
                    inventar.verifica_cont();
                    inventar.adauga_sabie();
                    inventar.scade_sabie();
                }
                catch (const ex_bani& e2) {
                    std::cout << e2.what() << std::endl;
                }
                catch (...) {
                    std::cout << "\nEroare necunoscuta" << std::endl;
                }
            }
        }
        catch (...) {
            std::cout << "\nEroare necunoscuta" << std::endl;
        }
       }
        j = j + (*p);
       lab.get_inamic().sterge_obiecte(x,y);
        std::cout<<j.get_viata()<<std::endl;
    }

void game::colecteaza_diamant(int x,int y) {
    diamant* d = lab.get_diamant().get_obiect(x,y);
    if (!d) return;
    inventar+=(*d);
    lab.get_diamant().sterge_obiecte(x,y);
}




