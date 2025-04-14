#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Structure for a page table entry
struct PageTableEntry {
    bool valid;
    int frameNumber;
    bool dirty;
};

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

    vector<PageTableEntry> pageTable;  // Each process has its own page table

public:
    Process(int id, int arrival, int burst, int prio, int mem, bool io);

    void updateState(string newState);
    void execute(int time);
    void displayProcess() const;

    // Initializes the page table with invalid entries
    void initPageTable(int numPages);

    // Optional: add more memory-related methods if needed later
};

#endif

