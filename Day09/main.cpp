#include <fstream>
#include <iostream>
#include "functions.h"

using namespace std;

int main(){
    ifstream datoteka("input.txt");

    long long rezultat1 = resiPart1(datoteka);

    datoteka.clear();
    datoteka.seekg(0);

    long long rezultat2 = resiPart2(datoteka);

    cout << "Part 1: " << rezultat1 << endl;
    cout << "Part 2: " << rezultat2 << endl;

    return 0;
}
