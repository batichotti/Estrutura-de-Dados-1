#pragma once

#include <chrono>
#include <string>
#include <iostream>
#include <stddef.h>

class Cronometro {
    std::string nome;
    std::chrono::time_point<std::chrono::high_resolution_clock> clock;

    public:
    Cronometro(const std::string &nome = ""): nome(nome) {
        clock = std::chrono::high_resolution_clock::now();
    }
    ~Cronometro() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - clock);
        const double res = duration.count();
        const auto a = res / 1000;      // milliseconds
        const auto b = res / 1000000;   // seconds
        std::cout << "Tempo decorrido para " << nome << ": " << res << " us; " << a << " ms; " << b << " s.\n";
    }
};