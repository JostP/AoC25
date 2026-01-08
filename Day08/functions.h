#ifndef FUNKCIJE_H
#define FUNKCIJE_H

#include <vector>
#include <string>

struct RazdelilnaOmarica {
    long long x;
    long long y;
    long long z;
    int krog;
};

struct Povezava {
    long long razdalja;
    size_t omarica1;
    size_t omarica2;
};

void resiPrviDel();
void resiDrugiDel();

#endif