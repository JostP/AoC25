#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Ne morem odpreti input.txt\n";
        return 1;
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    int result1 = countZeroVisits(lines);
    int result2 = countZeroClicks(lines);
    std::cout << "Geslo za prvi del naloge je: " << result1 << std::endl;
    std::cout << "Geslo za drugi del naloge je: " << result2 << std::endl;
    return 0;
}