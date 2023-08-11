#include "MaxHeap.h"

MaxHeap::MaxHeap() {} // Default constructor

bool MaxHeap::empty() const {
    return heap.empty(); // Check if the heap is empty
}

int MaxHeap::size() const {
    return heap.size(); // Get the number of patients in the heap
}

void MaxHeap::push(const Patients& patient) {
    heap.push_back(patient); // Add patient to the end of the heap
    heapifyUp(heap.size() - 1); // Fix the heap property upwards
}

Patients MaxHeap::pop() {
    if (empty())
    {
        throw std::out_of_range("Heap is empty"); // Throw an exception if heap is empty
    }

    Patients root = heap.front();  // Get the root patient (highest priority)
    heap[0] = heap.back(); // Move the last patient to the root position
    heap.pop_back(); // Remove the last element
    heapifyDown(0); // Fix the heap property downwards
    return root; // Return the removed root patient
}

void MaxHeap::heapifyUp(int index) {
    int parentIndex = (index - 1) / 2;
    // Compare the current patient's triage value with its parent's triage value
    while (index > 0 && heap[index].getTriageValue() > heap[parentIndex].getTriageValue())
    {
        std::swap(heap[index], heap[parentIndex]); // Swap the patients
        index = parentIndex; // Move upwards in the heap
        parentIndex = (index - 1) / 2;
    }
}

void MaxHeap::heapifyDown(int index) {
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int largestIndex = index;
    // Compare the current patient's triage value with its children's triage values
    if (leftChildIndex < heap.size() && heap[leftChildIndex].getTriageValue() > heap[largestIndex].getTriageValue())
    {
        largestIndex = leftChildIndex; // Update the largest index
    }

    if (rightChildIndex < heap.size() && heap[rightChildIndex].getTriageValue() > heap[largestIndex].getTriageValue())
    {
        largestIndex = rightChildIndex; // Update the largest index
    }

    // Swap with the largest child if necessary and continue downwards
    if (largestIndex != index)
    {
        std::swap(heap[index], heap[largestIndex]);
        heapifyDown(largestIndex);
    }
}

const Patients& MaxHeap::operator[](int index) const {
    return heap[index]; // Access patient at a specific index
}

const Patients& MaxHeap::peekAtPosition(int position) const {
    if (position < 0 || position >= heap.size())
    {
        throw std::out_of_range("Invalid position"); // Throw an exception for an invalid position
    }
    return heap[position]; // Access patient at a specific position without removing them
}


void MaxHeap::removeAt(int index) {
    if (index < 0 || index >= heap.size())
    {
        throw std::out_of_range("Index out of bounds"); // Throw an exception for an invalid position
    }

    std::swap(heap[index], heap.back()); // Swap the element to be removed with the last element
    heap.pop_back(); // Remove the last element

    // Rebalance the heap based on the patient's triage value
    if (index > 0 && heap[index].getTriageValue() > heap[(index - 1) / 2].getTriageValue()) {
        heapifyUp(index); // Fix upwards if necessary
    } else {
        heapifyDown(index); // Fix upwards if necessary
    }
}
