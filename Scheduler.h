#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Process.h"

void FCFS(std::vector<Process>& processes);
void SJF_NonPreemptive(std::vector<Process>& processes);
void SJF_Preemptive(std::vector<Process>& processes); // If needed

#endif
