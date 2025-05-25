#ifndef EX_VIATA_H
#define EX_VIATA_H
#include "exceptii.h"
class ex_viata: public exceptii {
  public:
    explicit ex_viata( const std::string& mesaj);
};
#endif //EX_VIATA_H
