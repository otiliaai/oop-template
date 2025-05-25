#include <iostream>
#include <array>
#include "caracter.h"
#include "labirint.h"
#include "game.h"
#include "obiect_aparare.h"
#include "scut.h"
#include "sabie.h"
#include "inventar.h"
int main() {
    game* game1 = game::get_instance();
    game1->run();

    return 0;
}

