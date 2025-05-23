#ifndef SCUT_H
#define SCUT_H
#include "obiect_aparare.h"
class scut : public obiect_aparare {
  public:
    scut();
    int calc_putere() const override;
    ~scut() = default;
};
#endif //SCUT_H
