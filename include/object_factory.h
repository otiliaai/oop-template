#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H
#include "obiect_aparare.h"
#include <memory>
class object_factory {
  public:
    virtual ~object_factory() =  default;
    virtual std::shared_ptr<obiect_aparare> creare_ob_aparare() = 0;
};
#endif //OBJECT_FACTORY_H
