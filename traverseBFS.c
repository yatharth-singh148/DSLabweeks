#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a graph
struct Graph {
    int vertices;
    int** adjMatrix;
};

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    
    // Allocate memory for adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
    }
    
    // Initialize adjacency matrix with zeros
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    
    return graph;
}

// Function to add an edge in an undirected graph
void addEdge(struct Graph* graph, int u, int v) {
    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1;
}

// Function to perform BFS traversal of the graph
void BFS(struct Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }
    
    // Create a queue for BFS
    int queue[graph->vertices];
    int front = -1, rear = -1;
    
    // Enqueue the start vertex
    queue[++rear] = startVertex;
    visited[startVertex] = true;
    
    while (front != rear) {
        // Dequeue a vertex from queue
        int vertex = queue[++front];
        printf("%d ", vertex);
        
        // Enqueue all adjacent vertices of the dequeued vertex
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
    
    free(visited);
}

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);
    
    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    
    printf("BFS Traversal starting from vertex 0: ");
    BFS(graph, 0);  // Perform BFS starting from vertex 0
    
    return 0;
}
