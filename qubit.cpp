#include "qubit.h"
#include <iostream>

Qubit::Qubit() : state({ Complex(1, 0), Complex(0, 0) }) {}

void Qubit::applyGate(const std::vector<std::vector<Complex>>& gate) {
    QubitState newState(2);
    for (int i = 0; i < 2; ++i) {
        newState[i] = 0;
        for (int j = 0; j < 2; ++j) {
            newState[i] += gate[i][j] * state[j];
        }
    }
    state = newState;
}

void Qubit::printState() const {
    std::cout << "Qubit state: [" << state[0] << ", " << state[1] << "]\n";
}