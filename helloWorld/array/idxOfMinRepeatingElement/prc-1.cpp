#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 8, minIndex = 1e6;
    int arr[n] = {1, 5, 2, 3, 4, 3, 8, 2};
    int N = 1e6 + 2;
    int idx[N];

    for (int i = 0; i < N; i++)
    {
        idx[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (idx[arr[i]] == -1)
        {
            idx[arr[i]] = i;
        }
        else if (minIndex > idx[arr[i]])
        {
            minIndex = idx[arr[i]];
        }
    }
    cout << "index = " << minIndex;

    return 0;
}