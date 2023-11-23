#include <stdio.h>
#include<stdlib.h>
// Structure to represent a sparse matrix element
struct Element {
    int row;
    int col;
    int value;
};

// Structure to represent a sparse matrix
struct SparseMatrix {
    int numRows;
    int numCols;
    int numElements;
    struct Element *elements;
};

// Function to create a sparse matrix from a 2D array
void createSparseMatrix(int array[2][2], struct SparseMatrix *sparseMatrix) {
    int i, j;
    int count = 0;

    // Count the number of non-zero elements
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            if (array[i][j] != 0) {
                count++;
            }
        }
    }

    // Set sparse matrix properties
    sparseMatrix->numRows = 2;
    sparseMatrix->numCols = 2;
    sparseMatrix->numElements = count;

    // Allocate memory for elements
    sparseMatrix->elements = (struct Element *)malloc(count * sizeof(struct Element));

    // Fill the elements array with non-zero values and their positions
    int index = 0;
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            if (array[i][j] != 0) {
                sparseMatrix->elements[index].row = i;
                sparseMatrix->elements[index].col = j;
                sparseMatrix->elements[index].value = array[i][j];
                index++;
            }
        }
    }
}

// Function to print the sparse matrix
void printSparseMatrix(const struct SparseMatrix *sparseMatrix) {
    int i;

    printf("Sparse Matrix:\n");

    // Print the non-zero elements and their positions
    for (i = 0; i < sparseMatrix->numElements; ++i) {
        printf("%d %d %d\n", sparseMatrix->elements[i].row, sparseMatrix->elements[i].col, sparseMatrix->elements[i].value);
    }
}

int main() {
    int array[2][2];
    struct SparseMatrix sparseMatrix;

    // Read a 2D array from the user
    printf("Enter a 2x2 array:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%d", &array[i][j]);
        }
    }

    // Create a sparse matrix from the array
    createSparseMatrix(array, &sparseMatrix);

    // Print the sparse matrix
    printSparseMatrix(&sparseMatrix);

    // Free allocated memory
    free(sparseMatrix.elements);

    return 0;
}
