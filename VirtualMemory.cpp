#include <iostream>
#include "VirtualMemory.h"
#include "memory_constants.h"

int translateAddress(const std::vector<PageTableEntry>& pageTable, int virtualAddress) {
    int pageNumber = virtualAddress / PAGE_SIZE;
    int offset = virtualAddress % PAGE_SIZE;

    if (pageNumber >= pageTable.size()) {
        std::cerr << "Invalid virtual address: exceeds page table size.\n";
        return -1;
    }

    const PageTableEntry& entry = pageTable[pageNumber];
    if (!entry.valid) {
        std::cerr << "Page fault: page " << pageNumber << " is not loaded.\n";
        return -1;
    }

    int physicalAddress = entry.frameNumber * PAGE_SIZE + offset;
    return physicalAddress;
}

void readMemory(const std::vector<PageTableEntry>& pageTable, int virtualAddress) {
    int physicalAddress = translateAddress(pageTable, virtualAddress);
    if (physicalAddress != -1) {
        std::cout << "Read from physical address: " << physicalAddress << std::endl;
    }
}

void writeMemory(std::vector<PageTableEntry>& pageTable, int virtualAddress) {
    int pageNumber = virtualAddress / PAGE_SIZE;
    int offset = virtualAddress % PAGE_SIZE;

    if (pageNumber >= pageTable.size()) {
        std::cerr << "Invalid virtual address: exceeds page table size.\n";
        return;
    }

    PageTableEntry& entry = pageTable[pageNumber];
    if (!entry.valid) {
        std::cerr << "Page fault on write: page " << pageNumber << " is not loaded.\n";
        return;
    }

    entry.dirty = true;
    int physicalAddress = entry.frameNumber * PAGE_SIZE + offset;
    std::cout << "Wrote to physical address: " << physicalAddress << " (Page " << pageNumber << " marked dirty)\n";
}

