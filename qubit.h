#ifndef QUBIT_H
#define QUBIT_H

#include <complex>
#include <vector>

using Complex = std::complex<double>;
using QubitState = std::vector<Complex>;

class Qubit {
public:
    Qubit(); //|0>
    void applyGate(const std::vector<std::vector<Complex>>& gate);
    void printState() const;

private:
    QubitState state;
};

#endif
