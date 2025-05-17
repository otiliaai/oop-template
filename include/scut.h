#ifndef SCUT_H
#define SCUT_H
#include "obiect_aparare.h"
class scut : public obiect_aparare {
  public:
    scut();
    int get_putere() override;
    ~scut() = default;
};
#endif //SCUT_H
