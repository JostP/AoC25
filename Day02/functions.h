#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <utility>

// ---------------------------------------------------------
// Part 1
// ---------------------------------------------------------

std::vector<std::pair<long long, long long>> razcleniRanges(const std::string &line);

bool isRepeatedPattern(long long number);
std::string toString(long long number);
bool hasEvenLength(const std::string &s);
bool checkPatternRepeated(const std::string &s);

std::vector<long long> findInvalidIDsInRange(long long start, long long end);
std::vector<long long> findAllInvalidIDs(const std::vector<std::pair<long long, long long>> &ranges);

long long sumIDs(const std::vector<long long> &ids);

// ---------------------------------------------------------
// Part 2
// ---------------------------------------------------------

bool isRepeatedSubstringAtLeastTwice(const std::string &s);

long long sumInvalidIDsPart2(const std::vector<std::pair<long long,long long>>& ranges);

#endif