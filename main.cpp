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

        // Define a list of processes
        vector<Process> processes = {
            {1, 0, 5, 0, 0, 0, 0},
            {2, 2, 3, 0, 0, 0, 0},
            {3, 4, 7, 0, 0, 0, 0}
        };

        // Run FCFS Scheduling
        cout << "\nRunning FCFS Scheduling...\n";
        FCFS(processes);
        for (const auto& p : processes) {
            cout << "PID: " << p.pid << ", Turnaround Time: " << p.turnaround_time
                 << ", Waiting Time: " << p.waiting_time << "\n";
        }

    } else {
        cout << "Access denied. Exiting...\n";
    }

    return 0;
}


