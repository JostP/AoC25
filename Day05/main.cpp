#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;

int main(){
    ifstream file("input.txt");

    vector<pair<unsigned long int, unsigned long int>> obmocja;
    vector<unsigned long int> idji;

    preberiVhod(file, obmocja, idji);

    int rezultat1 = prestejSvezeIDje(obmocja, idji);
    unsigned long int rezultat2 = prestejVseSveze(obmocja);

    cout << "Part 1: " << rezultat1 << endl;
    cout << "Part 2: " << rezultat2 << endl;

    return 0;
}
