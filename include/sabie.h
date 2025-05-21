#ifndef SABIE_H
#define SABIE_H
#include "obiect_aparare.h"
class sabie : public obiect_aparare{
  public:
    sabie();
    int calc_putere() const;
    ~sabie() = default;
 };
#endif //SABIE_H
