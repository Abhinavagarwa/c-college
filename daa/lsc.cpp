#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to find the length of the longest common subsequence
int longestCommonSubsequence(const string& X, const string& Y) {
    int m = X.size();
    int n = Y.size();
    
    // Create a DP table to store the lengths of LCS for substrings
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The length of LCS is in the bottom-right cell of the table
    return dp[m][n];
}

// Function to print the longest common subsequence
string printLCS(const string& X, const string& Y) {
    int m = X.size();
    int n = Y.size();

    // Create the DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table as before
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to find the actual LCS
    int i = m, j = n;
    string lcs = "";

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs; // Add character to LCS
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string X, Y;
    
    // Input two strings
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    // Find the length of the longest common subsequence
    int lcsLength = longestCommonSubsequence(X, Y);
    cout << "Length of LCS: " << lcsLength << endl;

    // Print the actual LCS
    string lcs = printLCS(X, Y);
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
