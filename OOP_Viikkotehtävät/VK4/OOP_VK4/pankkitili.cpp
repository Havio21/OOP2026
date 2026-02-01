#include "pankkitili.h"
#include <iostream>

Pankkitili::Pankkitili(string omistaja)
{
    cout << "Olen pankkitili konstruktori" << endl;
}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double w)
{
    if (w < 0)  {
        return false;
        saldo += w;
    }
    return true;
}

bool Pankkitili::withdraw(double w)
{
    if ( (w < 0) || ( (saldo - w) < 0) )return false;
    saldo -= w;
    return true;
}
