// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>
#include <cmath>

bool checkPrime(uint64_t value) {
    if (value <= 1) return false;
    if (value == 2) return true;
    if (value % 2 == 0) return false;
    
    uint64_t limit = static_cast<uint64_t>(std::sqrt(static_cast<double>(value)));
    for (uint64_t i = 3; i <= limit; i += 2) {
        if (value % i == 0) return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) return 0;
    
    uint64_t counter = 0;
    uint64_t number = 0;
    while (counter < n) {
        number++;
        if (checkPrime(number)) {
            counter++;
        }
    }
    return number;
}

uint64_t nextPrime(uint64_t value) {
    if (value < 2) return 2;
    
    uint64_t a = value + 1;
    while (!checkPrime(a)) {
        a++;
    }
    return a;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t num = 2; num < hbound; ++num) {
        if (checkPrime(num)) {
            sum += num;
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t counter = 0;
    for (uint64_t n = lbound; n <= hbound - 2; n++) {
        if (checkPrime(n) && checkPrime(n + 2)) {
            counter++;
        }
    }
    return counter;
}
