#ifndef POTIUNE_FACTORY_H
#define POTIUNE_FACTORY_H
#include "potiune.h"
#include <memory>
#include "object_factory.h"

class potiune_factory : public object_factory{
  public:
    std::shared_ptr<obiect_aparare> creare_ob_aparare() override;
};
#endif //POTIUNE_FACTORY_H
