#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// A structure to represent a weighted edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to run the Bellman-Ford algorithm
void bellmanFord(int V, int E, vector<Edge>& edges, int source) {
    // Step 1: Initialize distances from source to all vertices as infinity (INT_MAX)
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // Step 2: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }

    // Print the results
    cout << "Vertex distances from source " << source << ":" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << "Vertex " << i << ": Infinity" << endl;
        else
            cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int V, E, source;
    
    // Input number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> V;
    
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);
    
    // Input edges
    cout << "Enter edges (source, destination, weight): " << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    // Input source vertex
    cout << "Enter source vertex: ";
    cin >> source;

    // Call the Bellman-Ford algorithm
    bellmanFord(V, E, edges, source);

    return 0;
}

