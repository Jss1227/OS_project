#include <iostream>
#include <vector>
#include "auth.h"
#include "Process.h"
#include "Scheduler.h"

using namespace std;

void bootSystem() {
    cout << "Booting up the BasicOS...\n";
}

int main() {
    bootSystem();

    if (authenticateUser()) {
        cout << "Access granted. Welcome to BasicOS!\n";

        // Create process list
        vector<Process> processes;
        processes.emplace_back(1, 0, 5, 1, 16, false);
        processes.emplace_back(2, 2, 3, 2, 12, true);
        processes.emplace_back(3, 4, 7, 1, 20, false);

        // Initialize virtual memory (e.g., assume 4KB pages, memory in KB)
        int pageSize = 4; // KB
        for (auto& proc : processes) {
            int numPages = (proc.getMemoryRequired() + pageSize - 1) / pageSize;
            proc.initPageTable(numPages);
        }

        // Run FCFS scheduling
        cout << "\nRunning FCFS Scheduling...\n";
        FCFS(processes);

        // Display results
        for (const auto& p : processes) {
            p.displayProcess(); // Make sure this prints turnaround & waiting time
        }

    } else {
        cout << "Access denied. Exiting...\n";
    }

    return 0;
}



