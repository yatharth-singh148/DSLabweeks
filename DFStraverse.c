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

// Function for DFS traversal
void DFS(struct Graph* graph, int vertex, bool* visited) {
    visited[vertex] = true;
    printf("%d ", vertex);
    
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Function to check if the graph is connected
bool isConnected(struct Graph* graph) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    
    // Initialize visited array
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }
    
    // Perform DFS from the first vertex
    DFS(graph, 0, visited);
    
    // Check if all vertices are visited
    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }
    
    free(visited);
    return true;
}

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);
    
    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    
    // Check if the graph is connected
    if (isConnected(graph)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }
    
    return 0;
}
