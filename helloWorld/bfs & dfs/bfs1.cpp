#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int x, y, dist;
};

int main()
{
    int R, C;
    cin >> R >> C;

    vector<string> grid(R);
    for (int i = 0; i < R; i++)
    {
        cin >> grid[i];
    }

    pair<int, int> start, end;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == 's')
                start = {i, j};
            if (grid[i][j] == 'e')
                end = {i, j};
        }
    }

    vector<vector<int>> visited(R, vector<int>(C, 0));
    queue<Node> q;

    q.push({start.first, start.second, 0});
    visited[start.first][start.second] = 1;

    // directions: up, down, left, right
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        if (cur.x == end.first && cur.y == end.second)
        {
            cout << "Minimum steps: " << cur.dist << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 0 && nx < R && ny >= 0 && ny < C &&
                grid[nx][ny] != '*' && !visited[nx][ny])
            {
                visited[nx][ny] = 1;
                q.push({nx, ny, cur.dist + 1});
            }
        }
    }

    cout << "No Path\n";
    return 0;
}
