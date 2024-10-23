#include <iostream>
#include <vector>
#include <chrono> // Include for timing
using namespace std;

// Function to compare and swap elements
void compareAndSwap(int& a, int& b, bool order) {
    if ((a > b && order) || (a < b && !order)) {
        swap(a, b);
    }
}

// Function to perform the bitonic merge
void bitonicMerge(vector<int>& arr, int low, int count, bool order) {
    if (count > 1) {
        int k = count / 2;
        for (int i = low; i < low + k; i++) {
            compareAndSwap(arr[i], arr[i + k], order);
        }
        bitonicMerge(arr, low, k, order);
        bitonicMerge(arr, low + k, k, order);
    }
}

// Function to create a bitonic sequence and then sort it
void bitonicSort(vector<int>& arr, int low, int count, bool order) {
    if (count > 1) {
        int k = count / 2;

        // Sort in ascending order for the first half
        bitonicSort(arr, low, k, true);
        // Sort in descending order for the second half
        bitonicSort(arr, low + k, k, false);
        // Merge the whole sequence in the order specified
        bitonicMerge(arr, low, count, order);
    }
}

// Main function to initiate the bitonic sorting
void sortArray(vector<int>& arr) {
    bitonicSort(arr, 0, arr.size(), true);
}

int main() {
    vector<int> arr = { 12, 4, 7, 9, 2, 5, 8, 3 };

    cout << "Unsorted array:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Measure time for Bitonic Sort
    auto start = chrono::high_resolution_clock::now();
    
    sortArray(arr);
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Sorted array:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Bitonic Sort took " << duration.count() << " seconds.\n";

    return 0;
}
