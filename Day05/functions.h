#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <utility>
#include <istream>

void preberiVhod(
    std::istream& file,
    std::vector<std::pair<unsigned long int, unsigned long int>>& obmocja,
    std::vector<unsigned long int>& idji
);

int prestejSvezeIDje(
    const std::vector<std::pair<unsigned long int, unsigned long int>>& obmocja,
    const std::vector<unsigned long int>& idji
);

unsigned long int prestejVseSveze(
    std::vector<std::pair<unsigned long int, unsigned long int>> obmocja
);

#endif
