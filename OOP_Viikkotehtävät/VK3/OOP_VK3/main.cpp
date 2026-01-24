#include <iostream>
#include "italianchef.h"
using namespace std;

int main()
{
    Chef gustav("Gustav");
    gustav.makeSalad(42);
    gustav.makeSoup(32);

    cout << " " << endl;

    ItalianChef luigi("Luigi");
    luigi.makeSalad(21);
    luigi.makeSoup(14);
    luigi.askSecret("pizza", 14, 14);

    cout << " " << endl;

    return 0;
}
