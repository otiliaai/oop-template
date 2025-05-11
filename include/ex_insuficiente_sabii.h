#ifndef EX_INSUFICIENTE_SABII_H
#define EX_INSUFICIENTE_SABII_H
#include "exceptii.h"
class ex_insuficiente_sabii: public exceptii {
  public:
    explicit ex_insuficiente_sabii(const std::string& mesaj);
};
#endif //EX_INSUFICIENTE_SABII_H
