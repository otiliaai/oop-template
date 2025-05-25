#include "exceptii.h"

exceptii::exceptii(const std::string& mesaj) : mesaj(mesaj) {};
const char* exceptii::what() const noexcept {
    return mesaj.c_str();
}