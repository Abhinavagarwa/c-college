#include <iostream>
#include <vector>
#include <string>
#include <chrono> // Include for timing
using namespace std;

// Naive String Matching Algorithm
void naiveStringMatch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    cout << "Naive Matching:\n";
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}

// Rabin-Karp Algorithm
#define d 256 // Number of characters in the input alphabet
#define q 101 // A prime number for hashing

void rabinKarp(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    int h = 1; // The value of h would be "pow(d, m-1)%q"
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    cout << "Rabin-Karp Matching:\n";

    // Calculate the value of h (d^(m-1))
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++) {
        // Check if hash values match
        if (p == t) {
            // Check for characters one by one
            bool found = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    found = false;
                    break;
                }
            }
            if (found)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for the next window of text
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
}

// Knuth-Morris-Pratt (KMP) Algorithm
void computeLPSArray(const string& pattern, vector<int>& lps) {
    int m = pattern.size();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps(m, 0);
    cout << "KMP Matching:\n";

    // Preprocess the pattern (compute lps array)
    computeLPSArray(pattern, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

// Main function to test all three algorithms
int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    // Measure time for Naive String Matching
    auto start = chrono::high_resolution_clock::now();
    naiveStringMatch(text, pattern);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Naive String Matching took " << duration.count() << " seconds.\n";

    // Measure time for Rabin-Karp Algorithm
    start = chrono::high_resolution_clock::now();
    rabinKarp(text, pattern);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Rabin-Karp Algorithm took " << duration.count() << " seconds.\n";

    // Measure time for KMP Algorithm
    start = chrono::high_resolution_clock::now();
    kmpSearch(text, pattern);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "KMP Algorithm took " << duration.count() << " seconds.\n";

    return 0;
}
