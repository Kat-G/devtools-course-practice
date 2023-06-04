// Copyright 2023 Terina Alina

#include <gtest/gtest.h>
#include <utility>
#include "include/Function_Eyler.h"

int Function_Eyler::Function_Euler(int n) {
    if (n <= 0) {
        throw std::invalid_argument(
        "Invalid value of argument. Must be positive");
    }int count = 0;
    std::vector<bool> isPrime(n, true);

    for (int i = 2; i <= sqrt(n); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    return count;
}
