#ifndef OBIECT_LABIRINT_H
#define OBIECT_LABIRINT_H

class obiect_labirint{
protected:
  int x,y;
  char simbol;
  public:
    obiect_labirint();
    virtual ~obiect_labirint() = default;
    virtual char print_caracter() const = 0;
    void set_pozitie(int x,int y);


  };
#endif //OBIECT_LABIRINT_H
