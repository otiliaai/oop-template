#ifndef EXCEPTII_H
#define EXCEPTII_H
#include <exception>
#include <string>

class exceptii : public std::exception{
    protected:
        std::string mesaj;
    public:
      explicit exceptii(const std::string& mesaj);
    [[nodiscard]] const char* what() const noexcept override;
};

#endif //EXCEPTII_H
