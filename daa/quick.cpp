#include <iostream>
#include <ctime>  // For clock()

using namespace std;

// Partition function to arrange elements around the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  // Swap if element is smaller than pivot
        }
    }
    swap(arr[i + 1], arr[high]);  // Place pivot in correct position
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition index
        quickSort(arr, low, pi - 1);         // Sort elements before partition
        quickSort(arr, pi + 1, high);        // Sort elements after partition
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Measure the time taken by quickSort
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\nTime taken: " << double(end - start) / CLOCKS_PER_SEC << " sec\n";

    return 0;
}
