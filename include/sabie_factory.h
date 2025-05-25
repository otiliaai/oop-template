#ifndef SABIE_FACTORY_H
#define SABIE_FACTORY_H
#include <memory>
#include "object_factory.h"
#include "sabie.h"

class sabie_factory : public object_factory {
  public:
    std::shared_ptr<obiect_aparare> creare_ob_aparare() override;
};
#endif //SABIE_FACTORY_H
