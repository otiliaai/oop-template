#ifndef GAME_H
#define GAME_H
#include "jucator.h"
#include "labirint.h"
#include "inventar.h"

class game {
    static game* instance;
    bool running;
    jucator j;
    labirint lab;
    inventar inv;
    game();

public:
    game(const game&) =  delete;
    game& operator=(const game&) = delete;
    static game* get_instance();

    static bool pozitie_valida(const labirint &lab, int x, int y);
    void run();
    void actualizeaza_harta();
    void verifica_status();
    // bool inamic_in_cale(int x, int y);
    // bool diamant_in_cale(int x, int y);
    // void omoara_inamic(inamic* i);
    void lupta_cu_inamicul(int x,int y);
    void colecteaza_diamant(int x,int y);
    void game_over();
    inventar& get_inventar();

    void cumpara_obiecte();

    static int introdu_cantitate();
    void depaseste_bomba(int x,int y);

};
#endif //GAME_H
