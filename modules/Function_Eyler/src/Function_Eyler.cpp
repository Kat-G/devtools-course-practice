// Copyright 2023 Terina Alina

#include <gtest/gtest.h>
#include <utility>
#include <vector>
#include "include/Function_Eyler.h"

int Function_Eyler::Function_Euler(int n) {
    if (n <= 0) {
        throw std::invalid_argument(
        "Invalid value of argument. Must be positive");
    }

    if (n == 1 || n == 2) {
        return n;
    }

    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= std::sqrt(n); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    return count;
}
