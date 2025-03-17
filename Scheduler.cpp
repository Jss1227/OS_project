#include "Scheduler.h"
#include <algorithm>

// First-Come, First-Served (FCFS)
void FCFS(std::vector<Process>& processes) {
    int current_time = 0;
    for (auto& p : processes) {
        if (current_time < p.arrival_time) {
            current_time = p.arrival_time;
        }
        p.completion_time = current_time + p.burst_time;
        p.turnaround_time = p.completion_time - p.arrival_time;
        p.waiting_time = p.turnaround_time - p.burst_time;
        current_time = p.completion_time;
    }
}

// Shortest Job First (Non-Preemptive)
void SJF_NonPreemptive(std::vector<Process>& processes) {
    std::vector<bool> completed(processes.size(), false);
    int current_time = 0, completed_count = 0;

    while (completed_count < processes.size()) {
        int shortest_job = -1;
        for (int i = 0; i < processes.size(); i++) {
            if (!completed[i] && processes[i].arrival_time <= current_time) {
                if (shortest_job == -1 || processes[i].burst_time < processes[shortest_job].burst_time) {
                    shortest_job = i;
                }
            }
        }

        if (shortest_job == -1) {
            current_time++;
        } else {
            current_time += processes[shortest_job].burst_time;
            processes[shortest_job].completion_time = current_time;
            processes[shortest_job].turnaround_time = processes[shortest_job].completion_time - processes[shortest_job].arrival_time;
            processes[shortest_job].waiting_time = processes[shortest_job].turnaround_time - processes[shortest_job].burst_time;
            completed[shortest_job] = true;
            completed_count++;
        }
    }
}
