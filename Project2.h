// Guards for the header file
#ifndef PROJECT2_H
#define PROJECT2_H
#include <vector>

class MinHeap {
    private:
        std::vector<int> heap; // Vector to store heap elements    
        void percolateDown(int i); // Function to maintain heap property through build
        void percolateUp(int i); // To be used in the insertion function

    public:
        MinHeap(std::vector<int> heap); // Initialize heap with the data vector
        void buildHeap(); // Build heap function to be used
        void printHeap() const; // Function to print heap elements
        std::vector<int> getHeap() const; // Function to return the internal heap vector
        void insert(int value); // Function to insert a new value into the heap
        int deleteMin(); // Function to delete the minimum element (root) from the heap and return it
        bool isEmpty() const; // Checks if the heap is empty or not
        void naiveMerge(const MinHeap& other); // Naive merge function to combine two heaps
        void efficientMerge(const MinHeap& other); // Efficient merge function to combine two heaps
        std::vector<int> heapSort(); // Heap sort function
};

// Helper function, had errors defining it in class and used AI help to figure out it needs to be outside the class
MinHeap DivideAndConquer(const std::vector<int>& data, int divideFactor);

#endif // Closes the guard for the header file