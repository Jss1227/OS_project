#include "Process.h"
#include "memory_constants.h"  // for NUM_PAGES

Process::Process(int id, int arrival, int burst, int prio, int mem, bool io)
    : pid(id), arrival_time(arrival), burst_time(burst), priority(prio),
      state("NEW"), remaining_time(burst), waiting_time(0), turnaround_time(0),
      memory_required(mem), io_operations(io) {
    initPageTable(NUM_PAGES); // Initialize the page table during process creation
}

void Process::updateState(std::string newState) {
    state = newState;
}

void Process::execute(int time) {
    if (remaining_time > 0) {
        remaining_time -= time;
        if (remaining_time <= 0) {
            state = "TERMINATED";
            remaining_time = 0;
        }
    }
}

void Process::displayProcess() const {
    std::cout << "PID: " << pid << " | State: " << state 
              << " | Arrival: " << arrival_time << " | Burst: " << burst_time 
              << " | Remaining: " << remaining_time << std::endl;
}

void Process::initPageTable(int numPages) {
    pageTable.resize(numPages);
    for (auto& entry : pageTable) {
        entry.valid = false;
        entry.frameNumber = -1;
        entry.dirty = false;
    }
}
