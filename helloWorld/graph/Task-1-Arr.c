#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 26 // Maximum nodes (A-Z)
#define MAX_EDGES 10 // Maximum edges per node

// Structure for the graph
typedef struct Graph
{
    int numVertices;
    char adj[MAX_NODES][MAX_EDGES]; // Adjacency list using a 2D array
    int adjSize[MAX_NODES];         // Track number of neighbors for each node
    int exists[MAX_NODES];          // Tracks if a node exists (1 = exists, 0 = deleted)
} Graph;

// Function to create a graph
Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < MAX_NODES; i++)
    {
        graph->adjSize[i] = 0;
        graph->exists[i] = 0; // Initially, all nodes do not exist
    }
    return graph;
}

// Function to add an edge
void addEdge(Graph *graph, char src, char dest)
{
    int srcIndex = src - 'A';
    int destIndex = dest - 'A';

    // Mark the nodes as existing
    graph->exists[srcIndex] = 1;
    graph->exists[destIndex] = 1;

    // Add dest to src's adjacency list
    graph->adj[srcIndex][graph->adjSize[srcIndex]++] = dest;

    // Add src to dest's adjacency list (undirected graph)
    graph->adj[destIndex][graph->adjSize[destIndex]++] = src;
}

// Function to print the adjacency list
void printGraph(Graph *graph)
{
    for (int i = 0; i < MAX_NODES; i++)
    {
        if (graph->exists[i])
        { // Only print if node exists
            printf("%c -> ", i + 'A');
            for (int j = 0; j < graph->adjSize[i]; j++)
            {
                printf("%c ", graph->adj[i][j]);
            }
            printf("\n");
        }
    }
}

// Function to delete a node and its edges
void deleteNode(Graph *graph, char node)
{
    int nodeIndex = node - 'A';

    // Mark node as deleted
    graph->exists[nodeIndex] = 0;
    graph->adjSize[nodeIndex] = 0;

    // Remove occurrences of the node from other adjacency lists
    for (int i = 0; i < MAX_NODES; i++)
    {
        if (graph->exists[i])
        { // Process only existing nodes
            int newSize = 0;
            for (int j = 0; j < graph->adjSize[i]; j++)
            {
                if (graph->adj[i][j] != node)
                { // Keep only other nodes
                    graph->adj[i][newSize++] = graph->adj[i][j];
                }
            }
            graph->adjSize[i] = newSize; // Update size
        }
    }
}

int main()
{
    Graph *graph = createGraph(5); // Creating a graph with 5 vertices (A-E)

    addEdge(graph, 'A', 'B');
    addEdge(graph, 'A', 'C');
    addEdge(graph, 'A', 'D');
    addEdge(graph, 'B', 'D');
    addEdge(graph, 'B', 'E');
    addEdge(graph, 'C', 'D');
    addEdge(graph, 'D', 'E');

    printf("Adjacency List before deletion:\n");
    printGraph(graph);

    // Deleting node B
    deleteNode(graph, 'B');

    printf("\nAdjacency List after deletion:\n");
    printGraph(graph);

    free(graph);
    return 0;
}
