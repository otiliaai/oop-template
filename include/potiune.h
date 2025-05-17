#ifndef POTIUNE_H
#define POTIUNE_H
#include "obiect_aparare.h"
class potiune : public obiect_aparare {
  public:
    potiune();
    int get_putere() const override;
    ~potiune() = default;
   };
#endif //POTIUNE_H
