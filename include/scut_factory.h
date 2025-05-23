#ifndef SCUT_FACTORY_H
#define SCUT_FACTORY_H
#include <memory>
#include "object_factory.h"
#include "scut.h"
class scut_factory : public object_factory {
  public:
    std::shared_ptr<obiect_aparare> creare_ob_aparare() override;
};
#endif //SCUT_FACTORY_H
