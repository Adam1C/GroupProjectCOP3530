#include "MaxHeap.h"

MaxHeap::MaxHeap() {}

bool MaxHeap::empty() const {
    return heap.empty();
}

int MaxHeap::size() const {
    return heap.size();
}

void MaxHeap::push(const Patients& patient) {
    heap.push_back(patient);
    heapifyUp(heap.size() - 1);
}

Patients MaxHeap::pop() {
    if (empty()) {
        return null;
        throw std::out_of_range("Heap is empty");
    }

    Patients root = heap.front();
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);

    return root;
}

void MaxHeap::heapifyUp(int index) {
    int parentIndex = (index - 1) / 2;

    while (index > 0 && heap[index].getTriageValue() > heap[parentIndex].getTriageValue()) {
        std::swap(heap[index], heap[parentIndex]);
        index = parentIndex;
        parentIndex = (index - 1) / 2;
    }
}

void MaxHeap::heapifyDown(int index) {
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int largestIndex = index;

    if (leftChildIndex < heap.size() && heap[leftChildIndex].getTriageValue() > heap[largestIndex].getTriageValue()) {
        largestIndex = leftChildIndex;
    }

    if (rightChildIndex < heap.size() && heap[rightChildIndex].getTriageValue() > heap[largestIndex].getTriageValue()) {
        largestIndex = rightChildIndex;
    }

    if (largestIndex != index) {
        std::swap(heap[index], heap[largestIndex]);
        heapifyDown(largestIndex);
    }
}