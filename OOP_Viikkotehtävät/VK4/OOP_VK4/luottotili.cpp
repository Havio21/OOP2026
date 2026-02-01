#include "luottotili.h"
#include <iostream>


Luottotili::Luottotili(string omistaja, double s) : Pankkitili(omistaja)
{
    cout << "Olen luottotili konstuktorissa" << endl;
    luottoRaja = s;
}

bool Luottotili::deposit(double q)
{
    if (saldo < luottoRaja) {
        if (q > 0)  {
            saldo = saldo + q;
            return true;
        }
    }
    return false;
}

bool Luottotili::withdraw(double q)
{
    if (q > 0)  {
        saldo = saldo - q;
        return true;
    }
    return false;
}
