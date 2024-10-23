#include <iostream>
#include <vector>
using namespace std;

// A utility function to print the board
void printSolution(vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check this row on the left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check the lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// A recursive utility function to solve N Queen problem
bool solveNQueenUtil(vector<vector<int>>& board, int col, int N) {
    // Base case: If all queens are placed, return true
    if (col >= N)
        return true;

    // Consider this column and try placing queens in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col, N)) {
            // Place the queen at board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueenUtil(board, col + 1, N))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution
            // then remove the queen (backtrack)
            board[i][col] = 0;  // Backtrack
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

// This function solves the N Queen problem using Backtracking.
bool solveNQueen(int N) {
    // Initialize the board with all zeros
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueenUtil(board, 0, N) == false) {
        cout << "Solution does not exist." << endl;
        return false;
    }

    // Print the solution
    printSolution(board, N);
    return true;
}

int main() {
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;

    solveNQueen(N);

    return 0;
}
