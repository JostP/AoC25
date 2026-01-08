#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long izracunajRazdaljo(RazdelilnaOmarica o1, RazdelilnaOmarica o2) {
    long long dx = o1.x - o2.x;
    long long dy = o1.y - o2.y;
    long long dz = o1.z - o2.z;
    return dx * dx + dy * dy + dz * dz;
}

bool primerjajPovezave(Povezava a, Povezava b) {
    return a.razdalja < b.razdalja;
}

void resiPrviDel() {
    ifstream vhod("input.txt");
    if (!vhod.is_open()) return;

    vector<RazdelilnaOmarica> omarice;
    string vrstica;
    int stevecId = 0;

    while (getline(vhod, vrstica)) {
        RazdelilnaOmarica o;
        stringstream ss(vrstica);
        char ločilo;
        if (ss >> o.x >> ločilo >> o.y >> ločilo >> o.z) {
            o.krog = stevecId;
            omarice.push_back(o);
            stevecId++;
        }
    }
    vhod.close();

    vector<Povezava> povezave;
    for (size_t i = 0; i < omarice.size(); i++) {
        for (size_t j = i + 1; j < omarice.size(); j++) {
            povezave.push_back({izracunajRazdaljo(omarice[i], omarice[j]), i, j});
        }
    }

    sort(povezave.begin(), povezave.end(), primerjajPovezave);

    int meja = 1000;
    for (int i = 0; i < meja && i < (int)povezave.size(); i++) {
        const auto& pz = povezave[i];
        int krog1 = omarice[pz.omarica1].krog;
        int krog2 = omarice[pz.omarica2].krog;

        if (krog1 != krog2) {
            for (size_t b = 0; b < omarice.size(); b++) {
                if (omarice[b].krog == krog2) {
                    omarice[b].krog = krog1;
                }
            }
        }
    }

    unordered_map<int, int> frekvence;
    for (const auto& o : omarice) {
        frekvence[o.krog]++;
    }

    long long f1 = 0, f2 = 0, f3 = 0;
    for (auto const& [id, velikost] : frekvence) {
        if (velikost > f1) {
            f3 = f2; f2 = f1; f1 = velikost;
        } else if (velikost > f2) {
            f3 = f2; f2 = velikost;
        } else if (velikost > f3) {
            f3 = velikost;
        }
    }

    cout << f1 << "*" << f2 << "*" << f3 << "=" << f1 * f2 * f3 << endl;
}

void resiDrugiDel() {
    ifstream vhod("input.txt");
    vector<RazdelilnaOmarica> omarice;
    string vrstica;
    int stevecId = 0;

    while (getline(vhod, vrstica)) {
        RazdelilnaOmarica o;
        stringstream ss(vrstica);
        char ločilo;
        if (ss >> o.x >> ločilo >> o.y >> ločilo >> o.z) {
            o.krog = stevecId;
            omarice.push_back(o);
            stevecId++;
        }
    }
    vhod.close();

    vector<Povezava> povezave;
    for (size_t i = 0; i < omarice.size(); i++) {
        for (size_t j = i + 1; j < omarice.size(); j++) {
            povezave.push_back({izracunajRazdaljo(omarice[i], omarice[j]), i, j});
        }
    }

    sort(povezave.begin(), povezave.end(), primerjajPovezave);

    for (size_t i = 0; i < povezave.size(); i++) {
        const auto& pz = povezave[i];
        int krog1 = omarice[pz.omarica1].krog;
        int krog2 = omarice[pz.omarica2].krog;

        if (krog1 != krog2) {
            bool vsePovezano = true;
            for (size_t b = 0; b < omarice.size(); b++) {
                if (omarice[b].krog == krog2) {
                    omarice[b].krog = krog1;
                }
                if (omarice[b].krog != krog1) {
                    vsePovezano = false;
                }
            }

            if (vsePovezano) {
                cout << omarice[pz.omarica1].x << "*" << omarice[pz.omarica2].x << "=" 
                     << omarice[pz.omarica1].x * omarice[pz.omarica2].x << endl;
                break;
            }
        }
    }
}