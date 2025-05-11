#ifndef EX_BANI_H
#define EX_BANI_H
#include "exceptii.h"
class ex_bani: public exceptii {
public:
    explicit ex_bani(const std::string& mesaj);
};
#endif //EX_BANI_H
