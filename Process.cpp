#include "Process.h"

Process::Process(int id, int arrival, int burst, int prio, int mem, bool io)
    : pid(id), arrival_time(arrival), burst_time(burst), priority(prio),
      state("NEW"), remaining_time(burst), waiting_time(0), turnaround_time(0),
      memory_required(mem), io_operations(io) {}

void Process::updateState(string newState) {
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
    cout << "PID: " << pid << " | State: " << state 
         << " | Arrival: " << arrival_time << " | Burst: " << burst_time 
         << " | Remaining: " << remaining_time << endl;
}
