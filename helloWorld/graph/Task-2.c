#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int path[MAX];
int pathIndex;

bool isComplete(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && graph[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool dfs(int u, int v, int n)
{
    visited[u] = 1;
    path[pathIndex++] = u;

    if (u == v)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (graph[u][i] && !visited[i])
        {
            if (dfs(i, v, n))
                return true;
        }
    }
    pathIndex--;
    return false;
}

void findPath(int u, int v, int n)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    pathIndex = 0;

    if (dfs(u, v, n))
    {
        printf("Path from %d to %d: ", u, v);
        for (int i = 0; i < pathIndex; i++)
            printf("%d ", path[i]);
        printf("\n");
    }
    else
    {
        printf("No path exists between %d and %d.\n", u, v);
    }
}

void findDegree(int u, int n, bool directed)
{
    int inDegree = 0, outDegree = 0;

    for (int i = 0; i < n; i++)
    {
        if (graph[u][i])
            outDegree++;
        if (graph[i][u])
            inDegree++;
    }

    if (directed)
    {
        printf("In-degree of %d: %d\n", u, inDegree);
        printf("Out-degree of %d: %d\n", u, outDegree);
    }
    else
    {
        printf("Degree of %d: %d\n", u, outDegree);
    }
}

int main()
{
    int n, u, v, choice;
    bool directed;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &directed);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    while (1)
    {
        printf("\nMENU:\n1. Check if graph is complete\n2. Find path\n3. Find degree/in-degree/out-degree\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            if (isComplete(n))
                printf("Graph is complete.\n");
            else
                printf("Graph is not complete.\n");
            break;
        case 2:
            printf("Enter source and destination (0-%d): ", n - 1);
            scanf("%d %d", &u, &v);
            findPath(u, v, n);
            break;
        case 3:
            printf("Enter node (0-%d): ", n - 1);
            scanf("%d", &u);
            findDegree(u, n, directed);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
