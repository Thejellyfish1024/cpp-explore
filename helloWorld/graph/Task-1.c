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

Node *createNode(char vertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

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

void addEdge(Graph *graph, char source, char destination)
{
    Node *newNode = createNode(destination);
    newNode->next = graph->adjLists[source - 'A'];
    graph->adjLists[source - 'A'] = newNode;
    newNode = createNode(source);
    newNode->next = graph->adjLists[destination - 'A'];
    graph->adjLists[destination - 'A'] = newNode;
}

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

int main()
{
    Graph *graph = createGraph(5);
    addEdge(graph, 'A', 'B');
    addEdge(graph, 'A', 'C');
    addEdge(graph, 'A', 'D');
    addEdge(graph, 'B', 'D');
    addEdge(graph, 'B', 'E');
    addEdge(graph, 'C', 'D');
    addEdge(graph, 'D', 'E');

    printf("\n\nGraph G before deletion:\n\n");
    printGraph(graph);
    printMemoryStructure(graph);
    deleteNode(graph, 'B');

    printf("\nGraph G after deleting B:\n\n");
    printGraph(graph);
    printMemoryStructure(graph);

    return 0;
}
