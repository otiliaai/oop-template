
#ifndef GAME_H
#define GAME_H
#include "jucator.h"
#include "labirint.h"
class game {
    bool running;
public:
    jucator j;
    labirint lab;
    game();
    bool pozitie_valida(labirint &lab, int x, int y);
    void run();
    void actualizeaza_harta();
    void verifica_status();
};
#endif //GAME_H
