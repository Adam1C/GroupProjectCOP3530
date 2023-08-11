#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "Patients.h"
#include <vector>
#include <iostream>

class MaxHeap {
private:
    std::vector<Patients> heap; // Store patients in a max heap structure

public:
    MaxHeap(); // Constructor

    bool empty() const; // Check if the heap is empty
    int size() const; // Get the number of patients in the heap

    void push(const Patients& patient); // Add a patient to the heap while maintaining max heap property
    Patients pop(); // Remove and return the patient with the highest priority
    const Patients& operator[](int index) const; // Access patient at a specific index
    void removeAt(int index); // Remove a patient at a specific index
    void heapifyUp(int index); // Fix the max heap property upwards from a specific index
    void heapifyDown(int index); // Fix the max heap property downwards from a specific index
    const Patients& peekAtPosition(int position) const; // Get the patient at a specific position without removing them
};

#endif // MAXHEAP_H
