#include <iostream>
#include <ctime>  // For clock()

using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Swap if the element is greater than the next
            }
        }
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

    // Measure time taken by Bubble Sort
    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Display the time taken by Bubble Sort
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken by Bubble Sort: " << time_taken << " seconds." << endl;

    return 0;
}
