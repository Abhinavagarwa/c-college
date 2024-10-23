#include <iostream>
#include <vector>

using namespace std;

// Function to perform matrix multiplication
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();        // Number of rows in matrix A
    int m = A[0].size();     // Number of columns in matrix A (or rows in matrix B)
    int p = B[0].size();     // Number of columns in matrix B

    // Resultant matrix C will be of size n x p
    vector<vector<int>> C(n, vector<int>(p, 0));

    // Matrix multiplication
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

// Function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m, p;
    
    // Input dimensions for matrices
    cout << "Enter the number of rows for matrix A: ";
    cin >> n;
    cout << "Enter the number of columns for matrix A (and rows for matrix B): ";
    cin >> m;
    cout << "Enter the number of columns for matrix B: ";
    cin >> p;

    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> B(m, vector<int>(p));

    // Input matrix A
    cout << "Enter matrix A elements: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    // Input matrix B
    cout << "Enter matrix B elements: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cin >> B[i][j];
        }
    }

    // Multiply matrices
    vector<vector<int>> C = multiplyMatrices(A, B);

    // Output the result
    cout << "Resultant matrix C (A x B) is: " << endl;
    printMatrix(C);

    return 0;
}
