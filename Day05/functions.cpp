#include "functions.h"
#include <string>
#include <sstream>

using namespace std;

void preberiVhod(
    istream& file,
    vector<pair<unsigned long int, unsigned long int>>& obmocja,
    vector<unsigned long int>& idji
){
    unsigned long int minVrednost;
    unsigned long int maxVrednost;
    char minus;

    for(string vrstica; getline(file, vrstica);){
        if(vrstica == "") break;
        istringstream ss(vrstica);
        ss >> minVrednost >> minus >> maxVrednost;
        obmocja.push_back({minVrednost, maxVrednost});
    }

    for(string vrstica; getline(file, vrstica);){
        idji.push_back(stoul(vrstica));
    }
}

int prestejSvezeIDje(
    const vector<pair<unsigned long int, unsigned long int>>& obmocja,
    const vector<unsigned long int>& idji
){
    int stevec = 0;

    for(auto id : idji){
        for(auto obmocje : obmocja){
            if(id >= obmocje.first && id <= obmocje.second){
                stevec++;
                break;
            }
        }
    }

    return stevec;
}

unsigned long int prestejVseSveze(
    vector<pair<unsigned long int, unsigned long int>> obmocja
){
    unsigned long int skupno = 0;

    for(unsigned int i = 0; i < obmocja.size() - 1; i++){
        for(unsigned int j = i + 1; j < obmocja.size(); j++){
            if(obmocja[j].first == 0 && obmocja[j].second == 0) continue;

            if(obmocja[i].first <= obmocja[j].first &&
               obmocja[i].second >= obmocja[j].second){
                obmocja[j] = {0, 0};
            }
            else if(obmocja[i].first >= obmocja[j].first &&
                    obmocja[i].second <= obmocja[j].second){
                obmocja[i] = {0, 0};
                goto izbrisano;
            }
            else if(obmocja[i].second >= obmocja[j].first &&
                    obmocja[i].second <= obmocja[j].second){
                obmocja[i].second = obmocja[j].first - 1;
            }
            else if(obmocja[i].first <= obmocja[j].second &&
                    obmocja[i].first >= obmocja[j].first){
                obmocja[i].first = obmocja[j].second + 1;
            }
        }

        izbrisano:
        if(obmocja[i].first == 0 && obmocja[i].second == 0) continue;
        skupno += (obmocja[i].second - obmocja[i].first) + 1;
    }

    auto zadnje = obmocja.back();
    if(zadnje.first != 0 && zadnje.second != 0){
        skupno += zadnje.second - zadnje.first + 1;
    }

    return skupno;
}
