#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "Patients.h"
#include <vector>

class MaxHeap {
private:
    std::vector<Patients> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    MaxHeap();

    bool empty() const;
    int size() const;

    void push(const Patients& patient);
    Patients pop();
};

#endif // MAXHEAP_H