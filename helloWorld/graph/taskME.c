#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Node
{
    char vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node *adjLists[MAX];
} Graph;

// Function to create a node with the given vertex and next pointer
Node *createNode(char vertex, Node *next)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = next;
    return newNode;
}

// Function to create an empty graph with the given number of vertices
Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < MAX; i++)
    {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge between two vertices (undirected graph)
void addEdge(Graph *graph, char source, char destination)
{
    Node *newNode = createNode(destination, graph->adjLists[source - 'A']);
    graph->adjLists[source - 'A'] = newNode;

    newNode = createNode(source, graph->adjLists[destination - 'A']);
    graph->adjLists[destination - 'A'] = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(Graph *graph)
{
    printf("Adjacency List:\n");
    for (int i = 0; i < MAX; i++)
    {
        if (graph->adjLists[i] != NULL)
        {
            printf("%c -> ", i + 'A');
            Node *temp = graph->adjLists[i];
            while (temp)
            {
                printf("%c ", temp->vertex);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

// Function to print the memory structure of the graph
void printMemoryStructure(Graph *graph)
{
    printf("\nMemory Structure:\n");
    for (int i = 0; i < MAX; i++)
    {
        if (graph->adjLists[i] != NULL)
        {
            printf("%c (Head: %p) -> ", i + 'A', graph->adjLists[i]);
            Node *temp = graph->adjLists[i];
            while (temp)
            {
                printf("[%c = %p] -> ", temp->vertex, temp);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}

// Function to delete a node and its associated edges from the graph
void deleteNode(Graph *graph, char delVertex)
{
    int index = delVertex - 'A';

    for (int i = 0; i < MAX; i++)
    {
        if (graph->adjLists[i] != NULL)
        {
            Node *temp = graph->adjLists[i];
            Node *prev = NULL;

            while (temp != NULL)
            {
                if (temp->vertex == delVertex)
                {
                    if (prev == NULL)
                        graph->adjLists[i] = temp->next;
                    else
                        prev->next = temp->next;

                    free(temp);
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }
    }

    Node *temp = graph->adjLists[index];
    while (temp)
    {
        Node *toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    graph->adjLists[index] = NULL;
}

// Function to initialize the graph with the given memory structure
void initializeGraphFromMemory(Graph *graph)
{
    // Assuming the memory structure is given in a similar format as in the image
    // You'll need to adapt this part based on the actual memory structure format
    // Here's a simplified example:

    graph->adjLists['A' - 'A'] = createNode('B', createNode('C', createNode('D', NULL)));
    graph->adjLists['B' - 'A'] = createNode('A', createNode('D', createNode('E', NULL)));
    graph->adjLists['C' - 'A'] = createNode('A', createNode('D', NULL));
    graph->adjLists['D' - 'A'] = createNode('A', createNode('B', createNode('C', createNode('E', NULL))));
    graph->adjLists['E' - 'A'] = createNode('B', createNode('D', NULL));
}

int main()
{
    Graph *graph = createGraph(5);

    // Initialize the graph with the given memory structure
    initializeGraphFromMemory(graph);

    printf("\n\nGraph G before deletion:\n\n");
    printGraph(graph);
    printMemoryStructure(graph);

    deleteNode(graph, 'B');

    printf("\nGraph G after deleting B:\n\n");
    printGraph(graph);
    printMemoryStructure(graph);

    return 0;
}