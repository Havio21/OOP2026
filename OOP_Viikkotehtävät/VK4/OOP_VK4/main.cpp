#include <iostream>
#include "asiakas.h"

using namespace std;

int main()
{

    asiakas pekka("Pekka", 2000);
    cout << "Pekan tilit" << endl;
    pekka.showSaldo();
    cout << "Pekan talletus" << endl;
    pekka.talletus(500);
    pekka.showSaldo();
    cout << "Pekan luoton nosto" << endl;
    pekka.luotonNosto(200);
    pekka.showSaldo();
    cout << "Pekan uusi tilanne" << endl;
    pekka.showSaldo();

    asiakas jenni("Jenni", 3000);
    cout << "Jennin tilit" << endl;
    jenni.showSaldo();
    cout << "Jennin talletus" << endl;
    jenni.talletus(300);
    jenni.showSaldo();
    cout << "Jennin luoton nosto" << endl;
    jenni.luotonNosto(400);
    jenni.showSaldo();

    cout << "Tilinsiirto Pekalta Jennille" << endl;
    pekka.tilisiirto(200, jenni);

    pekka.showSaldo();
    jenni.showSaldo();
    return 0;
}
