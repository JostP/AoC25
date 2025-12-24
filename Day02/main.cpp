#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Napaka pri odpiranju input.txt\n";
        return 1;
    }

    std::string line;
    std::getline(file, line);

// ---------------------------------------------------------
// Part 1
// ---------------------------------------------------------

    auto ranges = razcleniRanges(line);
    auto invalid = findAllInvalidIDs(ranges);

    long long rezultat1 = sumIDs(invalid);
    std::cout << "Rezultat za part 1: " << rezultat1 << std::endl;

// ---------------------------------------------------------
// Part 2
// ---------------------------------------------------------

    long long rezultat2 = sumInvalidIDsPart2(ranges);
    std::cout << "Rezultat za part 2: " << rezultat2 << std::endl;

    return 0;
}