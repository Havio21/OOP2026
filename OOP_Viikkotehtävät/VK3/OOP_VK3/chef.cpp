#include "chef.h"
#include <iostream>

Chef::Chef(string s) {
    cout << "CONSTRUCTOR: Chef is named " << s << endl;
    chefName = s;
}

Chef::~Chef()   {
    cout << "DECONSTRUCTOR: " << chefName << " has retired" << endl;
}


string Chef::getName()    {
    return chefName;
}
int Chef::makeSalad(int ainekset)  {
    int annokset = ainekset / 5;
    cout << chefName << " with " << ainekset << " items can make salad " << annokset << " portions" << endl;
    return annokset;
}

int Chef::makeSoup(int ainekset)   {
    int annokset = ainekset / 3;
    cout << chefName << " with " << ainekset << " items can make soup " << annokset << " portions" << endl;
    return annokset;
}
