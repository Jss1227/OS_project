#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <string>
using namespace std;

class Process {
private:
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    string state;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int memory_required;
    bool io_operations;

public:
    Process(int id, int arrival, int burst, int prio, int mem, bool io);

    void updateState(string newState);
    void execute(int time);
    void displayProcess() const;
};

#endif
