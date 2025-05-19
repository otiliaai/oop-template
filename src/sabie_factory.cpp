#include "sabie_factory.h"

std::shared_ptr<obiect_aparare>  sabie_factory::creare_ob_aparare() {
  return std::make_shared<sabie>();
}