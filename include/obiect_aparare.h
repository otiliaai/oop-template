#ifndef OBIECT_APARARE_H
#define OBIECT_APARARE_H
class obiect_aparare{
protected:
    int putere;
    int pret;
  public:
      obiect_aparare(int putere,int pret);
      virtual int get_putere() = 0;
    virtual int get_pret() const;
    virtual ~obiect_aparare() = default;

 };

#endif //OBIECT_APARARE_H
