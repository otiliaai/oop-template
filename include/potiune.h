#ifndef POTIUNE_H
#define POTIUNE_H
#include "obiect_aparare.h"
class potiune : public obiect_aparare {
  public:
    potiune();
    int calc_putere() const override;
    ~potiune() override= default;
   };
#endif //POTIUNE_H
