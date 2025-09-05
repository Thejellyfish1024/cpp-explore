#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n >> q;
    vector<vector<char>> arr(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }

    for (int i = 0; i < q; i++)
    {

        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int tree = 0;
        for (int row = y1; row <= y2; row++)
        {
            for (int col = x1; col <= x2; col++)
            {
                if (arr[row][col] == '*')
                {
                    tree++;
                }
            }
        }
        cout << tree << endl;
    }

    return 0;
}
