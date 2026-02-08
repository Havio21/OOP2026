#include "notifikaattori.h"
#include <iostream>

Notifikaattori::Notifikaattori() {
    cout << "Notifikaattori konstruktio" << endl;
}

void Notifikaattori::lisaa(Seuraaja *uusSeur)
{
    cout << "Luodaan seuraaja" << endl;

    if (uusSeur == nullptr)
    {
        return;
    }

    if (seuraajat == nullptr)
    {
        seuraajat = uusSeur;
        return;
    }
    uusSeur->next = seuraajat;
    seuraajat = uusSeur;
}

void Notifikaattori::poista(Seuraaja *poistSeur)
{

    cout << "Poistetaan seuraaja"<< endl;
    if (poistSeur == nullptr)
    {
        return;
    }
    if (seuraajat == nullptr)
    {
        return;
    }
    if (seuraajat == poistSeur)
    {
        seuraajat = seuraajat->next;
        return;
    }

    Seuraaja *seurTempNext = seuraajat->next;
    Seuraaja *seurTempPrev = seuraajat;
    while (seurTempNext->next != nullptr)
    {

        if (seurTempNext == poistSeur)
        {
            seurTempPrev->next = seurTempNext->next;
            return;
        }

        seurTempPrev = seurTempNext;
        seurTempNext = seurTempNext->next;
    }

    if (seurTempNext == poistSeur)
    {
        seurTempPrev->next = nullptr;
    }
}

void Notifikaattori::tulosta()
{
    if (seuraajat == nullptr)
    {
        cout << "Ei seuraajia :(" << endl;
        return;
    }

    Seuraaja * seurTempNext = seuraajat;

    while (seurTempNext->next != nullptr)
    {
        cout << seurTempNext->getNimi() << endl;
        seurTempNext = seurTempNext->next;
    }

    cout << seurTempNext->getNimi() << endl;
    /*cout << "Seuraajat: " << endl;
    if (seuraajat == nullptr)   {
        cout << "Ei seuraajia :(" << endl;
        return;
    }
    Seuraaja *alku = seuraajat;
    while (alku != nullptr) {
        cout << "Seuraaja " << alku->getNimi() << endl;
        alku = alku->next;
    }*/
}

void Notifikaattori::postita(string v)
{
    cout << "Notifikaattori postaa viestin " << v << endl;
    Seuraaja *now = seuraajat;

    while (now != nullptr)
    {
        now->paivitys(v);
        now = now->next;
    }
}
