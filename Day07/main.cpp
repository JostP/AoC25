#include <fstream>
#include <iostream>
#include "functions.h"

using namespace std;

int main(){
    ifstream file("input.txt");

    int rezultat1 = resiPart1(file);

    file.clear();
    file.seekg(0);

    unsigned long long rezultat2 = resiPart2(file);

    cout << "Part 1: " << rezultat1 << endl;
    cout << "Part 2: " << rezultat2 << endl;

    return 0;
}
