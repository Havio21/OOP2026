#include <iostream>
#include "seuraaja.h"
#include "notifikaattori.h"

using namespace std;

int main()
{
    Notifikaattori n;
    Seuraaja *A = new Seuraaja("Aapeli");
    Seuraaja *B = new Seuraaja("Beepeli");
    Seuraaja *C = new Seuraaja("Ceepeli");

    n.tulosta();
    n.postita("Moi sulle!");
    n.poista(B);

    n.lisaa(A);
    n.lisaa(B);
    n.lisaa(C);
    n.tulosta();
    n.postita("Moi vaan sullekin!");

    n.poista(B);
    n.tulosta();
    n.poista(A);
    n.poista(C);
    n.tulosta();

    return 0;
}
