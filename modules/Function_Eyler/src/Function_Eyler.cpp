// Copyright 2023 Terina Alina

#include <gtest/gtest.h>
#include <utility>
#include <cmath>
#include "include/Function_Eyler.h"

int Function_Eyler::Function_Euler(int n) {
    if (n <= 0) {
        throw std::invalid_argument(
        "Invalid value of argument. Must be positive");
    }

    if (n == 1 || n == 2) {
        return n;
    }

    int count = n;
    for (int i = 2; pow(i, 2) <= n; i++) {
        if (n % i == 0) {
            count -= count / i;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1) count -= count / n;

    return count;
}
