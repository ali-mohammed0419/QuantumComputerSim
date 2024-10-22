#include "gates.h"
#include <cmath>

constexpr double PI = 3.141592653589793;

const std::vector<std::vector<Complex>> PAULI_X = {
    {0, 1},
    {1, 0}
};

const std::vector<std::vector<Complex>> PAULI_Y = {
    {0, Complex(0, -1)},
    {Complex(0, 1), 0}
};

const std::vector<std::vector<Complex>> PAULI_Z = {
    {1, 0},
    {0, -1}
};

const std::vector<std::vector<Complex>> HADAMARD = {
    {1 / std::sqrt(2), 1 / std::sqrt(2)},
    {1 / std::sqrt(2), -1 / std::sqrt(2)}
};

const std::vector<std::vector<Complex>> S_GATE = {
    {1, 0},
    {0, Complex(0, 1)}
};

const std::vector<std::vector<Complex>> T_GATE = {
    {1, 0},
    {0, std::polar(1.0, PI / 4)}
};