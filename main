#include <iostream>
#include <vector>
#include "auth.h"
#include "Process.h"

using namespace std;

void bootSystem() {
    cout << "Booting up the BasicOS...\n";
}

int main() {
    bootSystem();
    
    if (authenticateUser()) {
        cout << "Access granted. Welcome to BasicOS!\n";
        
        // Create a few sample processes
        vector<Process> processes;
        processes.emplace_back(1, 0, 5, 1, 1024, false);
        processes.emplace_back(2, 2, 3, 2, 512, true);

        // Display initial process states
        cout << "\nInitial Process States:\n";
        for (const auto& process : processes) {
            process.displayProcess();
        }

        // Simulating process execution
        processes[0].updateState("RUNNING");
        processes[0].execute(2);

        cout << "\nUpdated Process States:\n";
        for (const auto& process : processes) {
            process.displayProcess();
        }
    } else {
        cout << "Access denied. Exiting...\n";
    }

    return 0;
}

