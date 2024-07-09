// Input : 5
// Output :
// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1
#include <iostream>
using namespace std;
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("../../../input.txt", "r", stdin);
//     freopen("../../../output.txt", "w", stdout);
// #endif

//     int n, val;
//     scanf("%d", &n);
//     val = n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= val; j++)
//         {
//             cout << j<<" ";
//         }
//         cout << endl;
//         val--;
//     }
// };

// second method with one loop

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif

    int n, col, val = 1;
    scanf("%d", &n);
    col = n;
    while (col > 0)
    {
        cout << val << " ";

        if (val == col)
        {
            cout << endl;
            val = 0;
            col--;
        }
        val++;
    }
};