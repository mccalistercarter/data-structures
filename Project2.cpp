/*
    All function declarations to be used in the main.cpp file for testing
*/

#include <iostream>
#include <algorithm> // Included so that the "swap" function can be used
#include "Project2.h"
using namespace std;

// Constructor to store the input vector into the heap array
MinHeap::MinHeap(vector<int> data) {
    heap = data;
}

void MinHeap::percolateDown(int i) {
    int smallest = i; // Initialize smallest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index

    // Check if left child exists and is smaller than root
    if (left < heap.size() && heap[left] < heap[smallest]) {
        smallest = left;
    }
    
    // Check same for the right child
    if (right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heap[i], heap[smallest]); // Swap root with smallest
        percolateDown(smallest); // Recursively percolate down the affected subtree to fix as needed
    }
}

void MinHeap::buildHeap() {
    for (int i = heap.size() / 2 - 1; i >= 0; i--) {
        percolateDown(i); // Call percolateDown for each non-leaf node ensuring the heap properties met
    }
}

// Added a printHeap function to aid in debugging rather than continously creating the function
void MinHeap::printHeap() const {
    for (int val : heap) {
        cout << val << " "; // Print each element in the heap
    }
    cout << endl; // New line after printing all elements
}

vector<int> MinHeap::getHeap() const {
    return heap; // Return the internal heap vector
}

// AI sidebar in VScode was used to decopher errors here and added the "&" character
MinHeap DivideAndConquer(const std::vector<int>& data, int divideFactor) {
    // Used AI: "Is there a simple way to divide a vector into N sub-vectors in C++?"
    vector<vector<int>> subarrays(divideFactor); // Creates 4 subarrays

    int tempSize = data.size() / divideFactor; // Fills the 4 subarrays with data
    for (int i = 0; i < divideFactor; i++) {
        int start = i * tempSize; int end;
        if (i == divideFactor - 1) {
            end = data.size(); // Last subarray takes the remainder
        } else {
            end = start + tempSize;
        }
        subarrays[i] = vector<int>(data.begin() + start, data.begin() + end);
    }

    vector<MinHeap> subHeaps; // Builds heaps out of each of the subarrays
    for (int i = 0; i < divideFactor; ++i) {
        MinHeap h(subarrays[i]);
        h.buildHeap();
        // Used GPT: "How do I append one item to another in C++?" giving me the push_back function
        subHeaps.push_back(h); // Append each sub-heaps vector to the end
    }

    vector<int> merged; // Merges the sub-heaps back into one array
    for (const MinHeap& h : subHeaps) {
        vector<int> heapData = h.getHeap(); // Get the internal vector of the heap
        merged.insert(merged.end(), heapData.begin(), heapData.end()); // Append all elements from that vector to the end of merged
    }

    MinHeap finalHeap(merged); // Create final heap with merged data
    finalHeap.buildHeap(); // Build the final heap to ensure heap properties are maintained
    return finalHeap;
}

void MinHeap::percolateUp(int i) {
    if (i == 0) return; // It at the root, we are done
    int parent = (i-1)/2;
    if (heap[i] < heap[parent]) { // If the curent node is smaller than the parent node
        swap(heap[i], heap[parent]); // Swap with parent
        percolateUp(parent); // Recursively percolate up the affected subtree to fix as needed
    }
}

void MinHeap::insert(int value) {
    heap.push_back(value); // Insert the new value at the end of the heap
    percolateUp(heap.size() - 1); // Percolate up from the last index to maintain heap property
}

// Used the sidebar bot to resolve errors and update this code to better run with the sort function later on; prompt included in main.cpp
int MinHeap::deleteMin() {
    if (heap.empty()) return -1; // If the heap is empty, return sentinel value
    int minVal = heap[0];
    heap[0] = heap.back(); // Move last element to the root (replaces the minimum value)
    heap.pop_back(); // Remove the last element from the list
    if (!heap.empty()) percolateDown(0); // Percolate down only if heap still has elements
    return minVal;
}

// Also adding an isEmpty function to use in the main.cpp testing
bool MinHeap::isEmpty() const {
    return heap.empty(); // Returns true if the heap is empty, false otherwise
}

void MinHeap::naiveMerge(const MinHeap& other) {
    vector<int> otherHeap = other.getHeap(); // Get the internal vector of the other heap
    heap.insert(heap.end(), otherHeap.begin(), otherHeap.end()); // Append all elements from that vector to the end of this heap
    buildHeap(); // Rebuild the heap to maintain heap properties
}

void MinHeap::efficientMerge(const MinHeap& other) {
    vector<int> otherHeap = other.getHeap(); // Get the internal vector of the other heap
    for (int val : otherHeap) {
        insert(val); // Insert each element from the other heap individually, maintaining heap properties
    }
}

vector<int> MinHeap::heapSort() {
    vector<int> sorted; // Vector to store sorted elements
    while (!isEmpty()) {
        sorted.push_back(deleteMin()); // Get the minimum element (root)
    }
    return sorted; // Return the sorted vector
}