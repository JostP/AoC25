#include "functions.h"
#include <string>
#include <vector>

// ---------------------------------------------------------
// PART 1
// ---------------------------------------------------------
int countZeroVisits(const std::vector<std::string>& lines) {
    int pos = 50;
    int count = 0;

    for (const std::string& s : lines) {
        if (s.empty()) continue;

        char smer = s[0];
        int dist = std::stoi(s.substr(1));

        if (smer == 'R') {
            pos = (pos + dist) % 100;
        }
        
        else if (smer == 'L') {
            pos = (pos - dist) % 100;
            if (pos < 0)
                pos += 100;
        }

        if (pos == 0) {
            count++;
        }
    }

    return count;
}



// ---------------------------------------------------------
// PART 2 (methoda 0x434C49434B)
// ---------------------------------------------------------
int countZeroClicks(const std::vector<std::string>& lines) {
    int pos = 50;
    int total = 0;

    for (const std::string& s : lines) {
        if (s.empty()) continue;

        char smer = s[0];
        int dist = std::stoi(s.substr(1));

        int razdaljaDoNic = 0;

        // razdalja do 0 glede na smer
        if (smer == 'R') {
            razdaljaDoNic = (100 - pos) % 100;
            if (razdaljaDoNic == 0) razdaljaDoNic = 100;
        }
        
        else if (smer == 'L') {
            razdaljaDoNic = pos % 100;
            if (razdaljaDoNic == 0) razdaljaDoNic = 100;
        }

        // Kolikokrat med rotacijo gremo mimo 0?
        if (dist >= razdaljaDoNic) {
            total += 1 + (dist - razdaljaDoNic) / 100;
        }

        //posodobi končno pozicijo
        if (smer == 'R') {
            pos = (pos + dist) % 100;
        }
        
        else if (smer == 'L') {
            pos = (pos - dist) % 100;
            if (pos < 0) pos += 100;
        }
    }

    return total;
}