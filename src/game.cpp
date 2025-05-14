#include "game.h"
#include <conio.h>

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
        j.afis_viata();
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
        lab.ajusteaza_harta(j, x_vechi, y_vechi, x_nou, y_nou);
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
    std::cout << "\nAi in cale un inamic. Daca alegi sa mergi mai departe, pierzi 70% din viata ta, "
                 "daca alegi sa lupti, poti invinge inamicul.\nPentru lupta apasa 'l', pentru a continua apasa 'c'\nOptiune: ";
    char alegere = _getch();
    const inamic* p = lab.get_inamic().get_obiect(x, y);

    if (!p) return;

    if (alegere == 'c') {
        j = j - (*p);
        try {
            j.verifica_viata();
        } catch (const ex_viata& e) {
            std::cout << e.what() << std::endl;
            running = false;
            game_over();
            return;
        }
    } else if (alegere == 'l') {
        std::cout << "\nPentru a invinge inamicul folosind sabia, apasa 's'\n";
        _getch(); // așteaptă să apese 's'

        try {
            inventar.verifica_sabii();
            inventar.scade_sabie();
            std::cout << "Ai invins cu succes inamicul!";
            Sleep(500);
        } catch (const ex_insuficiente_sabii& e) {
            std::cout << e.what() << std::endl;
            std::cout << "\nPentru a cumpara o sabie (500$), apasa pe 'b'.\nOptiune: ";
            char c = _getch();

            if (c == 'b') {
                try {
                    inventar.verifica_cont(500); // preț corect
                    inventar.adauga_sabie();
                    inventar.scade_sabie();
                    std::cout << "Ai cumparat si folosit o sabie!";
                    Sleep(500);
                } catch (const ex_bani& e2) {
                    std::cout << e2.what() << std::endl;
                    std::cout << "\nContinua si plateste cu viata. Apasa 'c'\n";
                    _getch();
                    j = j - (*p); // abia aici pierzi viață
                    try {
                        j.verifica_viata();
                    } catch (const ex_viata& e3) {
                        std::cout << e3.what() << std::endl;
                        running = false;
                        game_over();
                        return;
                    }
                }
            }
        }
    } else {
        std::cout << "\nAI APASAT O TASTA GRESITA!";
        return;
    }

    lab.get_inamic().sterge_obiecte(x, y);
    lab.ajusteaza_harta(j, j.get_pozitie().first, j.get_pozitie().second, x, y);
}


void game::colecteaza_diamant(int x,int y) {
    const diamant* d = lab.get_diamant().get_obiect(x,y);
    if (!d) return;
    inventar+=(*d);
    lab.get_diamant().sterge_obiecte(x,y);
    std::pair<int,int> poz = j.get_pozitie();
   lab.ajusteaza_harta(j,poz.first,poz.second,x,y);
}

void game::game_over() {
    system("cls");
    std::cout<<"\nGAME OVER!"<<std::endl;
}