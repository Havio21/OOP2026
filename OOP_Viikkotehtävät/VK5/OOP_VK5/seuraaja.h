#ifndef SEURAAJA_H
#define SEURAAJA_H
#include <string>

using namespace std;

class Seuraaja
{
public:
    Seuraaja(string);
    void paivitys(string);
    Seuraaja *next = nullptr;
    string getNimi();

private:
    string nimi;
};

#endif // SEURAAJA_H
