#include <stdio.h>

// Function for Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Element found, return its position
        }
    }
    return -1;  // Element not found
}

// Function for Binary Search
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;  // Element found, return its position
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;  // Element not found
}

int main() {
    int n;

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Read the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;

    // Read the element to be searched
    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    // Perform Linear Search
    int linearResult = linearSearch(arr, n, key);

    if (linearResult != -1) {
        printf("Linear Search: Element found at position %d\n", linearResult + 1);
    } else {
        printf("Linear Search: Element not found\n");
    }

    // Perform Binary Search (Note: Binary search requires a sorted array)
    int sortedArr[n];
    for (int i = 0; i < n; i++) {
        sortedArr[i] = arr[i];
    }

    // Sort the array before performing binary search
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sortedArr[j] > sortedArr[j + 1]) {
                int temp = sortedArr[j];
                sortedArr[j] = sortedArr[j + 1];
                sortedArr[j + 1] = temp;
            }
        }
    }

    // Perform Binary Search
    int binaryResult = binarySearch(sortedArr, 0, n - 1, key);

    if (binaryResult != -1) {
        printf("Binary Search: Element found at position %d\n", binaryResult + 1);
    } else {
        printf("Binary Search: Element not found\n");
    }

    return 0;
}
