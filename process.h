#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <string>
using namespace std;

class Process {
private:
    int pid;               // Unique Process ID
    int arrival_time;      // Arrival time of the process in the system
    int burst_time;        // Total execution time required
    int priority;          // Priority level of the process (if applicable)
    string state;          // Process state: NEW, READY, RUNNING, WAITING, TERMINATED
    int remaining_time;    // Remaining CPU time for execution
    int waiting_time;      // Time spent in the ready queue
    int turnaround_time;   // Total time from arrival to completion
    int memory_required;   // Memory required by the process
    bool io_operations;    // Indicates if the process has I/O operations

public:
    /**
     * Constructor to initialize the process attributes.
     * @param id: Process ID
     * @param arrival: Time when process enters the system
     * @param burst: Total execution time required
     * @param prio: Process priority
     * @param mem: Memory required by the process
     * @param io: Boolean flag for I/O operations
     */
    Process(int id, int arrival, int burst, int prio, int mem, bool io);

    /**
     * Updates the state of the process (e.g., NEW -> READY -> RUNNING).
     * @param newState: The new state of the process
     */
    void updateState(string newState);

    /**
     * Executes the process for a given time, reducing remaining execution time.
     * If remaining time reaches 0, the process state is set to TERMINATED.
     * @param time: The amount of CPU time the process runs
     */
    void execute(int time);

    /**
     * Displays process information.
     */
    void displayProcess() const;
};

#endif
