#include "seuraaja.h"
#include <iostream>

Seuraaja::Seuraaja(string n)
{
    nimi = n;
    cout << "Seuraaja konstruktori" <<endl;
    //cout << "Luodaan seuraaja " << nimi << endl;
}

void Seuraaja::paivitys(string v)
{
    cout << "paivitys" << endl;
    cout << "viesti " << v << endl;
}

string Seuraaja::getNimi()
{
    return nimi;
}
