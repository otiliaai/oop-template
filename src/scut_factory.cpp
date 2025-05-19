#include "scut_factory.h"

std::shared_ptr<obiect_aparare> creare_ob_aparare() {
  return std::make_shared<scut>();
}