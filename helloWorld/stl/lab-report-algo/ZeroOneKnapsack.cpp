#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    int value[n + 1], weight[n + 1];
    cout << "Enter value and weight of each item:\n";
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i] >> weight[i];
    }

    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    int k[n + 1][W + 1];

    // Build DP table
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if (weight[i] <= w)
                k[i][w] = max(k[i - 1][w], k[i - 1][w - weight[i]] + value[i]);
            else
                k[i][w] = k[i - 1][w];
        }
    }

    cout << "Max profit (0/1 Knapsack): " << k[n][W] << endl;
    return 0;
}
