#include "functions.h"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Koordinata{
    long long x;
    long long y;
};

long long resiPart1(istream& file){
    vector<Koordinata> rdecePlosce;
    string vrstica;

    while(getline(file, vrstica)){
        char vejica;
        Koordinata k;
        stringstream ss(vrstica);
        ss >> k.x >> vejica >> k.y;
        rdecePlosce.push_back(k);
    }

    long long najvecjaPlosca = 0;

    for(size_t i=0; i<rdecePlosce.size()-1; i++){
        for(size_t j=i+1; j<rdecePlosce.size(); j++){
            long long dx = llabs(rdecePlosce[i].x - rdecePlosce[j].x) + 1;
            long long dy = llabs(rdecePlosce[i].y - rdecePlosce[j].y) + 1;
            long long plosca = dx * dy;
            if(plosca > najvecjaPlosca){
                najvecjaPlosca = plosca;
            }
        }
    }

    return najvecjaPlosca;
}

long long resiPart2(istream& file){
    vector<Koordinata> rdecePlosce;
    string vrstica;

    while(getline(file, vrstica)){
        char vejica;
        Koordinata k;
        stringstream ss(vrstica);
        ss >> k.x >> vejica >> k.y;
        rdecePlosce.push_back(k);
    }

    vector<pair<Koordinata, Koordinata>> robovi;
    for(size_t i=0; i<rdecePlosce.size()-1; i++){
        robovi.push_back(make_pair(rdecePlosce[i], rdecePlosce[i+1]));
    }
    robovi.push_back(make_pair(rdecePlosce[0], rdecePlosce[rdecePlosce.size()-1]));

    long long najvecjaPlosca = 0;

    for(size_t i=0; i<rdecePlosce.size()-1; i++){
        for(size_t j=i+1; j<rdecePlosce.size(); j++){
            long long x1 = max(rdecePlosce[i].x, rdecePlosce[j].x);
            long long x2 = min(rdecePlosce[i].x, rdecePlosce[j].x);
            long long y1 = max(rdecePlosce[i].y, rdecePlosce[j].y);
            long long y2 = min(rdecePlosce[i].y, rdecePlosce[j].y);

            long long dx = x1 - x2 + 1;
            long long dy = y1 - y2 + 1;
            long long plosca = dx * dy;

            // preverimo, ali je kak rob v notranjosti
            bool zunaj = false;
            for(auto &edge: robovi){
                if(edge.first.x == edge.second.x){ // vertikalen rob
                    long long ey1 = max(edge.first.y, edge.second.y);
                    long long ey2 = min(edge.first.y, edge.second.y);
                    long long ex = edge.first.x;
                    if(x1 > ex && x2 < ex && ey2 < y1 && ey1 > y2){
                        zunaj = true;
                        break;
                    }
                } else { // horizontalen rob
                    long long ex1 = max(edge.first.x, edge.second.x);
                    long long ex2 = min(edge.first.x, edge.second.x);
                    long long ey = edge.first.y;
                    if(y1 > ey && y2 < ey && ex2 < x1 && ex1 > x2){
                        zunaj = true;
                        break;
                    }
                }
            }
            if(!zunaj && plosca > najvecjaPlosca){
                najvecjaPlosca = plosca;
            }
        }
    }

    return najvecjaPlosca;
}
