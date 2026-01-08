#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;

int main(){
    ifstream file("input.txt");

    vector<string> polje;
    for(string vrstica; getline(file, vrstica);){
        polje.push_back(vrstica);
    }

    int rezultat1 = prestejDostopne(polje);

    int rezultat2 = odstraniInPrestej(polje);

    cout << "Part 1: " << rezultat1 << endl;
    cout << "Part 2: " << rezultat2 << endl;

    return 0;
}
