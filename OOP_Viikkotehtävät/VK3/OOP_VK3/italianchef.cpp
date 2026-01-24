#include "italianchef.h"
#include <string>
#include <iostream>

ItalianChef::ItalianChef(string a) : Chef(a) {
    cout << "CONSTRUCTOR: Italian chef is named " << a << endl;
    chefName = a;

}

ItalianChef::~ItalianChef() {
    cout << "DECONSTRUCTOR: Italian Chef " << chefName << " has retired" << endl;
}

bool ItalianChef::askSecret(string q, int w, int e)   {
    if (q == password)  {
        cout << "DEBUG: Correct password" << endl;
        makepizza(w, e);
        return true;
    }
    return false;
}

int ItalianChef::makepizza(int w, int e)    {
    cout << "DEBUG: " <<chefName << " can make " << min(w, e) / 5 << " pizzas" << endl;
    return min(w, e) / 5;
}
