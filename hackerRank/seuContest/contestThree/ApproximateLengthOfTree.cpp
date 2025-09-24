#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int dfs(int node)
{
    visited[node] = true;
    int maxDepth = 0;

    for (int child : adj[node])
    {
        if (!visited[child])
        {
            cout << "child = " << child << " ";
            maxDepth = max(maxDepth, dfs(child));
        }
    }

    return 1 + maxDepth; // 1 for current node
}

int main()
{
    int n;
    cin >> n; // number of nodes
    adj.resize(n + 1);
    visited.assign(n + 1, false);

    // taking n-1 edges for tree
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // root assumed as 1
    int height = dfs(1) - 1; // subtract 1 because height counts edges
    cout << height << endl;
}
