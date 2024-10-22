#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <ctime> // For clock()

using namespace std;

// A structure to represent a node in the priority queue
typedef pair<int, int> iPair;

// Function to implement Dijkstra's Algorithm
void dijkstra(vector<vector<pair<int, int>>>& graph, int src, int V) {
    // Distance vector to store the shortest distance from source to each vertex
    vector<int> dist(V, INT_MAX);
    
    // Min-heap to store {distance, vertex} pairs
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    
    // Distance of the source vertex from itself is always 0
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        // Visit all the adjacent vertices of the dequeued vertex
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            // If there is a shorter path to v through u
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    // Output the shortest distance from the source to all vertices
    cout << "Vertex Distance from Source " << src << ":\n";
    for (int i = 0; i < V; ++i)
        cout << i << " \t\t " << dist[i] << "\n";
}

int main() {
    int V, E, src;
    
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V); // Adjacency list representation

    cout << "Enter edges (src, dest, weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Remove this if the graph is directed
    }

    cout << "Enter source vertex: ";
    cin >> src;

    // Measure time for Dijkstra's algorithm
    clock_t start = clock();
    dijkstra(graph, src, V);
    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken by Dijkstra's Algorithm: " << time_taken << " seconds.\n";

    return 0;
}
