#ifndef EX_INSUFICIENTE_H
#define EX_INSUFICIENTE_H
#include "exceptii.h"
class ex_insuficiente: public exceptii {
  public:
    explicit ex_insuficiente(const std::string& mesaj);
};
#endif //EX_INSUFICIENTE_H
