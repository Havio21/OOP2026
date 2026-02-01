#include "asiakas.h"
#include <iostream>


asiakas::asiakas(string n, double s) : kayttotili(n), luottotili(n, s)
{
    nimi = n;
}

string asiakas::getNimi()
{
    return nimi;
}

void asiakas::showSaldo()
{
    cout << "Kayttotili saldo " << kayttotili.getBalance() << endl;
    cout << "Luottotili saldo " << luottotili.getBalance() << endl;

}

bool asiakas::talletus(double q)
{
    return kayttotili.deposit(q);
}

bool asiakas::nosto(double q)
{
    return kayttotili.withdraw(q);
}

bool asiakas::luotonMaksu(double q)
{
    return luottotili.deposit(q);
}

bool asiakas::luotonNosto(double q)
{
    return luottotili.withdraw(q);
}

bool asiakas::tilisiirto(double q, asiakas& kohde)
{
    cout << "Asiakas tilisiirto" << endl;
    double saldo = kayttotili.getBalance();

    if ((q < 0) || (q > saldo)){
        return false;
    }

    kayttotili.withdraw(q);
    kohde.kayttotili.deposit(q);

    return true;
}
