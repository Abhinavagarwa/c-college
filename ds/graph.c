#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Node structure for an adjacency list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));

    // Initialize adjacency lists as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add an edge from dest to src (since the graph is undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to perform Depth-First Search (DFS)
void DFS(Graph* graph, int start, bool visited[]) {
    printf("%d ", start);
    visited[start] = true;

    // Traverse all adjacent vertices
    Node* current = graph->adjLists[start];
    while (current != NULL) {
        int neighbor = current->data;
        if (!visited[neighbor]) {
            DFS(graph, neighbor, visited);
        }
        current = current->next;
    }
}

// Function to perform Breadth-First Search (BFS)
void BFS(Graph* graph, int start, bool visited[]) {
    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    // Enqueue the start vertex and mark it as visited
    queue[++rear] = start;
    visited[start] = true;

    while (front != rear) {
        // Dequeue a vertex from the queue and print it
        int current = queue[++front];
        printf("%d ", current);

        // Enqueue all adjacent vertices of the dequeued vertex
        Node* temp = graph->adjLists[current];
        while (temp != NULL) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                queue[++rear] = neighbor;
                visited[neighbor] = true;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the starting vertex for traversal: ");
    int start;
    scanf("%d", &start);

    // Initialize an array to keep track of visited vertices
    bool visited[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
    }

    printf("DFS Traversal starting from vertex %d: ", start);
    DFS(graph, start, visited);
    printf("\n");

    // Reset visited array for BFS
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
    }

    printf("BFS Traversal starting from vertex %d: ", start);
    BFS(graph, start, visited);
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < vertices; i++) {
        Node* current = graph->adjLists[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}
