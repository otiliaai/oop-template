#include "game.h"
#include <conio.h>


game::game() :lab(15,35){
    this->running = true;
}
bool game::pozitie_valida(labirint &lab, int x, int y) {
    int lng = lab.get_dimensiuni(lab).first;
    int lat = lab.get_dimensiuni(lab).second;
    return  x > 0 && x < lng && y > 0 && y < lat && lab.drum_liber(lab,x,y);
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
        lab.ajusteaza_harta(lab, j.print_jucator(), x_vechi, y_vechi, x_nou, y_nou);
    }
}
void game::verifica_status() {
    if (j.get_pozitie().first==lab.get_dimensiuni(lab).first-2 && j.get_pozitie().second==lab.get_dimensiuni(lab).second-2) {
        system("cls");
        std::cout<<"AI CASTIGAT JOCUL";
        running = false;
    }
}


void game::run() {

    while (running) {
        system("cls");
        lab.afiseaza();
        actualizeaza_harta();
        verifica_status();
    }
}
