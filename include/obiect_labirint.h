#ifndef OBIECT_LABIRINT_H
#define OBIECT_LABIRINT_H

class jucator;

class obiect_labirint{
protected:
  int x,y;
  char simbol;
  public:
    obiect_labirint();
    virtual ~obiect_labirint() = default;
    char print_caracter() const;
    void set_pozitie(int x,int y);

    virtual void impact_jucator(jucator& j) const = 0;


  };
#endif //OBIECT_LABIRINT_H
