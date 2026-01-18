#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum);

int main()
{
    srand(time(0));
    int maxnum;

    cout << "Anna arvotun luvun raja: ";
    cin >> maxnum;

    int laskuri = game(maxnum);
    cout << "Arvauksia yhteensa " << laskuri << endl;



    return 0;
}

int game(int maxnum)
{
    int arvaus; //Käyttäjän antama luku
    int arvottu = rand() % maxnum + 1;    //Arvottu luku
    int laskuri = 0;

    cout << "Arvaa numero: ";

    while(true){
        cin >> arvaus;
        laskuri++;

        if (arvaus < arvottu) {
            cout << "Luku on suurempi kuin " << arvaus << endl;
        }

        else if (arvaus > arvottu) {
            cout << "Luku on pienempi kuin " << arvaus << endl;
        }

        else {
            cout << "Oikein luku oli " << arvottu << endl;
            break;
        }
    }
    return laskuri;
}
