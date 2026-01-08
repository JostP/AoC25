#include "functions.h"
#include <string>
#include <set>
#include <vector>

using namespace std;

int resiPart1(istream& file){
    string vrstica;
    int pozicija = 0;
    int skupnoRazcepov = 0;
    set<int> zarki;

    getline(file, vrstica);
    while(vrstica[pozicija] != 'S') pozicija++;
    zarki.insert(pozicija);

    getline(file, vrstica);

    for(; getline(file, vrstica);){
        pozicija = 0;
        for(char c : vrstica){
            if(c == '^' && zarki.find(pozicija) != zarki.end()){
                zarki.erase(pozicija);
                zarki.insert(pozicija - 1);
                zarki.insert(pozicija + 1);
                skupnoRazcepov++;
            }
            pozicija++;
        }
        getline(file, vrstica);
    }

    return skupnoRazcepov;
}

unsigned long long resiPart2(istream& file){
    string vrstica;
    vector<unsigned long long> zarki;
    int pozicija = 0;

    getline(file, vrstica);
    for(char c : vrstica){
        if(c == 'S') zarki.push_back(1);
        else zarki.push_back(0);
        pozicija++;
    }

    getline(file, vrstica);

    for(; getline(file, vrstica);){
        pozicija = 0;
        for(char c : vrstica){
            if(c == '^' && zarki[pozicija] >= 1){
                unsigned long long stevilo = zarki[pozicija];
                zarki[pozicija] = 0;
                zarki[pozicija - 1] += stevilo;
                zarki[pozicija + 1] += stevilo;
            }
            pozicija++;
        }
        getline(file, vrstica);
    }

    unsigned long long skupaj = 0;
    for(auto v : zarki){
        skupaj += v;
    }

    return skupaj;
}
