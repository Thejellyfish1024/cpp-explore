// Input : 5
// Output :
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1

#include <iostream>
#include <math.h>
using namespace std;

int nCr(int n)
{
    if(n < 1) return 1;
    for (int i = n - 1; i >= 2; i--)
    {
        n *= i;
    }
    return n;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("../../../input.txt", "r", stdin);
//     freopen("../../../output.txt", "w", stdout);
// #endif

    int n, r, val;
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            val = nCr(i) / (nCr(j) * (nCr(i - j)));
            cout << val<<" ";
        }
        cout << endl;
    }

    return 0;
};