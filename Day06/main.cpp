#include <fstream>
#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main(){
    ifstream file("input.txt");

    long long rezultat1 = resiPart1(file);

    file.clear();
    file.seekg(0);

    long long rezultat2 = resiPart2(file);

    cout << "Part 1: " << rezultat1 << endl;
    cout << "Part 2: " << rezultat2 << endl;

    return 0;
}
