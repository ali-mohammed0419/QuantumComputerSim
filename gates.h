#ifndef GATES_H
#define GATES_H

#include <complex>
#include <vector>

using Complex = std::complex<double>;
using QubitState = std::vector<Complex>;

extern const std::vector<std::vector<Complex>> PAULI_X;
extern const std::vector<std::vector<Complex>> PAULI_Y;
extern const std::vector<std::vector<Complex>> PAULI_Z;
extern const std::vector<std::vector<Complex>> HADAMARD;
extern const std::vector<std::vector<Complex>> S_GATE;
extern const std::vector<std::vector<Complex>> T_GATE;

#endif
