#include <fstream>
#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main(){
    ifstream file("input.txt");

    int result1 = 0;
    uint_fast64_t result2 = 0;

    const int batteryCount = 12;

    for(string line; getline(file, line);){
        result1 += calcJoltagePart1(line);
        result2 += calcJoltagePart2(line, batteryCount);
    }

    cout << "Part 1: " << result1 << endl;
    cout << "Part 2: " << result2 << endl;

    return 0;
}
