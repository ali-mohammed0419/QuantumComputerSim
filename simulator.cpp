#include "simulator.h"
#include "gates.h"
#include <iostream>

void Simulator::run() {
    bool running = true;
    while (running) {
        int mainChoice;
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Create a new qubit\n";
        std::cout << "2. Delete an existing qubit\n";
        std::cout << "3. List all qubits\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> mainChoice;

        switch (mainChoice) {
        case 1: createQubit(); break;
        case 2: deleteQubit(); break;
        case 3: listQubits(); break;
        case 4: running = false; break;
        default: std::cout << "Invalid choice. Please enter a number between 1 and 4.\n"; break;
        }
    }
}

void Simulator::createQubit() {
    qubits[++qubitCounter] = Qubit();
    std::cout << "Created new qubit with ID: " << qubitCounter << "\n";
}

void Simulator::deleteQubit() {
    int deleteId;
    std::cout << "\nEnter the ID of the qubit to delete: ";
    std::cin >> deleteId;
    if (qubits.erase(deleteId)) {
        std::cout << "Deleted qubit with ID: " << deleteId << "\n";
    }
    else {
        std::cout << "No qubit found with ID: " << deleteId << "\n";
    }
}

void Simulator::listQubits() {
    if (qubits.empty()) {
        std::cout << "\nNo active qubits.\n";
    }
    else {
        std::cout << "\nListing all active qubits:\n";
        for (const auto& qubitPair : qubits) {
            std::cout << "Qubit ID: " << qubitPair.first << " - ";
            qubitPair.second.printState();
        }
    }
}

void Simulator::applyGateToQubit(int qubitID) {
    if (qubits.find(qubitID) == qubits.end()) {
        std::cout << "No qubit found with ID: " << qubitID << "\n";
        return;
    }

    int choice;
    bool simulating = true;

    while (simulating) {
        std::cout << "\nChoose a gate to apply to qubit " << qubitID << ":\n";
        std::cout << "1. Pauli-X\n";
        std::cout << "2. Pauli-Y\n";
        std::cout << "3. Pauli-Z\n";
        std::cout << "4. Hadamard\n";
        std::cout << "5. S Gate\n";
        std::cout << "6. T Gate\n";
        std::cout << "7. Stop applying gates\n";
        std::cout << "Enter your choice (1-7): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            qubits[qubitID].applyGate(PAULI_X);
            qubits[qubitID].printState();
            break;
        case 2:
            qubits[qubitID].applyGate(PAULI_Y);
            qubits[qubitID].printState();
            break;
        case 3:
            qubits[qubitID].applyGate(PAULI_Z);
            qubits[qubitID].printState();
            break;
        case 4:
            qubits[qubitID].applyGate(HADAMARD);
            qubits[qubitID].printState();
            break;
        case 5:
            qubits[qubitID].applyGate(S_GATE);
            qubits[qubitID].printState();
            break;
        case 6:
            qubits[qubitID].applyGate(T_GATE);
            qubits[qubitID].printState();
            break;
        case 7:
            simulating = false;
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 7.\n";
            break;
        }
    }
}
