#ifndef ASIAKAS_H
#define ASIAKAS_H
#include <string>
#include "luottotili.h"
#include "pankkitili.h"
using namespace std;

class asiakas
{
public:
    asiakas(string, double);
    string getNimi();
    void showSaldo();
    bool talletus(double);
    bool nosto(double);
    bool luotonMaksu(double);
    bool luotonNosto(double);
    bool tilisiirto(double, asiakas&);

private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;
};

#endif // ASIAKAS_H
