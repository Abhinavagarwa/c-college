#include <iostream>
#include <ctime>  // For clock()

using namespace std;

// Function to perform Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Return index of target
        }
    }
    return -1;  // Return -1 if target is not found
}

// Function to perform Binary Search (Iterative)
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    return -1;  // Return -1 if target is not found
}

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements (for binary search, make sure they're sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> target;

    // Measure time taken by Linear Search
    clock_t start_ls = clock();
    int result_ls = linearSearch(arr, n, target);
    clock_t end_ls = clock();

    if (result_ls != -1)
        cout << "Linear Search: Element found at index " << result_ls << endl;
    else
        cout << "Linear Search: Element not found" << endl;

    // Time taken by Linear Search
    double time_ls = double(end_ls - start_ls) / CLOCKS_PER_SEC;
    cout << "Time taken by Linear Search: " << time_ls << " seconds." << endl;

    // Measure time taken by Binary Search
    clock_t start_bs = clock();
    int result_bs = binarySearch(arr, n, target);
    clock_t end_bs = clock();

    if (result_bs != -1)
        cout << "Binary Search: Element found at index " << result_bs << endl;
    else
        cout << "Binary Search: Element not found" << endl;

    // Time taken by Binary Search
    double time_bs = double(end_bs - start_bs) / CLOCKS_PER_SEC;
    cout << "Time taken by Binary Search: " << time_bs << " seconds." << endl;

    return 0;
}
