/*
    GPT model used to write the compliation statement clearly and efficiently
    With directory selected run g++ main.cpp Project2.cpp -o project2.exe; if ($?) { .\project2.exe }
*/

#include <iostream>
#include <vector>
#include "Project2.h"
using namespace std;

int main() {
    /* 
        Problem 1: Building a Heap Testing
        AI used here with prompt: "Can you help me understand how to get a randomly generated vector of numbers
        in C++ to test functions with?" 
        Time complexity of heap build is O(n)
    */
    vector<int> data(10);
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < 10; i++) {
        data[i] = rand() % 100; // Random integers between 0 and 99
    }
    cout<< "Problem 1: " << endl;
    cout << "Original Data: ";
    for (int val : data) cout << val << " "; cout << endl;
    MinHeap minHeap(data); // Create the heap with the random data
    minHeap.buildHeap(); // Build the min-heap
    cout << "After building heap: ";
    minHeap.printHeap(); // Print the heap after building to check

    /*
        Problem 2: Divide and Conquer Heap Testing
        For problem 2, we would implement a divide and conquer approach to build the heap. This would involve dividing the
        array into smaller subarrays, building heaps for those subarrays (4 in this example), and then merging them back together and running buildHeap()
        one more time to confirm that heap properties are maintained. DivideAndConquer function is implemented in Project2.cpp
        Time complexity of O(n) using the naive merge but more efficient method built later could be used for O(n log n) time, faster for smaller sets
        This approach is beneficial because building smaller heaps is faster and merging them reduces the overall complexity compared to building one large heap directly. More scalable.
    */
    cout << "\nProblem 2: " << endl;
    MinHeap finalHeap = DivideAndConquer(data, 4); // Divide into 4 subarrays and build heap
    cout << "Original Data: ";
    for (int val : data) cout << val << " "; cout << endl; // Same function as above
    cout << "Final heap after Divide and Conquer: ";
    finalHeap.printHeap(); // Print the final heap to check

    /*
        Problem 3: Insertion and Percolate Up Testing
        For problem 3, we will test the insertion function which uses percolateUp to maintain heap properties after adding a new element.
        Time compleixty of O(log n) though often is shorter but worst case is O(log n) going from leaf to root
    */
    cout << "\nProblem 3: " << endl;
    int newValue = rand() % 100; // Generate a new random value to insert at the end of our heap
    // Use the heap from problem 2 for this test
    cout << "Heap before insertion: ";
    finalHeap.printHeap(); // Print the heap before insertion
    cout << "Inserting new value: " << newValue << endl;
    finalHeap.insert(newValue); // Insert the new value
    cout << "Heap after insertion: ";
    finalHeap.printHeap(); // Print the heap after insertion to check

    /*
        Problem 4: Deletion of Minimum Element Testing
        For problem 4, we will test the deletion of the minimum element (the root) from the heap.
        Time complexity of O(log n) as it requires percolating down from the root to restore heap properties which is O(log n)
    */
    cout << "\nProblem 4: " << endl;
    cout << "Heap before deleting minimum element: ";
    finalHeap.printHeap(); // Print the heap before deletion, use the heap from problem 3
    finalHeap.deleteMin(); // Delete the minimum element
    cout << "Heap after deleting minimum element: ";
    finalHeap.printHeap(); // Print the heap after deletion to check    
    cout << "Heap after deleting second minimum element: ";
    finalHeap.deleteMin(); // Delete the minimum element again
    finalHeap.printHeap(); // Print the heap after deletion to check

    /*
        Problem 5: Merge Testing
        First test naive merge function to combine two heaps, doing it with the two random heaps created below
        Then test the efficient merge function (insert each of heap 2 one by one into heap 1 using the insert function)
        Time complexity of O(n + m) for naive merge where n and m are sizes of the two heaps, as we concatenate and then build heap
        Time complexity of O(m log(n + m)) for efficient merge where n and m are sizes of the two heaps, as we insert each element of the second heap into the first
        Space complexity of O(n) for naive merge but O(1) additional space for efficient merge as we insert in place
        When both heaps are large, the naive merge is generally more efficient due to its linear time complexity. However, for smaller heaps or when
        memory usage is a concern, the efficient merge may be preferred despite its higher time complexity.
    */
    vector<int> data1(5);
    for (int i = 0; i < 5; i++) {
        data1[i] = rand() % 100; // Random integers between 0 and 99
    }
    MinHeap heap1(data1);
    heap1.buildHeap();
    vector<int> data2(5);
    for (int i = 0; i < 5; i++) {
        data2[i] = rand() % 100; // Random integers between 0 and 99
    }
    MinHeap heap2(data2);
    heap2.buildHeap();
    cout << "\nProblem 5: " << endl;
    cout << "Heap 1: "; heap1.printHeap();
    cout << "Heap 2: "; heap2.printHeap();
    heap1.naiveMerge(heap2); // Merge heap2 into heap1 using naive merge
    cout << "Merged Heap (Naive Merge): "; heap1.printHeap();
    // Efficient merge test, start by recreating the heaps to use
    MinHeap heap3(data1); heap3.buildHeap();
    MinHeap heap4(data2); heap4.buildHeap();
    heap3.efficientMerge(heap4); // Merge heap4 into heap3 using efficient merge
    cout << "Merged Heap (Efficient Merge): "; heap3.printHeap();
    
    /*
        Problem 6: Heap Sort Testing
        Time complexity of O(n log n) as we repeatedly delete the minimum element n times, each deletion taking O(log n) and
        buildHeap() taking O(n) so overall that is O(n log n)
    */
    cout << "\nProblem 6: " << endl;
    vector<int> unsortedData(10);
    for (int i = 0; i < 10; i++) {
        unsortedData[i] = rand() % 100; // Random integers between 0 and 99
    }
    cout << "Unsorted Data: ";
    for (int val : unsortedData) cout << val << " "; cout << endl; // Print out the unsorted data

    // Used AI here with the prompt:"Why is there an error in line 104 of main.cpp and how can I resolve it?"
    MinHeap sorter(unsortedData);
    // Also used sidebar with prompt: "Can you help me understand where the errors in the function are coming from here?"
    sorter.buildHeap(); // Had to buildHeap() so that the deleteMin function would work properly, this was the main issue
    vector<int> sortedData = sorter.heapSort(); // Use heap sort function
    cout << "Sorted Data: ";
    for (int val : sortedData) cout << val << " "; cout << endl; // Print sorted data
}