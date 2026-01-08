#ifndef FUNKCIJE_H
#define FUNKCIJE_H

#include <vector>
#include <string>
#include <map>

struct Naprava {
    std::string ime;
    std::vector<Naprava*> izhodi;
    long long steviloPoti;
};

long long prestejPoti(Naprava* naprava);
void resiPrviDel();

#endif