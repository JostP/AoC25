#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Naprava* najdiAliUstvari(map<string, Naprava>& naprave, string ime) {
    if (naprave.find(ime) == naprave.end()) {
        naprave[ime].ime = ime;
        naprave[ime].steviloPoti = -1;
    }
    return &naprave[ime];
}

long long prestejPoti(Naprava* naprava) {
    if (naprava->ime == "out") {
        return 1;
    }

    if (naprava->steviloPoti != -1) {
        return naprava->steviloPoti;
    }

    long long vsota = 0;
    for (Naprava* izhod : naprava->izhodi) {
        vsota += prestejPoti(izhod);
    }

    naprava->steviloPoti = vsota;
    return vsota;
}

void resiPrviDel() {
    ifstream vhod("input.txt");
    if (!vhod.is_open()) return;

    map<string, Naprava> naprave;
    string vrstica;

    while (getline(vhod, vrstica)) {
        stringstream ss(vrstica);
        string imeNaprave;
        ss >> imeNaprave;
        
        imeNaprave.pop_back();
        
        Naprava* trenutna = najdiAliUstvari(naprave, imeNaprave);

        string imeIzhoda;
        while (ss >> imeIzhoda) {
            Naprava* izhodnaNaprava = najdiAliUstvari(naprave, imeIzhoda);
            trenutna->izhodi.push_back(izhodnaNaprava);
        }
    }
    vhod.close();

    Naprava* zacetek = najdiAliUstvari(naprave, "you");
    cout << "Skupno stevilo poti: " << prestejPoti(zacetek) << endl;
}