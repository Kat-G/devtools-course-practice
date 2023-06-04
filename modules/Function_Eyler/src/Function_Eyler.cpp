// Copyright 2023 Terina Alina

#include <gtest/gtest.h>
#include <utility>
#include "include/Function_Eyler.h"

int Function_Eyler::Function_Euler(int n) {
    if (n <= 0) {
        throw std::invalid_argument(
        "Invalid value of argument. Must be positive");
    }
    if (n == 1 || n == 2) {
        return n;
    }

    int count = 1;

    for (int i = 3; i <= n / 2; i++) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            count++;
        }
    }

    return count;
}
