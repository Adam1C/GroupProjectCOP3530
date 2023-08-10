#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "Patients.h"
#include <vector>
#include <iostream>

class MaxHeap {
private:
    std::vector<Patients> heap;

public:
    MaxHeap();

    bool empty() const;
    int size() const;

    void push(const Patients& patient);
    Patients pop();

    const Patients& operator[](int index) const;
    void removeAt(int index);
    void heapifyUp(int index);
    void heapifyDown(int index);
    const Patients& peekAtPosition(int position) const;
};

#endif // MAXHEAP_H
