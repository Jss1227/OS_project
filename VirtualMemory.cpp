#include <iostream>
#include "VirtualMemory.h"
#include "memory_constants.h"

int translateAddress(const std::vector<PageTableEntry>& pageTable, int virtualAddress) {
    int pageNumber = virtualAddress / PAGE_SIZE;
    int offset = virtualAddress % PAGE_SIZE;

    if (pageNumber >= pageTable.size()) {
        std::cerr << "Invalid virtual address\n";
        return -1;
    }

    if (!pageTable[pageNumber].valid) {
        std::cerr << "Page fault at page " << pageNumber << "\n";
        return -1;
    }

    int frameNumber = pageTable[pageNumber].frameNumber;
    return frameNumber * PAGE_SIZE + offset;
}

void readMemory(const std::vector<PageTableEntry>& pageTable, int virtualAddress) {
    int physicalAddress = translateAddress(pageTable, virtualAddress);
    if (physicalAddress != -1) {
        std::cout << "Read from physical address: " << physicalAddress << "\n";
    }
}

void writeMemory(std::vector<PageTableEntry>& pageTable, int virtualAddress) {
    int pageNumber = virtualAddress / PAGE_SIZE;
    if (pageNumber < pageTable.size() && pageTable[pageNumber].valid) {
        pageTable[pageNumber].dirty = true;
        std::cout << "Wrote to page " << pageNumber << ", marked dirty.\n";
    }
}
