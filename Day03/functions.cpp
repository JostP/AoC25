#include "functions.h"
#include <cmath>

int calcJoltagePart1(std::string_view line){
    int first = 0;
    int second = 0;

    for(char c : line){
        int val = c - '0';

        if(second > first){
            first = second;
            second = val;
            continue;
        }

        if(val > second){
            second = val;
        }
    }

    return first * 10 + second;
}

uint_fast64_t calcJoltagePart2(std::string line, int count){
    uint_fast64_t sum = 0;
    auto lastMax = line.rend();

    for(int i = 1; i <= count; i++){
        auto currentMax = line.rbegin() + (count - i);

        for(auto it = currentMax; it != lastMax; it++){
            if(*it >= *currentMax){
                currentMax = it;
            }
        }

        lastMax = currentMax;
        sum += (*currentMax - '0') * std::pow(10, count - i);
    }

    return sum;
}
