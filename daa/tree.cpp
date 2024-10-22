#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the vertex with the minimum key value, that is not yet included in the MST
int minKey(vector<int>& key, vector<bool>& mstSet, int V) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    return minIndex;
}

// Function to implement Prim's Algorithm
void primMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V);    // Stores MST
    vector<int> key(V, INT_MAX);  // Key values used to pick minimum weight edge
    vector<bool> mstSet(V, false);  // To represent set of vertices included in MST

    // Always include the first vertex in MST
    key[0] = 0;     // Make key 0 so that this vertex is picked first
    parent[0] = -1; // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);  // Pick the minimum key vertex not in MST
        mstSet[u] = true;                // Add the picked vertex to the MST set

        // Update the key value and parent index of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    cout << "Edges in the MST (Prim's):\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " -- " << i << " == " << graph[i][parent[i]] << endl;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    primMST(graph, V);
    return 0;
}
