#ifndef VIRTUAL_MEMORY_H
#define VIRTUAL_MEMORY_H

struct PageTableEntry {
    bool valid;
    int frameNumber;
    bool dirty;
};

int translateAddress(const std::vector<PageTableEntry>& pageTable, int virtualAddress);
void readMemory(const std::vector<PageTableEntry>& pageTable, int virtualAddress);
void writeMemory(std::vector<PageTableEntry>& pageTable, int virtualAddress);

#endif
