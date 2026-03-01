// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>


bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
  }
  if (value == 2) {
    return true;
  }
  if (value % 2 == 0) {
    return false;
  }
  uint64_t limit = sqrt(value);
  for (uint64_t i = 3; i <= limit; i += 2) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    return 0;
  }
  uint64_t counter = 0;
  uint64_t number = 0;
  while (counter < n) {
    number++;
    f (checkPrime(number)) {
      counter++;
    }
  }
  return number;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t a = value + 1;
  while (true) {
    if (checkPrime(a)) {
      return a;
    }
    a++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  uint64_t num = 2;
  while (num < hbound) {
    if (checkPrime(num)) {
      sum += num;
    }
    ++num;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t counter = 0;
  for (uint64_t n = lbound; n + 2 < hbound; n++) {
    if (checkPrime(n) && checkPrime(n + 2)) {
      counter++;
    }
  }
  return counter;
}
