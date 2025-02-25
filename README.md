# OS_project

## Team Members
Jorge Saenz

## Project Overview
This is a basic operating system simulator written in C++. It includes:

- **Boot sequence**: Displays a startup message.
- **User authentication**: Requires a password before granting access.
- **Process management**: Simulates the creation and execution of processes.

## Process Class Explanation
The `Process` class represents a simulated OS process with the following attributes:

- `pid`: Unique process ID.
- `arrival_time`: The time when the process enters the system.
- `burst_time`: Total CPU execution time required.
- `priority`: Process priority (if applicable).
- `state`: The current state of the process (e.g., NEW, READY, RUNNING, TERMINATED).
- `remaining_time`: The CPU time left for execution.
- `waiting_time`: Total time the process spends waiting in the ready queue.
- `turnaround_time`: The total time from arrival to completion.
- `memory_required`: The amount of memory required by the process.
- `io_operations`: Boolean flag indicating if the process performs I/O operations.

### Implemented Methods
- **`Process()`**: Initializes the process with given parameters.
- **`updateState()`**: Changes the process state.
- **`execute()`**: Simulates execution, decreasing `remaining_time`. Terminates process when execution completes.
- **`displayProcess()`**: Displays process information.

## How to Run
Clone the repository:
```sh
git clone https://github.com/Jss1227/OS_project.git
```


