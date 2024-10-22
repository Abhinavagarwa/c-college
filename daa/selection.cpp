#include <iostream>
#include <ctime>  // For clock()

using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        // Find the minimum element in the unsorted part of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Measure time taken by Selection Sort
    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Display the time taken by Selection Sort
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken by Selection Sort: " << time_taken << " seconds." << endl;

    return 0;
}
