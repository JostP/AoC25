#include "functions.h"
#include <sstream>
#include <iostream>

//razdeli ranges v dve spremenljivki a in b

std::vector<std::pair<long long, long long>> razcleniRanges(const std::string &line) {
    std::vector<std::pair<long long, long long>> ranges;
    std::stringstream ss(line);
    std::string token;

    while (std::getline(ss, token, ',')) {
        if (token.empty()) continue;
        size_t dash = token.find('-');
        long long a = std::stoll(token.substr(0, dash));
        long long b = std::stoll(token.substr(dash + 1));
        ranges.emplace_back(a, b);
    }
    return ranges;
}

std::string toString(long long number) {
    return std::to_string(number);
}

bool hasEvenLength(const std::string &s) {
    return (s.size() % 2 == 0);
}

bool checkPatternRepeated(const std::string &s) {
    if (!hasEvenLength(s)) return false;

    int half = s.size() / 2;
    return s.substr(0, half) == s.substr(half);
}

bool isRepeatedPattern(long long number) {
    std::string s = toString(number);
    return checkPatternRepeated(s);
}

std::vector<long long> findInvalidIDsInRange(long long start, long long end) {
    std::vector<long long> invalid;
    for (long long x = start; x <= end; x++) {
        if (isRepeatedPattern(x)) {
            invalid.push_back(x);
        }
    }
    return invalid;
}

std::vector<long long> findAllInvalidIDs(const std::vector<std::pair<long long, long long>> &ranges) {
    std::vector<long long> all;
    for (auto &r : ranges) {
        auto part = findInvalidIDsInRange(r.first, r.second);
        all.insert(all.end(), part.begin(), part.end());
    }
    return all;
}

// ------------------------------------------------------------
// Part 2
// ------------------------------------------------------------

long long sumIDs(const std::vector<long long> &ids) {
    long long s = 0;
    for (auto x : ids) s += x;
    return s;
}


bool isRepeatedSubstringAtLeastTwice(const std::string &s) {
    int n = s.size();

    for (int len = 1; len <= n/2; len++) {
        if (n % len != 0) continue;

        std::string chunk = s.substr(0, len);
        bool ok = true;

        for (int i = 0; i < n; i += len) {
            if (s.substr(i, len) != chunk) {
                ok = false;
                break;
            }
        }

        if (ok && n/len >= 2) return true;
    }
    return false;
}

long long sumInvalidIDsPart2(const std::vector<std::pair<long long,long long>>& ranges) {
    long long sum = 0;

    for (auto &r : ranges) {
        long long a = r.first;
        long long b = r.second;

        for (long long id = a; id <= b; id++) {
            std::string s = std::to_string(id);
            if (isRepeatedSubstringAtLeastTwice(s)) {
                sum += id;
            }
        }
    }

    return sum;
}