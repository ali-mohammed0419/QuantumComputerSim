#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "qubit.h"
#include <map>

class Simulator {
public:
    void run();

private:
    std::map<int, Qubit> qubits;
    int qubitCounter = 0;

    void createQubit();
    void deleteQubit();
    void listQubits();
    void applyGateToQubit(int qubitID);
};

#endif
