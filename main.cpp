#include <iostream>
#include <array>
#include "caracter.h"
    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i]
    ///
#include "labirint.h"
#include "game.h"
#include "obiect_aparare.h"
#include "scut.h"
#include "sabie.h"
#include "inventar.h"
int main() {
    game* game1 = game::get_instance();
    game1->run();

    inventar& in = game1->get_inventar();

    auto s1 = std::make_shared<scut>();
    auto s2 = std::make_shared<scut>();
    auto s3 = std::make_shared<scut>();
    auto d1 = std::make_shared<sabie>();
    auto d2 = std::make_shared<sabie>();
    auto d3 = std::make_shared<sabie>();

    in.adauga_obiect(s1);
    in.adauga_obiect(s2);
    in.adauga_obiect(d2);
    in.afisare();
    in.sterge_obiect(s2);
    in.adauga_obiect(s3);
    in.adauga_obiect(s2);
    in.afisare_obiecte_aparare();
    std::cout << in.numar_sabii() << std::endl;
    std::cout << in.numar_scuturi();

    return 0;
}



