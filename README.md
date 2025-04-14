# BasicOS - Operating System Simulator

## Team Members
- Jorge Saenz

## Project Overview

**BasicOS** is a simplified operating system simulator developed in C++ that demonstrates core operating system concepts. This project includes:

- Boot sequence simulation
- User authentication
- Process creation and scheduling (FCFS & SJF)
- Virtual memory management with page tables and address translation

---

## Features

### 🔧 Boot Sequence
Simulates a basic boot-up process to initialize the OS environment.

### 🔐 User Authentication
- Secure login using hardcoded credentials.
- Prompts the user for a username and password.
- Access is only granted if both match the predefined values.
  - **Username**: `admin`
  - **Password**: `password123`

### 👨‍💻 Process Management
- Creates processes with attributes:
  - Process ID (PID)
  - Arrival Time
  - Burst Time
  - Priority
  - Memory Requirement
  - I/O Operation Flag
- Tracks each process state:
  - NEW → READY → RUNNING → WAITING → TERMINATED

### 🧮 Scheduling Algorithms
Supports basic CPU scheduling:

#### ✅ FCFS (First-Come, First-Served)
- Non-preemptive algorithm
- Executes processes in order of arrival

#### 🔜 SJF (Shortest Job First)
- Implementation in progress
- Will support both preemptive and non-preemptive modes

#### Metrics Calculated:
- Completion Time
- Turnaround Time
- Waiting Time
- Average Turnaround & Waiting Times

### 💾 Virtual Memory Management
Implements a basic simulation of virtual memory:

- **Virtual Address Translation**
  - Uses a fixed page size (e.g., 4KB)
  - Simulates mapping from virtual addresses to physical frames

- **Page Tables**
  - Each process maintains its own page table
  - Includes:
    - Frame Number
    - Valid Bit
    - Dirty Bit (optional)

- **Configurable Memory**
  - Define virtual and physical memory sizes at initialization

---

## How to Run
Clone the repository:
```sh
git clone https://github.com/Jss1227/OS_project.git
```
Compile the project:
```sh
g++ main.cpp auth.cpp Process.cpp Scheduler.cpp VirtualMemory.cpp -o BasicOS
```
Run the program:
```sh
./BasicOS
```

