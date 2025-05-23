#include "scut.h"

scut::scut() : obiect_aparare(100,150) {}

int scut::calc_putere() const {
    return this->putere-20;
}
