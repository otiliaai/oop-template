#ifndef GAME_H
#define GAME_H
#include "jucator.h"
#include "labirint.h"
#include "inventar.h"
#include "inamic.h"
#include <windows.h>

class game {
    static game* instance;
    bool running;
    jucator j;
    labirint lab;
    inventar inv;
    game();
    game(const game&) =  delete;
    game& operator=(const game&) = delete;
public:
    static game* get_instance();
    bool pozitie_valida(labirint &lab, int x, int y);
    void run();
    void actualizeaza_harta();
    void verifica_status();
    bool inamic_in_cale(int x, int y);
    bool diamant_in_cale(int x, int y);
    void omoara_inamic(inamic* i);
    void lupta_cu_inamicul(int x,int y);
    void colecteaza_diamant(int x,int y);
    void game_over();
    inventar& get_inventar();
    void cumpara_scut();
    void cumpara_obiecte();
    int introdu_cantitate();
};
#endif //GAME_H
